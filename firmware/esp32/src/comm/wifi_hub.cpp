#include "comm/wifi_hub.h"
#include <Arduino.h>

namespace aqua_atmos::comm {

const char* WEB_PAGE = R"rawliteral(
<!DOCTYPE html><html><head>
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>AquaAtmos Dashboard</title>
<style>
  body { font-family: Arial; text-align: center; background: #1a1a1a; color: #eee; }
  .card { background: #333; padding: 20px; margin: 10px; border-radius: 10px; }
  .val { font-size: 2em; color: #00d1b2; }
  .grid { display: grid; grid-template-columns: repeat(auto-fit, minmax(150px, 1fr)); }
  .state-on { color: #48c774; } .state-off { color: #f14668; }
</style>
<script>
  setInterval(function() {
    fetch('/api/data').then(r => r.json()).then(d => {
      document.getElementById('t').innerText = d.temp.toFixed(1) + 'C';
      document.getElementById('h').innerText = d.hum.toFixed(0) + '%';
      document.getElementById('v').innerText = d.vcrc ? 'ACTIF' : 'OFF';
      document.getElementById('s').innerText = d.sorb;
      document.getElementById('b').innerText = d.bat.toFixed(0) + '%';
    });
  }, 2000);
</script>
</head><body>
  <h1>AQUA-ATMOS</h1>
  <div class="grid">
    <div class="card"><h3>Air</h3><div id="t" class="val">--</div></div>
    <div class="card"><h3>Hum</h3><div id="h" class="val">--</div></div>
    <div class="card"><h3>Batterie</h3><div id="b" class="val">--</div></div>
  </div>
  <div class="card">
    <h3>Etat Systeme</h3>
    <p>VCRC: <span id="v" class="val">--</span></p>
    <p>Sorbant: <span id="s" class="val">--</span></p>
  </div>
</body></html>
)rawliteral";

void WifiHub::begin() {
  WiFi.softAP("AquaAtmos");
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Access Point actif : "); Serial.println(IP);

  // Portail captif : toutes les requêtes DNS vont vers l'ESP32
  dns_server_.start(53, "*", IP);

  setup_routing();
  server_.begin();
}

void WifiHub::setup_routing() {
  server_.on("/", [this]() { handle_root(); });
  server_.on("/esp", [this]() { handle_esp_local(); });

  // Captive portal probes: Android, iOS/macOS, Windows.
  server_.on("/generate_204", [this]() { handle_root(); });
  server_.on("/gen_204", [this]() { handle_root(); });
  server_.on("/hotspot-detect.html", [this]() { handle_root(); });
  server_.on("/library/test/success.html", [this]() { handle_root(); });
  server_.on("/connecttest.txt", [this]() { handle_root(); });
  server_.on("/redirect", [this]() { handle_root(); });
  server_.on("/ncsi.txt", [this]() { handle_root(); });
  server_.on("/fwlink", [this]() { handle_root(); });

  server_.on("/api/data", [this]() {
    server_.send(200, "application/json", get_json_data(last_sensors_, last_derived_, last_vcrc_, last_sorbent_));
  });
  server_.on("/api/command", HTTP_POST, [this]() { handle_command(); });
  server_.on("/api/inject", HTTP_POST, [this]() { handle_inject(); });
  server_.onNotFound([this]() { handle_not_found(); });
}

void WifiHub::handle(const domain::SensorFrame& sensors, const domain::DerivedFrame& derived, const domain::VcrcDecision& vcrc, const domain::SorbentDecision& sorbent) {
  last_sensors_ = sensors;
  last_derived_ = derived;
  last_vcrc_    = vcrc;
  last_sorbent_ = sorbent;

  dns_server_.processNextRequest();
  server_.handleClient();
}

void WifiHub::handle_root() {
  // Redirection par script HTML/JS compatible portails captifs mobiles
  String html = "<html><head><meta http-equiv=\"refresh\" content=\"0; url=http://192.168.4.2:5000/\" />"
                "<script>window.location.href = \"http://192.168.4.2:5000/\";</script></head>"
                "<body style=\"font-family:sans-serif; text-align:center; padding-top:50px; background:#121212; color:#eee;\">"
                "<h2>Connexion AquaAtmos...</h2>"
                "<p>Redirection vers le Dashboard...</p>"
                "<a href=\"http://192.168.4.2:5000/\" style=\"color:#ff8c00; font-weight:bold; font-size:1.2em; text-decoration:none;\">Cliquez ici si la redirection ne fonctionne pas</a>"
                "</body></html>";
  server_.send(200, "text/html", html);
}

void WifiHub::handle_esp_local() {
  // Page web locale d'origine pour le diagnostic direct
  server_.send(200, "text/html", WEB_PAGE);
}

void WifiHub::handle_not_found() {
  handle_root();
}


void WifiHub::handle_command() {
  String body = server_.arg("plain");
  String cmd   = server_.arg("cmd");
  String value = server_.arg("value");

  if (cmd == "vcrc_override" || cmd == "vcrc") {
    overrides_.vcrc_enabled = true;
    overrides_.vcrc_value   = (value == "true" || value == "1");
  } else if (cmd == "vcrc_auto") {
    overrides_.vcrc_enabled = false;
  } else if (cmd == "sorb_mode") {
    overrides_.sorb_enabled = true;
    if (value == "ABSORPTION")    overrides_.sorb_value = domain::SorbentDecision::Mode::Absorption;
    else if (value == "REGEN")    overrides_.sorb_value = domain::SorbentDecision::Mode::Regeneration;
    else                          overrides_.sorb_value = domain::SorbentDecision::Mode::Veille;
  } else if (cmd == "sorb_auto") {
    overrides_.sorb_enabled = false;
  } else if (cmd == "heater") {
    overrides_.heater_enabled = true;
    overrides_.heater_value   = (value == "true" || value == "1");
  } else if (cmd == "heater_auto") {
    overrides_.heater_enabled = false;
  } else if (cmd == "reset") {
    server_.send(200, "application/json", "{\"ok\":true}");
    delay(200);
    ESP.restart();
    return;
  }

  server_.send(200, "application/json", "{\"ok\":true}");
}

void WifiHub::handle_inject() {
  String active_str = server_.arg("active");
  if (active_str == "false" || active_str == "0") {
    mock_sensors_.active = false;
  } else {
    mock_sensors_.active = true;
    overrides_.vcrc_enabled   = false;
    overrides_.sorb_enabled   = false;
    overrides_.heater_enabled = false;
    if (server_.hasArg("temp")) mock_sensors_.temp_air_c = server_.arg("temp").toFloat();
    if (server_.hasArg("hum"))  mock_sensors_.hr_pct = server_.arg("hum").toFloat();
    if (server_.hasArg("bat"))  mock_sensors_.soc_battery_pct = server_.arg("bat").toFloat();
    if (server_.hasArg("res"))  mock_sensors_.reservoir_level_pct = server_.arg("res").toFloat();
    if (server_.hasArg("cond")) mock_sensors_.temp_cond_c = server_.arg("cond").toFloat();
    if (server_.hasArg("sol"))  mock_sensors_.solar_wm2 = server_.arg("sol").toFloat();
    if (server_.hasArg("delta_hr")) mock_sensors_.delta_hr_sorbent = server_.arg("delta_hr").toFloat();
    if (server_.hasArg("vcrc")) {
      overrides_.vcrc_enabled = true;
      String vcrc = server_.arg("vcrc");
      overrides_.vcrc_value = (vcrc == "true" || vcrc == "1");
    }
    if (server_.hasArg("sorb")) {
      overrides_.sorb_enabled = true;
      String sorb = server_.arg("sorb");
      if (sorb == "ABSORPTION")      overrides_.sorb_value = domain::SorbentDecision::Mode::Absorption;
      else if (sorb == "REGEN")      overrides_.sorb_value = domain::SorbentDecision::Mode::Regeneration;
      else                           overrides_.sorb_value = domain::SorbentDecision::Mode::Veille;
    }
    if (server_.hasArg("heater")) {
      overrides_.heater_enabled = true;
      String heater = server_.arg("heater");
      overrides_.heater_value = (heater == "true" || heater == "1");
    }
  }
  server_.send(200, "application/json", "{\"ok\":true}");
}

String WifiHub::get_json_data(const domain::SensorFrame& s, const domain::DerivedFrame& d, const domain::VcrcDecision& v, const domain::SorbentDecision& sb) {
  const char* sorb_str =
    (sb.mode == domain::SorbentDecision::Mode::Absorption)   ? "ABSORPTION" :
    (sb.mode == domain::SorbentDecision::Mode::Regeneration) ? "REGEN" : "VEILLE";

  char buf[320];
  snprintf(buf, sizeof(buf),
    "{\"temp\":%.1f,\"hum\":%.1f,\"bat\":%.0f,\"res\":%.0f,\"flow\":%.2f,\"dew\":%.1f,"
    "\"vcrc\":%s,\"sorb\":\"%s\",\"heater\":%s,\"hour\":%d}",
    s.temp_air_c, s.hr_pct, s.soc_battery_pct, s.reservoir_level_pct,
    s.water_flow_ml_min / 1000.0f, d.dew_point_c,
    v.state ? "true" : "false", sorb_str, sb.heater_on ? "true" : "false", s.hour_of_day);
  return String(buf);
}

}

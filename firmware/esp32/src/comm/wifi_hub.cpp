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
  WiFi.softAP("AquaAtmos-V1");
  IPAddress IP = WiFi.softAPIP();
  Serial.print("Access Point actif : "); Serial.println(IP);

  // Portail captif : toutes les requêtes DNS vont vers l'ESP32
  dns_server_.start(53, "*", IP);

  setup_routing();
  server_.begin();
}

void WifiHub::setup_routing() {
  server_.on("/", [this]() { handle_root(); });
  server_.on("/generate_204", [this]() { handle_root(); }); // Android captive portal
  server_.onNotFound([this]() { handle_not_found(); });
}

void WifiHub::handle(const domain::SensorFrame& sensors, const domain::VcrcDecision& vcrc, const domain::SorbentDecision& sorbent) {
  dns_server_.processNextRequest();
  server_.handleClient();

  // API Endpoint (JSON)
  server_.on("/api/data", [this, sensors, vcrc, sorbent]() {
    server_.send(200, "application/json", get_json_data(sensors, vcrc, sorbent));
  });
}

void WifiHub::handle_root() {
  server_.send(200, "text/html", WEB_PAGE);
}

void WifiHub::handle_not_found() {
  // Redirection automatique pour le portail captif
  server_.sendHeader("Location", "/", true);
  server_.send(302, "text/plain", "");
}

String WifiHub::get_json_data(const domain::SensorFrame& s, const domain::VcrcDecision& v, const domain::SorbentDecision& sb) {
  String json = "{";
  json += "\"temp\":" + String(s.temp_air_c) + ",";
  json += "\"hum\":" + String(s.hr_pct) + ",";
  json += "\"bat\":" + String(s.soc_battery_pct) + ",";
  json += "\"vcrc\":" + String(v.state ? "true" : "false") + ",";
  json += "\"sorb\":\"";
  if (sb.mode == domain::SorbentDecision::Mode::Absorption) json += "ABSORPTION";
  else if (sb.mode == domain::SorbentDecision::Mode::Regeneration) json += "REGEN";
  else json += "VEILLE";
  json += "\"}";
  return json;
}

}

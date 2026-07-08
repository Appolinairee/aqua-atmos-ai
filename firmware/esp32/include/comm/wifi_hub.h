#pragma once

#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include "domain/types.h"

namespace aqua_atmos::comm {

struct MockSensorState {
  bool active = false;
  float temp_air_c = 25.0f;
  float hr_pct = 60.0f;
  float soc_battery_pct = 80.0f;
  float reservoir_level_pct = 30.0f;
  float temp_cond_c = 25.0f;
  float solar_wm2 = 0.0f;
  float delta_hr_sorbent = 5.0f;
};

class WifiHub {
 public:
  void begin();
  void handle(const domain::SensorFrame& sensors,
              const domain::DerivedFrame& derived,
              const domain::VcrcDecision& vcrc,
              const domain::SorbentDecision& sorbent);

  const domain::OverrideState& overrides() const { return overrides_; }
  const MockSensorState& mock_sensors() const { return mock_sensors_; }

 private:
  WebServer server_{80};
  DNSServer dns_server_;

  domain::SensorFrame     last_sensors_{};
  domain::DerivedFrame    last_derived_{};
  domain::VcrcDecision    last_vcrc_{};
  domain::SorbentDecision last_sorbent_{};
  domain::OverrideState  overrides_{};
  MockSensorState        mock_sensors_{};

  void setup_routing();
  void handle_root();
  void handle_esp_local();
  void handle_not_found();
  void handle_command();
  void handle_inject();

  String get_json_data(const domain::SensorFrame& s,
                       const domain::DerivedFrame& d,
                       const domain::VcrcDecision& v,
                       const domain::SorbentDecision& sb);
};

}

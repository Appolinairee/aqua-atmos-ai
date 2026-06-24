#pragma once

#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include "domain/types.h"

namespace aqua_atmos::comm {

class WifiHub {
 public:
  void begin();
  void handle(const domain::SensorFrame& sensors,
              const domain::DerivedFrame& derived,
              const domain::VcrcDecision& vcrc,
              const domain::SorbentDecision& sorbent);

  const domain::OverrideState& overrides() const { return overrides_; }

 private:
  WebServer server_{80};
  DNSServer dns_server_;

  domain::SensorFrame     last_sensors_{};
  domain::DerivedFrame    last_derived_{};
  domain::VcrcDecision    last_vcrc_{};
  domain::SorbentDecision last_sorbent_{};
  domain::OverrideState  overrides_{};

  void setup_routing();
  void handle_root();
  void handle_not_found();
  void handle_command();

  String get_json_data(const domain::SensorFrame& s,
                       const domain::DerivedFrame& d,
                       const domain::VcrcDecision& v,
                       const domain::SorbentDecision& sb);
};

}

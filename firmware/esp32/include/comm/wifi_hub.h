#pragma once

#include <WiFi.h>
#include <WebServer.h>
#include <DNSServer.h>
#include "domain/types.h"

namespace aqua_atmos::comm {

class WifiHub {
 public:
  void begin();
  
  /**
   * @brief Gère les requêtes web et le portail captif. À appeler dans la loop.
   */
  void handle(const domain::SensorFrame& sensors, 
              const domain::VcrcDecision& vcrc, 
              const domain::SorbentDecision& sorbent);

 private:
  WebServer server_{80};
  DNSServer dns_server_;
  
  void setup_routing();
  void handle_root();
  void handle_not_found();
  
  // Cache des données pour l'API
  String get_json_data(const domain::SensorFrame& s, 
                       const domain::VcrcDecision& v, 
                       const domain::SorbentDecision& sb);
};

}

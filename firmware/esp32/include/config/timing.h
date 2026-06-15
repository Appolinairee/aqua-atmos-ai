#pragma once

namespace aqua_atmos::config {

// Délais de protection (en millisecondes)
constexpr unsigned long VCRC_MIN_OFF_MS = 300000UL;  // 5 minutes de repos obligatoire
constexpr unsigned long VCRC_MIN_RUN_MS = 1200000UL; // 20 minutes de marche minimale (MRT)

constexpr unsigned long HEATER_MIN_OFF_MS = 60000UL; // 1 minute pour la résistance

}

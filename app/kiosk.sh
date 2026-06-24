#!/bin/bash
# Lance Chromium en plein écran sur le dashboard
# À ajouter dans /etc/xdg/lxsession/LXDE-pi/autostart

sleep 5  # attendre que le serveur Flask démarre

chromium-browser \
  --kiosk \
  --noerrdialogs \
  --disable-infobars \
  --disable-session-crashed-bubble \
  --check-for-update-interval=31536000 \
  http://localhost:5000

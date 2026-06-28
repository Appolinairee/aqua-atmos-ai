#!/usr/bin/env bash
set -Eeuo pipefail

APP_NAME="aqua-atmos"
APP_USER="${APP_USER:-pi}"
REPO_DIR="${REPO_DIR:-/home/pi/aqua-atmos-ai}"
APP_DIR="$REPO_DIR/app"
VENV_DIR="$REPO_DIR/.venv"
SERVICE_FILE="/etc/systemd/system/${APP_NAME}.service"
DASHBOARD_URL="http://localhost:5000"
ESP32_SSID="${ESP32_SSID:-AquaAtmos}"
PI_WIFI_IP="${PI_WIFI_IP:-192.168.4.2/24}"
ESP32_GATEWAY="${ESP32_GATEWAY:-192.168.4.1}"

log() {
  printf '\n[%s] %s\n' "$APP_NAME" "$1"
}

need_root() {
  if [[ "${EUID:-$(id -u)}" -ne 0 ]]; then
    echo "Relance avec sudo: sudo bash scripts/setup_raspberry_pi.sh"
    exit 1
  fi
}

check_repo() {
  if [[ ! -f "$APP_DIR/main.py" ]]; then
    echo "Repo introuvable: $APP_DIR/main.py"
    echo "Definis REPO_DIR si besoin, ex: REPO_DIR=/home/pi/aqua-atmos-ai sudo -E bash scripts/setup_raspberry_pi.sh"
    exit 1
  fi
}

install_packages() {
  log "Installation des paquets systeme"
  apt-get update
  apt-get install -y python3 python3-venv python3-pip chromium-browser
}

setup_python() {
  log "Preparation de l'environnement Python"
  sudo -u "$APP_USER" python3 -m venv "$VENV_DIR"
  sudo -u "$APP_USER" "$VENV_DIR/bin/python" -m pip install --upgrade pip
  sudo -u "$APP_USER" "$VENV_DIR/bin/pip" install -r "$APP_DIR/requirements.txt"
  install -d -o "$APP_USER" -g "$APP_USER" "$APP_DIR/data"
}

install_service() {
  log "Installation du service systemd"
  cat > "$SERVICE_FILE" <<SERVICE
[Unit]
Description=Aqua Atmos Dashboard
After=network-online.target
Wants=network-online.target

[Service]
Type=simple
User=$APP_USER
WorkingDirectory=$APP_DIR
Environment=PYTHONUNBUFFERED=1
ExecStart=$VENV_DIR/bin/python main.py
Restart=always
RestartSec=5

[Install]
WantedBy=multi-user.target
SERVICE

  systemctl daemon-reload
  systemctl enable "$APP_NAME"
  systemctl restart "$APP_NAME"
}

setup_static_ip() {
  log "Configuration IP statique WiFi ESP32"
  if command -v nmcli >/dev/null 2>&1; then
    if ! nmcli connection show "$ESP32_SSID" >/dev/null 2>&1; then
      nmcli connection add type wifi con-name "$ESP32_SSID" ssid "$ESP32_SSID"
    fi
    nmcli connection modify "$ESP32_SSID" \
      ipv4.addresses "$PI_WIFI_IP" \
      ipv4.gateway "$ESP32_GATEWAY" \
      ipv4.dns "$ESP32_GATEWAY" \
      ipv4.method manual
    nmcli connection up "$ESP32_SSID" || true
    return
  fi

  if [[ -f /etc/dhcpcd.conf ]]; then
    if ! grep -q "ssid $ESP32_SSID" /etc/dhcpcd.conf; then
      cat >> /etc/dhcpcd.conf <<WIFI

interface wlan0
ssid $ESP32_SSID
static ip_address=$PI_WIFI_IP
static routers=$ESP32_GATEWAY
static domain_name_servers=$ESP32_GATEWAY
WIFI
    fi
    systemctl restart dhcpcd || true
  fi
}

print_summary() {
  log "Termine"
  echo "Dashboard: $DASHBOARD_URL"
  echo "Statut:    systemctl status $APP_NAME --no-pager"
  echo "Logs:      journalctl -u $APP_NAME -f"
  echo "Restart:   sudo systemctl restart $APP_NAME"
  echo "Kiosk:     chromium-browser --kiosk --noerrdialogs --disable-infobars $DASHBOARD_URL"
}

main() {
  need_root
  check_repo
  install_packages
  setup_python
  install_service
  setup_static_ip
  print_summary
}

main "$@"

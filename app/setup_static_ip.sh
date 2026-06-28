#!/bin/bash
# Script de configuration d'IP statique (192.168.4.2) sur le Raspberry Pi pour le WiFi AquaAtmos-V1

SSID="AquaAtmos-V1"
IP="192.168.4.2/24"
GATEWAY="192.168.4.1"

echo "[AQUA-ATMOS] Configuration de l'IP statique pour le WiFi : $SSID..."

if command -v nmcli >/dev/null 2>&1; then
    echo "-> Détection de NetworkManager (nmcli)..."
    # Créer le profil s'il n'existe pas
    if ! nmcli connection show "$SSID" >/dev/null 2>&1; then
        echo "-> Création du profil de connexion WiFi..."
        sudo nmcli connection add type wifi con-name "$SSID" ssid "$SSID"
    fi
    # Configurer l'IP fixe
    sudo nmcli connection modify "$SSID" \
        ipv4.addresses "$IP" \
        ipv4.gateway "$GATEWAY" \
        ipv4.dns "$GATEWAY" \
        ipv4.method manual
    sudo nmcli connection up "$SSID"
    echo "[OK] IP statique configurée avec succès via NetworkManager."
else
    echo "-> Détection de dhcpcd (/etc/dhcpcd.conf)..."
    CONFIG_BLOCK="
interface wlan0
ssid $SSID
static ip_address=$IP
static routers=$GATEWAY
static domain_name_servers=$GATEWAY
"
    if grep -q "ssid $SSID" /etc/dhcpcd.conf; then
        echo "-> Le profil WiFi $SSID est déjà présent dans /etc/dhcpcd.conf."
    else
        echo "$CONFIG_BLOCK" | sudo tee -a /etc/dhcpcd.conf >/dev/null
        sudo systemctl restart dhcpcd
        echo "[OK] IP statique ajoutée avec succès à /etc/dhcpcd.conf."
    fi
fi

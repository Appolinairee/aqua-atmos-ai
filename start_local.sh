#!/bin/bash
# Script de lancement local pour AQUA-ATMOS (sans matériel ESP32 réel)

echo "=== Démarrage de AQUA-ATMOS en local ==="

# 1. Lancement du simulateur ESP32 (Mock) en arrière-plan
echo "[1/2] Lancement du simulateur ESP32 sur http://localhost:8080..."
python3 app/mock_esp32.py &
MOCK_PID=$!

# S'assurer que le mock s'arrête quand on ferme le script
trap "kill $MOCK_PID; exit" INT TERM EXIT

# Attendre un court instant que le simulateur démarre
sleep 1

# 2. Lancement du dashboard Flask en local branché sur le simulateur
echo "[2/2] Lancement du tableau de bord sur http://localhost:5000..."
export ESP32_HOST="localhost:8080"
export PYTHONPATH="app"
python3 app/main.py

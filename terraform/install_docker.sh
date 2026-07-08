#!/bin/bash
set -e

# Mise à jour du système
apt-get update -y
apt-get upgrade -y

# Installation des dépendances requises
apt-get install -y ca-certificates curl gnupg lsb-release

# Ajout de la clé GPG officielle de Docker
install -m 0755 -d /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | gpg --dearmor -o /etc/apt/keyrings/docker.gpg
chmod a+r /etc/apt/keyrings/docker.gpg

# Configuration du dépôt Docker
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable" | tee /etc/apt/sources.list.d/docker.list > /dev/null

# Installation de Docker et Docker Compose
apt-get update -y
apt-get install -y docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin

# Ajout de l'utilisateur ubuntu au groupe docker pour pouvoir lancer des commandes sans sudo
usermod -aG docker ubuntu

# Démarrage et activation du service Docker
systemctl enable docker
systemctl start docker

resource "aws_secretsmanager_secret" "aqua_app_secrets" {
  name        = "aqua_atmos_app_secrets"
  description = "Secrets for the Aqua Atmos AI application"
}

resource "aws_secretsmanager_secret_version" "aqua_app_secrets_version" {
  secret_id     = aws_secretsmanager_secret.aqua_app_secrets.id
  secret_string = jsonencode(var.app_secrets)
}

output "public_ip" {
  value = aws_instance.aqua_app.public_ip
}

output "secrets_arn" {
  value       = aws_secretsmanager_secret.aqua_app_secrets.arn
  description = "ARN of the Secrets Manager secret"
}

output "name_servers" {
  value       = aws_route53_zone.aqua_atmos.name_servers
  description = "Name servers to configure in the parent domain registrar for delegation"
}

resource "aws_route53_zone" "aqua_atmos" {
  name = "aqua-atmos.adandeappolinaire.me"
}

resource "aws_route53_record" "aqua_atmos_a" {
  zone_id = aws_route53_zone.aqua_atmos.zone_id
  name    = "aqua-atmos.adandeappolinaire.me"
  type    = "A"
  ttl     = "300"
  records = [aws_instance.aqua_app.public_ip]
}

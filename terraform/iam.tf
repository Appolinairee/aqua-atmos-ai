resource "aws_iam_role" "ec2_secrets_role" {
  name = "aqua-atmos-ec2-secrets-role"
  assume_role_policy = jsonencode({
    Version = "2012-10-17"
    Statement = [
      {
        Action = "sts:AssumeRole"
        Effect = "Allow"
        Principal = {
          Service = "ec2.amazonaws.com"
        }
      }
    ]
  })
}

resource "aws_iam_policy" "secrets_read_policy" {
  name        = "aqua-atmos-secrets-read-policy"
  description = "Allows reading the Aqua Atmos secrets from Secrets Manager"
  policy = jsonencode({
    Version = "2012-10-17"
    Statement = [
      {
        Action   = ["secretsmanager:GetSecretValue"]
        Effect   = "Allow"
        Resource = aws_secretsmanager_secret.aqua_app_secrets.arn
      }
    ]
  })
}

resource "aws_iam_role_policy_attachment" "secrets_policy_attach" {
  role       = aws_iam_role.ec2_secrets_role.name
  policy_arn = aws_iam_policy.secrets_read_policy.arn
}

resource "aws_iam_instance_profile" "ec2_profile" {
  name = "aqua-atmos-ec2-profile"
  role = aws_iam_role.ec2_secrets_role.name
}

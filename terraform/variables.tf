variable "key_name" {
  default = "devops-test-key"
}

variable "instance_type" {
  default = "t3.medium"
}

variable "app_secrets" {
  type        = map(string)
  description = "Application secrets to store in AWS Secrets Manager"
  sensitive   = true
}

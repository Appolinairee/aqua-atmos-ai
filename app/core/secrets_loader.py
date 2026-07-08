import os
import json
import logging
from pathlib import Path
from dotenv import load_dotenv

logger = logging.getLogger(__name__)

def load_environment_secrets():
    """
    Loads secrets into os.environ.
    First loads from local .env file.
    Then, if USE_AWS_SECRETS=true, fetches and overrides from AWS Secrets Manager.
    """
    # 1. Load local .env (fallback/defaults)
    env_path = Path(__file__).parent.parent.parent / '.env'
    load_dotenv(dotenv_path=env_path)

    # 2. Load from AWS Secrets Manager if enabled
    if os.environ.get("USE_AWS_SECRETS", "false").lower() == "true":
        try:
            import boto3
            from botocore.exceptions import ClientError
        except ImportError:
            logger.error("boto3 is required to load AWS Secrets")
            return

        secret_name = os.environ.get("AWS_SECRET_NAME", "aqua_atmos_app_secrets")
        region_name = os.environ.get("AWS_REGION", "us-east-1") # Ajuster la région si besoin

        try:
            client = boto3.client(service_name='secretsmanager', region_name=region_name)
            response = client.get_secret_value(SecretId=secret_name)
            
            if 'SecretString' in response:
                secret_dict = json.loads(response['SecretString'])
                for key, value in secret_dict.items():
                    os.environ[key] = str(value)
                    
            logger.info("Successfully loaded secrets from AWS Secrets Manager.")
        except ClientError as e:
            logger.error(f"Failed to load AWS secrets: {e}")

# Automatically execute when imported
load_environment_secrets()

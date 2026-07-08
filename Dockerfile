FROM python:3.12-slim

RUN addgroup --system --gid 1001 aqua \
 && adduser --system --uid 1001 --ingroup aqua aqua

WORKDIR /app

COPY app/requirements.txt app/requirements.txt
RUN pip install --no-cache-dir -r app/requirements.txt

COPY app/ app/
COPY src/ src/
COPY assets/ assets/
RUN install -d -o aqua -g aqua data



USER aqua

ENV PYTHONPATH=app
ENV PYTHONUNBUFFERED=1

EXPOSE 5000 8080

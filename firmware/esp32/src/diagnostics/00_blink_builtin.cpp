#include <Arduino.h>

void setup() {
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  Serial.println("BLINK TEST - GPIO2 builtin LED");
}

void loop() {
  digitalWrite(2, HIGH);
  Serial.println("ON");
  delay(500);
  digitalWrite(2, LOW);
  Serial.println("OFF");
  delay(500);
}

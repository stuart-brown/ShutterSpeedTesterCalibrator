#include <Arduino.h>

#define LASER_LED PB7

void setup()
{
  pinMode(LASER_LED, OUTPUT);
}

void loop()
{
  digitalWrite(LASER_LED, HIGH);
  delay(100);
  digitalWrite(LASER_LED, LOW);
  delay(900);
}
#include <Arduino.h>

#define LASER_LED PB7
#define USER_BUTTON PC13
#define USER_LED PA5

volatile uint32_t on_pulse_ms = 128;
volatile uint32_t off_pulse_ms = 1000 - on_pulse_ms;

void button_press_isr()
{
  digitalWrite(USER_LED, HIGH);
  on_pulse_ms *= 2;
  if (on_pulse_ms > 1024)
  {
    on_pulse_ms = 1;
  }
  if (on_pulse_ms < 1000)
  {
    off_pulse_ms = 1000 - on_pulse_ms;
  }
  else
  {
    off_pulse_ms = 1000;
  }
  digitalWrite(USER_LED, LOW);
}

void setup()
{
  pinMode(LASER_LED, OUTPUT);
  pinMode(USER_LED, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(USER_BUTTON), button_press_isr, FALLING);
  digitalWrite(USER_LED, LOW);
}

void loop()
{
  digitalWrite(LASER_LED, HIGH);
  delay(on_pulse_ms);
  digitalWrite(LASER_LED, LOW);
  delay(off_pulse_ms);
}

#include "Arduino.h"
#include "Clock/RtcClock.h"
#include <Wire.h>
#include <DS3232RTC.h>

RtcClock clock;
int count = 0;

void timer();

void setup() {
  Serial.begin(9600);
  Serial.println("initialize");

  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), timer, FALLING);
  clock.begin();

  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH);
  delay(1000);
  digitalWrite(13, LOW);
  delay(1000);
}

void timer() {

   Time time = clock.getTime();

  Serial.print("Czas: ");
  Serial.print(count);
  Serial.print(":  ");
  Serial.print(time.hour);
  Serial.print(":");
  Serial.print(time.minute);
  Serial.print(":");
  Serial.print(time.second);
  Serial.print("\n");

  count++;
}

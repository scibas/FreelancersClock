#include "Arduino.h"
#include "Clock/RtcClock.h"
#include <Wire.h>
#include <DS3232RTC.h>
// class Clock;

RtcClock clock;
int count = 0;

void timer();

void setup() {
  Serial.begin(9600);
  Serial.println("initialize");
     // the function to get the time from the RTC
  clock = RtcClock();

  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), timer, FALLING);

  pinMode(13, OUTPUT);
}

void loop() {
  digitalWrite(13, HIGH); // turn the LED on (HIGH is the voltage level)
  delay(1000);            // wait for a second
  digitalWrite(13, LOW);  // turn the LED off by making the voltage LOW
  delay(1000);
}

void timer() {

  // Time time = clock.getTime();

  Serial.print("Czas: ");
  // Serial.print(count);
  // Serial.print(":  ");
  // Serial.print(time.hour);
  // Serial.print(":");
  // Serial.print(time.minute);
  // Serial.print("\n");

  count++;
}

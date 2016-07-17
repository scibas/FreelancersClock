#include "Arduino.h"
#include "Clock/RtcClock.h"
#include <Wire.h>
#include <DS3232RTC.h>

RtcClock clock;

void rtcTimeDidChange();

void setup() {
  Serial.begin(9600);
  Serial.println("initialize");

  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), rtcTimeDidChange, FALLING);
  clock.begin();
}

void loop() {}

void rtcTimeDidChange() {

   Time time = clock.getTime();

  char timeString[8];
  sprintf(timeString, "%d:%02d:%02d", time.hour, time.minute , time.second);
  Serial.println(timeString);
}

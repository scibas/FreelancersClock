#include "RtcClock.h"
#include "Time.h"

RtcClock::RtcClock() {
}

void RtcClock::begin() {
  rtc.squareWave(SQWAVE_1_HZ);
  Serial.println("Setting squareWave");

  setSyncProvider(rtc.get);
}

Time RtcClock::getTime() {
  Time time;
  time.hour = hour();
  time.minute = minute();
  time.second = second();

  return time;
}

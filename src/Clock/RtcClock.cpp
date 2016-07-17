#include "RtcClock.h"
#include "Time.h"

RtcClock::RtcClock() {
}

void RtcClock::begin() {
  RTC.squareWave(SQWAVE_1_HZ);
  setSyncProvider(RTC.get);
}

Time RtcClock::getTime() {
  Time time;
  time.hour = hour();
  time.minute = minute();
  time.second = second();

  return time;
}

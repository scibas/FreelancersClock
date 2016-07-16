#include "RtcClock.h"
#include "Time.h"
#include "DS3232RTC.h"

// DS3232RTC rtc;

RtcClock::RtcClock() {
  // setSyncProvider(RTC.get);
  //setSyncProvider(RTC.get);
  // rtc = DS3232RTC();
  // RTC.squareWave(SQWAVE_1_HZ);
  Serial.println("Setting squareWave");
}

Time RtcClock::getTime() {
  Time time;
  time.hour = 12;
  time.minute = 0;

  return time;
}

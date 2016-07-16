#include "Clock/Clock.h"
#include "DS3232RTC.h"

class RtcClock {
public:
  RtcClock();
  void begin();

  Time getTime();
  DS3232RTC rtc;

};

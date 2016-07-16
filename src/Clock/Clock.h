#include <stdint.h>

struct Time {
  uint8_t hour;
  uint8_t minute;
  uint8_t second;
};

struct Date {
  uint16_t year;
  uint8_t month;
  uint8_t day;
  uint8_t dayOfWeek;
};

class Clock {

public:
  // virtual void setTime(Time time) = 0;
  virtual Time getTime() = 0;

  // virtual void setDate(Date date);
  // virtual Date getDate();
  //
  // virtual void setAlarm(Time time);
  // virtual bool isAlarmEnabled();
  // virtual void disableAlarm();
};

//
// Created by Omar Shaban on 10/16/21.
//

#ifndef ASS2_TIMESPAN_H
#define ASS2_TIMESPAN_H

#include <iostream>

using namespace std;

class TimeSpan {
  friend ostream &operator<<(ostream &out, const TimeSpan &ts);

public:
  // explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
  explicit TimeSpan(double hour = 0, double minute = 0, double second = 0);

  // add
  TimeSpan operator+(const TimeSpan &ts) const;

  // subtract
  TimeSpan operator-(const TimeSpan &ts) const;

  // check equality
  bool operator==(const TimeSpan &ts) const;

  // check if not equal
  bool operator!=(const TimeSpan &ts) const;

  // multiply timespan by an unsigned number
  TimeSpan operator*(unsigned int number) const;

  // addition assignment operator
  TimeSpan& operator+=(const TimeSpan &ts);

  // subtract assignment operator
  TimeSpan& operator-=(const TimeSpan &ts);

  // less than
  bool operator<(const TimeSpan &ts) const;

  // greater than
  bool operator>(const TimeSpan &ts) const;

  // less than or equal to
  bool operator<=(const TimeSpan &ts) const;

  // greater than or equal to
  bool operator>=(const TimeSpan &ts) const;

  // hour component of timespan
  int getHour() const;

  // minute component of timespan
  int getMinute() const;

  // second component of timespan
  int getSecond() const;

  // hour component of timespan
  int setHour(int newHour) const;

  // minute component of timespan
  int setMinute(int newMinute) const;

  // second component of timespan
  int setSecond(int newSecond) const;

  // true if timespan is 0 or larger
  bool isPositive() const;

private:
  //constants for conversion
  const double HOURS_TO_SEC = 3600.0;
  const double MINUTES_TO_SEC = 60.0;

  //class variables for hours, minutes, and seconds
  double hourTS;
  double minuteTS;
  double secondTS;

  //organizes the time to correct any issues
  void simplify();

  //modulus that can have double as parameter.
  double dmod(double x, double y);

  //converts time to total seconds
  double toSeconds()const;
};

#endif // ASS2_TIMESPAN_H
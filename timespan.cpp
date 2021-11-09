 //
// Created by Omar Shaban on 10/16/21.
//

#include "timespan.h"

ostream &operator<<(ostream &out, const TimeSpan &ts) {

  if(ts.isPositive() == false){
    out << "-";
  }
  out << abs(ts.hourTS) << ":";
  if(abs(ts.minuteTS) < 9){
    out << "0";
  }
  out << abs(ts.minuteTS) << ":";
  if(abs(ts.secondTS) < 9){
    out << "0";
  }
  out << abs(ts.secondTS);
  return out;
}

// explicit TimeSpan(int Hour = 0, int Minute = 0, int Second = 0);
TimeSpan::TimeSpan(double hour, double minute, double second) {
  hourTS = hour;
  minuteTS = minute;
  secondTS = second;
  simplify();
}

// hour component
int TimeSpan::getHour() const {
  return (int)hourTS;
}

// minute component
int TimeSpan::getMinute() const {
  return (int)minuteTS;
}
// second component
int TimeSpan::getSecond() const {
  return (int)secondTS;
}
// true if timespan is 0 or larger
bool TimeSpan::isPositive() const { 
  if(toSeconds() < 0){
    return false;
  }
    return true; 
}

// add
TimeSpan TimeSpan::operator+(const TimeSpan &ts) const {
  TimeSpan tsSum(hourTS, minuteTS, secondTS);
  tsSum.hourTS = tsSum.hourTS + ts.hourTS;
  tsSum.minuteTS = tsSum.minuteTS + ts.minuteTS;
  tsSum.secondTS = tsSum.secondTS + ts.secondTS;
  tsSum.simplify();
  return tsSum;
}

// subtract
TimeSpan TimeSpan::operator-(const TimeSpan &ts) const {
  TimeSpan tsSub(hourTS, minuteTS, secondTS);
  tsSub.hourTS = tsSub.hourTS - ts.hourTS;
  tsSub.minuteTS = tsSub.minuteTS - ts.minuteTS;
  tsSub.secondTS = tsSub.secondTS - ts.secondTS;
  tsSub.simplify();
  return tsSub;
}

// multiply with an integer
TimeSpan TimeSpan::operator*(unsigned int number) const {
  TimeSpan tsLarge(hourTS, minuteTS, secondTS);
  tsLarge.hourTS = tsLarge.hourTS * number;
  tsLarge.minuteTS = tsLarge.minuteTS * number;
  tsLarge.secondTS = tsLarge.secondTS * number;
  tsLarge.simplify();
  return tsLarge;
}

// equality ==
bool TimeSpan::operator==(const TimeSpan &ts) const {
  if(toSeconds() == ts.toSeconds()){
    return true;
  }else{
    return false;
  }
}

// inequality !=
bool TimeSpan::operator!=(const TimeSpan &ts) const {
  if(toSeconds() == ts.toSeconds()){
    return false;
  }else{
    return true;
  }
}

// addition assignment operator
TimeSpan& TimeSpan::operator+=(const TimeSpan &ts){
  hourTS = hourTS + ts.hourTS;
  minuteTS = minuteTS + ts.minuteTS;
  secondTS = secondTS + ts.secondTS;
  return *this;
}

// subtract assignment operator
TimeSpan& TimeSpan::operator-=(const TimeSpan &ts){
  hourTS = hourTS - ts.hourTS;
  minuteTS = minuteTS - ts.minuteTS;
  secondTS = secondTS - ts.secondTS;
  return *this;
}

// less than
bool TimeSpan::operator<(const TimeSpan &ts) const{
  if(toSeconds() < ts.toSeconds()){
    return true;
  }else{
    return false;
  }
}

// greater than
bool TimeSpan::operator>(const TimeSpan &ts) const{
  if(toSeconds() > ts.toSeconds()){
    return true;
  }else{
    return false;
  }
}

// less than or equal to
bool TimeSpan::operator<=(const TimeSpan &ts) const{
  if(toSeconds() <= ts.toSeconds()){
    return true;
  }else{
    return false;
  }
}

// greater than or equal to
bool TimeSpan::operator>=(const TimeSpan &ts) const{
  if(toSeconds() >= ts.toSeconds()){
    return true;
  }else{
    return false;
  }
}

//organizes the time to correct any issues
void TimeSpan::simplify(){
  double totalSec;
  totalSec = hourTS * HOURS_TO_SEC + minuteTS * MINUTES_TO_SEC + secondTS;

  hourTS = (double)(int)(totalSec/HOURS_TO_SEC);
  totalSec = dmod(totalSec, HOURS_TO_SEC);
  minuteTS = (double)(int)(totalSec/MINUTES_TO_SEC);
  totalSec = dmod(totalSec, MINUTES_TO_SEC);
  secondTS = totalSec;

  double temp = dmod(secondTS, 1);
  if(dmod(secondTS, 1) != 0.0){
    if(temp >= 0.5){
      this->secondTS = secondTS - temp + 1.0;
    }
    if(temp < 0.5){
      this->secondTS = secondTS - temp;
    }
  }  
}

//modulus that can have double as parameter.
double TimeSpan::dmod(double x, double y) {
    return x - (int)(x/y)*y;
}

//converts time to total seconds
double TimeSpan::toSeconds()const{
  double totalSec;
  totalSec = hourTS * HOURS_TO_SEC + minuteTS * MINUTES_TO_SEC + secondTS;
  return totalSec;
}
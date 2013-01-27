#ifndef mapToPWM_h
#define mapToPWM_h

#include "Arduino.h"

class mapToPWM
{
  public:
  	mapToPWM(); //constructor
    int mtp(int guideReading, int guideCentre, int guideMin, int guideMax, int deadZoneWidth, int pwmCentre, int pwmMin, int pwmMax, float kapow, float cap);
  private:
    // int _example;
};

#endif
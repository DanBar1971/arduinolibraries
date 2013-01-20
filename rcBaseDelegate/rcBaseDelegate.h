//incoming serial command handling.
//originally built for RC vehicle communication.

#ifndef rcBaseDelegate_h
#define rcBaseDelegate_h

#include "Arduino.h"

class rcBaseDelegate
{
  public:
  	rcBaseDelegate(); //constructor
    void delegate(String cmd, int cmdval);
  private:
    // int _example;
};

#endif
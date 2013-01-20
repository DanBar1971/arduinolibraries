//incoming serial command handling.
//originally built for RC vehicle communication.

#ifndef inSerialCmd_h
#define inSerialCmd_h

#include "Arduino.h"

class inSerialCmd
{
  public:
  	inSerialCmd(); //constructor
    void serialListen();
  private:
    // int _example;
};

#endif
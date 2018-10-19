/*
  Uartino.h - Library for stable UART communication.
  Created by Dr. Gianluca Rosi, October 19, 2018.
  Released under GNU-GPL v3.0 license.
*/

#ifndef Uartino_h
#define Uartino_h

#include "Arduino.h"

class Uartino
{
  public:
    String sendCommand(const char* command,  unsigned int delayer, unsigned int timeout);
    Boolean fchk(String value, String expectecd)
};

#endif

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

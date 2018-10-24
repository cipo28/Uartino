class Uartino
{
  public:
    String sendCommand(SoftwareSerial mySerial, const char* command,  unsigned int delayer, unsigned int timeout);
    String sendCommand(AltSoftSerial mySerial, const char* command,  unsigned int delayer, unsigned int timeout);
    Boolean fchk(String value, String expectecd)
};

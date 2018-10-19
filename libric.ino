/**
 * @param {SoftwareSerial} mySerial - An already initialized serial object, AltSoftSerial is supported.
 * @param {char*} command - A pointer to the char array containing the command, should be null terminated.
 * @param {unsigned int} delayer - Gives some ms to the module to answer, w/o wasting the "timeout time".
 * @param {unsigned int} timeout - Limits in how much time the module can answer.
 */
String sendCommand(const char* command,  unsigned int delayer, unsigned int timeout){
  //strictly sync
  mySerial.print(command);
  unsigned long previousMillis = millis();
  unsigned long currentMillis = previousMillis;
  
  delay(delayer);
  int x=0;
  while (mySerial.available()<=0 && ((unsigned long)(currentMillis - previousMillis)) <= ((unsigned long) timeout)){
    //Serial.print(x); //DEBUG purposes
    x++;
    currentMillis = millis();
  }
  if(mySerial.available()){
    char reply[mySerial.available()];
    int i = 0;
    while (mySerial.available()) {
      reply[i] = mySerial.read();
      Serial.print(reply[i]);
      delay(3); //If too fast, can be interpreted as a multiple message sent
      i++;
    }
    //end the string
    //reply[i] = '\0'; //DEBUG purposes
    return String(reply);
  }else{
    return "TIMEOUT";
  }
}

/**
 * @param {SoftwareSerial} mySerial - An already initialized serial object.
 * @param {char*} command - A pointer to the char array containing the command, should be null terminated.
 * @param {unsigned int} delayer - Gives some ms to the module to answer, w/o wasting the "timeout time".
 * @param {unsigned int} timeout - Limits in how much time the module can answer.
 */

String sendCommand(SoftwareSerial mySerial, const char* command,  unsigned int delayer, unsigned int timeout){
  mySerial.print(command);
  unsigned long previousMillis = millis();
  unsigned long currentMillis = previousMillis;
  //return answer, strictly sync
  delay(delayer);
  int x=0;
  while (mySerial.available()<=0 && ((unsigned long)(currentMillis - previousMillis)) <= ((unsigned long) timeout)){
    //Serial.print(x);
    x++;
    currentMillis = millis();
  }
  if(mySerial.available()){
    char reply[mySerial.available()];
    int i = 0;
    while (mySerial.available()) {
      reply[i] = mySerial.read();
      Serial.print(reply[i]);
      delay(3);
      i++;
    }
    //end the string
    //reply[i] = '\0';
    return String(reply);
  }else{
    return "TIMEOUT";
  }
}

/**
 * @param {AltSoftSerial} mySerial - An already initialized serial object.
 */

String sendCommand(AltSoftSerial mySerial, const char* command,  unsigned int delayer, unsigned int timeout){
  mySerial.print(command);
  unsigned long previousMillis = millis();
  unsigned long currentMillis = previousMillis;
  //return answer, strictly sync
  delay(delayer);
  int x=0;
  while (mySerial.available()<=0 && ((unsigned long)(currentMillis - previousMillis)) <= ((unsigned long) timeout)){
    //Serial.print(x);
    x++;
    currentMillis = millis();
  }
  if(mySerial.available()){
    char reply[mySerial.available()];
    int i = 0;
    while (mySerial.available()) {
      reply[i] = mySerial.read();
      Serial.print(reply[i]);
      delay(3);
      i++;
    }
    //end the string
    //reply[i] = '\0';
    return String(reply);
  }else{
    return "TIMEOUT";
  }
}

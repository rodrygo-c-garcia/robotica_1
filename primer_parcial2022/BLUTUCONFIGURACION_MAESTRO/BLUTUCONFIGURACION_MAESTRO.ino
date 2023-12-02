#include <SoftwareSerial.h>
SoftwareSerial mySerial(11,10); //TX,RX
void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
 if (Serial.available()) {
    char data = Serial.read();
    mySerial.write(data);
  } 
}

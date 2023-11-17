#incl+ude <SoftwareSerial.h>
// 11 receptor,   Rx, Tx
SoftwareSerial se(10, 11);

void setup() {
  Serial.begin(9600);
  
  // iniciar la comunicacion serial
  se.begin(9600);j

}

void loop() {
  // si recibimos del software seria lo escribimos en la pantalla
  if(se.available()){
    Serial.write(se.read());
  }
  // 
  if(Serial.available()){
    se.write(Serial.read());
  }
}

// AT+NAME=MYMODULE
// AT+PSWD

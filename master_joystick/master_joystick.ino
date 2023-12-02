// CODE MASTER
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // TX, RX

//JOYSTICK
//Pines analógicos
int ejeX = A0,
    ejeY = A1,
    lecturaX = 0,
    lecturaY = 0,
    a = 0;

void setup() {
  Serial.begin(9600);
  mySerial.begin(9600);
  pinMode(ejeX, INPUT);
  pinMode(ejeY, INPUT);  
}

void loop() {
  lecturaX = analogRead(ejeX);
  lecturaY = analogRead(ejeY);

  delay(1);
  Serial.print(lecturaX);
  Serial.print(",");
  Serial.print(lecturaY);

  //ADELANTE
  if(lecturaX >= 800 && a == 1){
    mySerial.write('1');
    delay(50);
    a = 0;  
  }

  //ATRAS
  if(lecturaX <= 200 && a == 1) {
    mySerial.write('2');
    delay(50);
    a = 0;  
  }

  //DETENERSE
  if(lecturaX >= 201 && lecturaX <= 699 && lecturaY >= 201 && lecturaY <= 699 && a == 0){
    mySerial.write('5');
    delay(50);
    a = 1;
  }

  //DERECHA
  if(lecturaY <= 800 && a == 1){
    mySerial.write('3');
    delay(50);
    a = 0;
  }

    //IZQUIERDA
  if(lecturaY >= 800 && a == 1){
    mySerial.write('4');
    delay(50);
    a = 0;
  }
}

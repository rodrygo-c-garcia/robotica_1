#include <SoftwareSerial.h>
#include <Ultrasonic.h>
SoftwareSerial mySerial(10,11); //RX,Tx
Ultrasonic ultrasonic(4, 5);
int distancia;
int mandar=10;
int led2=3;
void setup() {
  Serial.begin(9600);
  pinMode(led2,OUTPUT);
  mySerial.begin(9600);
}

void loop() {
  distancia = ultrasonic.read();  
  
  
  Serial.print("Distancia: ");
  Serial.println(distancia);
  delay(100); 
  mySerial.write(distancia);

  if(distancia > 12){
    digitalWrite(led2, LOW); 
    delay(100);   
  }else{
    digitalWrite(led2, HIGH);
    delay(100);  
  }
  
}

//#include <SoftwareSerial.h>
//// #include <Ultrasonic.h>
//SoftwareSerial mySerial(10,11); //RX,Tx
//// Ultrasonic ultrasonic(11, 10);
//int distancia;
//int a=5;
//void setup() {
//  Serial.begin(9600);
//  mySerial.begin(9600);
//}
//
//void loop() {
////  distancia = ultrasonic.read();  
//  delay(1);
//  Serial.print("Distancia: ");
//  Serial.println(a);
//
//  mySerial.write(a);
//}



//ARDUINO 1
//     -> MAESTRO
//     -> SENSOR ULTRASONIC
//
//ARDUINO 2
//    -> MOTOR 2      -> MOTOR 1
//    -> LED1
//    -> ESCLAVO 
//
//
//SI SENSOR > 12CM
// MOTOR 1 Y MOTOR 2 
// PRENDIDO 
// LED 2 PRENDIDO 
// LED 2 PRENDIDO

 

#include <Ultrasonic.h>
int triggerPin = 11, // trigger es la salida es decir envia una onda de sonido (emisor)
    echoPin = 12, // recibe la onda de sonido (receptor)
    distance,
    pin1 = 8;

//Ultrasonic ultrasonic(trigger, echo)
Ultrasonic ultrasonic(11, 12);

void setup() {
  Serial.begin(9600);
  pinMode(pin1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = ultrasonic.read(); // retorna la distancia en cm
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");
  if(distance <= 10){
    digitalWrite(pin1, HIGH);
  }
  else {
    digitalWrite(pin1, LOW);
  }
  
 }

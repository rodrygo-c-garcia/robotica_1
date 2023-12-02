// examen viernes

#include <Ultrasonic.h>
int triggerPin = 11, // trigger es la salida es decir envia una onda de sonido (emisor)
    echoPin = 12, // recibe la onda de sonido (receptor)
    distance,
    led1 = 8,
    led2 = 9;

//Ultrasonic ultrasonic(trigger, echo)
Ultrasonic ultrasonic(triggerPin, echoPin);

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = ultrasonic.read(); // retorna la distancia en cm
  Serial.print("Distancia: ");
  Serial.print(distance);
  Serial.println(" cm");
  
  if(distance > 25){
    digitalWrite(led1, LOW);
    digitalWrite(led2, HIGH);
  }
  else if(distance < 8){
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
  } else if(distance > 8 && distance < 25){
    analogWrite(led1, map(distance, 25, 8, 0, 255));
    analogWrite(led2, map(distance, 25, 8, 255,0));
  }
  delayMicroseconds(100);
 }

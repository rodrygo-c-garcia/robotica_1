#include <Ultrasonic.h>

//Partes del sensor
int triggerPin = 11;
int echoPin = 12;
Ultrasonic sensor(triggerPin, echoPin); 
int distance;

//potenciometro
int potenciometroPinAnalog = 0; // pin analogico
int valorPotenciometro;

//leds
int led1 = 8;
int led2 = 9;
int led3 = 10;

//variables true o false
bool prendido = true;

void setup() {
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop() {
  distance  = sensor.read(); // obtnemos el valor de la distancia en cm
  Serial.print("la distancia en cm es: ");
  Serial.println(distance);
  valorPotenciometro = analogRead(potenciometroPinAnalog);// 0 a 1023 = 
  Serial.print("valor actual del potenciometro es: ");
  Serial.println(valorPotenciometro);
  
  if(valorPotenciometro==0 or valorPotenciometro==1){//prendido hacia tope derecho
    ctrlSensor();
    digitalWrite(led1, HIGH);
    digitalWrite(led3, LOW);
  }else if(valorPotenciometro==1023){//apagado hacia tope izquierdo
    digitalWrite(led2, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led3, HIGH);
  }
  delay(1000);
}

void ctrlSensor(){
  (distance < 12) ? digitalWrite(led2, HIGH) : digitalWrite(led2, LOW);
}

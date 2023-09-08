#include <Ultrasonic.h>
Ultrasonic sensor(7,6);

int potenciometro=0;
int valor=0;
int brillo;
int modulador=255;

int ledA = 12;
int ledB = 11;
int ledC = 10;
int distancia;

void setup() {
  //pinMode(potenciometro,INPUT);
  Serial.begin(9600);
  pinMode(ledA,OUTPUT);
  pinMode(ledB,OUTPUT);
  pinMode(ledC,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //analogRead  (PIN) leo valores de 0 a 1024 
  //analogWrite  0 a 255
  //digitalRead(PIN) leo valores de [ 0=heigh al 1=low ]
  valor= analogRead(potenciometro);// 0 a 1023
  //brillo= valor*0.25;
  brillo= map(valor,0,1023,0,255);
  
  distancia=sensor.read();
  if(valor < 512){
    digitalWrite(ledC, LOW);
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    delay(500);
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    delay(500);
  }else{
      digitalWrite(ledC, HIGH);
      digitalWrite(ledA, LOW);
      digitalWrite(ledB, LOW);
      if(distancia<=10)
      {
        digitalWrite(ledA, HIGH);
        digitalWrite(ledB, HIGH);
        delay(500);
      }else{    
        digitalWrite(ledA, LOW);
        digitalWrite(ledB, LOW);
        delay(500);
      }
  }


  
  
  Serial.println(valor);
  Serial.print("Distancia en CM:");
  Serial.println(distancia);
  
  //Serial.println(brillo);
  // foruma de 3 es valor ->1023   , 255
  if(brillo >=0 && brillo <=255){
    modulador=modulador-brillo;
    //analogWrite(led1, modulador);
  }
  
  //analogWrite(led, brillo); //esto va hasta dos 255
  
  
  //delay(200);


  
  
}


// cuando el potenciometro este en de la mitad 
/*
# Robotica

3 leds
3 resistencias
1 potenciometro
Sensor ultrasonico


Funcionalidad: 
Cuando el potenciometro este del tope hasta antes de la mitad el led prendido pasa a apagado 
y cuando el potenciometro este de la mitad para arriba se prende

Si el sistema esta apagado el potenciometro de mitad para abajo
el led 'a' y 'b' parpadean cada segundo al mismo tiempo

Si el sistema esta prendido 
led 'a' y 'b' se encenderan cuando el sensor ultrasonico detecte una distancia menor de a 10 cm. y sino se apagan




*/

/*
2 led 
1 potenciometro 
1 motor
Primer parcial 
*Cuando el potenciometro este en mas de la mitad de su valor 
  ->  Led A prendido 
  -> motor girando 
    para adelante con velo 200
    hasta que el sensorultrasonico detecte menos de 15cm
*cuando el potenciometro este en menos de la mitad de su valor 
* -> led b prendido
  -> motor girando atras 
  con una vel. de 190 hata que el sensor ultrasonico detecte
  una distacia mayor a 15cm
*imprimir siempre en ptantall 
*velocidad motor
*distnacia medida 
*valor potenciometro

*/
// variables
#include <Ultrasonic.h>
int veloMotor=0;
int distancia=0;
int potenciometro=0;
int ledA=6;
int ledB=5;
int mot_izq1=8;
int mot_izq2=7;
int brillo;
int valor=0;
Ultrasonic sensor(2,3);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledA,OUTPUT);
  pinMode(ledB,OUTPUT);
  pinMode(mot_izq1, OUTPUT);
  pinMode(mot_izq2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  distancia=sensor.read();
  Serial.print("Distancia en CM:");
  Serial.println(distancia);
  Serial.print("Potenciometro:");
  valor= analogRead(potenciometro);
  Serial.println(valor);
  //brillo= map(valor,0,1023,0,255);
  //Serial.print("Potenciometro:");
  Serial.print("velocidad:");
  valor= analogRead(veloMotor);
  
  delay(500);
  // 1023/2= 512
  if(valor > 512){
    //Serial.print("AQUI: 512");
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    if(distancia >= 15 ){
      veloMotor=200;
      analogWrite(mot_izq1, 200 ); //0 a 1024
      analogWrite(mot_izq2, 0 ); 
    }else{
       analogWrite(mot_izq1, 0 ); //0 a 1024
        analogWrite(mot_izq2, 0 ); 
    }
  }
  
  if( valor >= 0 &&  valor <=511 ){
    //Serial.print("AQUI: MENOR");
    digitalWrite(ledB, HIGH);
    digitalWrite(ledA, LOW);
    if(distancia >= 0 &&  distancia <=15){
      veloMotor=190;
      analogWrite(mot_izq1, 0 ); //0 a 1024
      analogWrite(mot_izq2, 190 ); 
    }else{
       analogWrite(mot_izq1, 0 ); //0 a 1024
       analogWrite(mot_izq2, 0 ); 
    }
  }
  

  /*if(valor >= 0 && valor < 512){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, LOW);
    delay(500);
  }else{
    digitalWrite(ledB, HIGH);
    digitalWrite(ledA, LOW);
    delay(500);
  }*/
  
  
  //digitalWrite(ledA, HIGH);
  //digitalWrite(ledB, HIGH);

}

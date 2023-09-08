#include <Ultrasonic.h>
//trigel echo, //el vcc va a 5 voltios la conexion  
Ultrasonic sensor(4,5);

int potenciometro=0;
int distancia;
int ledA = 4;


//el positivo a al rojo de 12 voltios a las pilas
//el gnd va al negro con y el otro conector de gnd va al gnd del arduino
// motor // pinex chiquiutos 



int mot_der1=12;
int mot_der2=11;
//motor los pines chiquitos
int mot_izq1=8;
int mot_izq2=7;
//
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledA,OUTPUT);
  //motor
  pinMode(mot_der1, OUTPUT);
  pinMode(mot_der2, OUTPUT);
  pinMode(mot_izq1, OUTPUT);
  pinMode(mot_izq2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //si el sensor ultrasonico mide una distancia< 22cm
  //    motor se mueva hacia adelante con una velocidad de 150
  //si el sensor ultrasonico mide una distancia mayor o igual a 22cm
  //  pero menor a 30cm
  //  un led debe parpadear cada segundo 
  //En otro caso
  //  Motor se mueva hcia atras 
  //  con una velocidad de 150



  //sensor ultrasonico
  distancia=sensor.read();
  Serial.print("Distancia en CM:");
  Serial.println(distancia);
  delay(1000);
  //
  //digitalWrite(ledA, LOW);

  if(distancia < 22){
    analogWrite(mot_izq1, 150 ); //0 a 1024
    analogWrite(mot_izq2, 0 ); 
    
  }
  if(distancia >= 22 && distancia < 30){
    analogWrite(mot_izq1, 0 ); //0 a 1024
    analogWrite(mot_izq2, 0 );
    delay(1000);
    digitalWrite(ledA, HIGH);
    delay(1000);
    digitalWrite(ledA, LOW);
     
    
  }
  
  if(distancia>=30){
    analogWrite(mot_izq1, 0 ); //0 a 1024
    analogWrite(mot_izq2, 150 );
     digitalWrite(ledA, LOW);
  }

  
}

//  motor
// el positivo a al rojo de 12 voltios a las pilas y puede ir al vcnn tambien
// el gnd va al negro con y el otro conector de gnd va al gnd del arduino
// motor // pinex chiquiutos 
//  int mot_izq1=8;
//  int mot_izq2=7;
//  pinMode(mot_izq1, OUTPUT);
//  pinMode(mot_izq2, OUTPUT);
//  analogWrite(mot_izq1, 150 ); //0 a 1024
//    analogWrite(mot_izq2, 0 ); 
//


//led
//  la pata grande va al pinModel ejempl0 1,2,3,4
//  y la patitca chiquita va a gnd con la resistencia
//


//potenciometro
// conextar 1 a positivo vcc(5voltios) y otra a negativa(gnd)
// la pata del medio es a un pin model analogico 
//int potenciometro=0;
//  valor= analogRead(potenciometro);// 0 a 1023
//
// esto es para regular el valor entre 0 a 255
//  int brillo;
// brillo= map(valor,0,1023,0,255);

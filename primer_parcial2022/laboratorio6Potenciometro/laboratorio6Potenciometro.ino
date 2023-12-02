

int potenciometro=0;
int velocidad;

int valor=0;
//
int distancia;
int ledA = 11;
int ledB = 10;

int mot_izq1=8;
int mot_izq2=7;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledA,OUTPUT);
  pinMode(ledB,OUTPUT);
  //motor
  pinMode(mot_izq1, OUTPUT);
  pinMode(mot_izq2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valor= analogRead(potenciometro);// 0 a 1023
  //brillo= valor*0.25;
  velocidad= map(valor,0,1023,0,255);
  Serial.print("velocidad en :");
  Serial.println(velocidad);
  delay(200);
  if(velocidad== 0){
     digitalWrite(ledA, HIGH);
     digitalWrite(ledB, LOW);
     analogWrite(mot_izq1, 0 ); //0 a 1024
      analogWrite(mot_izq2, 0 );
  }
  if(velocidad >0 &&  velocidad < 200){
    digitalWrite(ledA, LOW);
     digitalWrite(ledB, LOW);
     analogWrite(mot_izq1, velocidad ); //0 a 1024
      analogWrite(mot_izq2, 0 );
  }
  if(velocidad >= 200 && velocidad <=255 ){
     digitalWrite(ledA, LOW);
     digitalWrite(ledB, HIGH);
       analogWrite(mot_izq1, velocidad ); //0 a 1024
      analogWrite(mot_izq2, 0 );
  }


  
}

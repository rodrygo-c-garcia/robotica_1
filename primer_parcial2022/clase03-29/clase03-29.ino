int mot_der1=12;
int mot_der2=11;

int mot_izq1=8;
int mot_izq2=7;

void setup() {
  // put your setup code here, to run once:
    pinMode(mot_der1, OUTPUT);
    pinMode(mot_der2, OUTPUT);
    pinMode(mot_izq1, OUTPUT);
    pinMode(mot_izq2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //velocidad a un lado
  analogWrite(mot_der1, 150 ); //0 a 1024
  analogWrite(mot_der2, 0 ); 
  //
  analogWrite(mot_izq1, 150 ); //0 a 1024
  analogWrite(mot_izq2, 0 ); 
  delay(2000);
  
  analogWrite(mot_der1, 0 ); //0 a 1024
  analogWrite(mot_der2, 150 ); 
  //
  analogWrite(mot_izq1, 0 ); //0 a 1024
  analogWrite(mot_izq2, 150 ); 
  delay(2000);
}

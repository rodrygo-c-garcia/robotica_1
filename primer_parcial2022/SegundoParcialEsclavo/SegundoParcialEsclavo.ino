




int mot_der1=12;
int mot_der2=11;
//motor los pines chiquitos
int mot_izq1=8;
int mot_izq2=7;
int DATO = 0;
int led1=13;
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  pinMode(mot_der1, OUTPUT);
  pinMode(mot_der2, OUTPUT);
  pinMode(mot_izq1, OUTPUT);
  pinMode(mot_izq2, OUTPUT);
  pinMode(led1,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    //DATO = Serial.read();  
    DATO = Serial.parseInt();
    Serial.print("Distancia: ");
    Serial.println(DATO);
    delay(100); 
    if(DATO > 12){
      analogWrite(mot_izq1, 0 ); //0 a 1024
      analogWrite(mot_izq2, 150 );
      analogWrite(mot_der1, 0 ); //0 a 1024
      analogWrite(mot_der2, 150 );
      digitalWrite(led1, LOW);    
    }
    digitalWrite(led1, HIGH);
  }
    
  

}





// para el esclavo. 
//int led=4;
//int DATO = 0;
//
//
//void setup() {
//  pinMode(led,OUTPUT);
//  digitalWrite(led,LOW);
//  Serial.begin(9600);  
//
//}
//
//void loop() {
//  if(Serial.available()>0){
//    DATO = Serial.read();  
//  }
//
// if (DATO == '5') {
//   delay(500);
//    digitalWrite(led, LOW);
//     delay(500);
// }
//}

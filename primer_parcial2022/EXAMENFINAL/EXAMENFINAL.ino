char DATO;
int pinA = 4;
int pinB = 5;
int motor1 = 10;
int motor2 = 11;
int motor3 = 12;
int motor4 = 13;
void setup() {
  //pinMode(10, OUTPUT);
  Serial.begin(9600);  
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);

  analogWrite(motor1, 0);
  analogWrite(motor2, 0);
  analogWrite(motor3, 0);
  analogWrite(motor4, 0);
}

void loop() {
  //digitalWrite(pinB, HIGH);
  
  if(Serial.available()>0){
    DATO = Serial.read();
    Serial.print(DATO);
    Serial.print(DATO);
//teclas a precionar son X=MOTOR1,Y=led1,Z=led2 ,P=motor2, S= apagado
    if(DATO == 'X') {
      analogWrite(motor1, 150);
      analogWrite(motor2, 0);
    } else if(DATO == 'Y') {
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, HIGH);
    } else if(DATO == 'Z') {
      digitalWrite(pinA, HIGH);
      digitalWrite(pinB, LOW);
//      digitalWrite(pinC, HIGH);
      digitalWrite(motor1, LOW);
      digitalWrite(motor2, LOW);
    } else if(DATO == 'P') {
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      analogWrite(motor3, 150);
      analogWrite(motor4, 0);
    }else if(DATO == 'S') {
      digitalWrite(pinA, LOW);
      digitalWrite(pinB, LOW);
      digitalWrite(motor1, LOW);
      digitalWrite(motor2, LOW);
      analogWrite(motor3, LOW);
      analogWrite(motor4, LOW);
    }
  }
}

int ledA = 12;
int ledB = 11;
int ledC = 10;

int potenciometro = A0;
int sensor = 0;

int valorPotenciometro = 0;
int valorSensor = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(potenciometro, INPUT);
  pinMode(sensor, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  valorPotenciometro = analogRead(potenciometro);
  valorSensor = analogRead(sensor);
  if(valorPotenciometro < 512){
    digitalWrite(ledA, HIGH);
    digitalWrite(ledB, HIGH);
    delay(1000);
    digitalWrite(ledA, LOW);
    digitalWrite(ledB, LOW);
    delay(1000);
  }else{
    if(valorSensor < 10){
      digitalWrite(ledA, HIGH);
      digitalWrite(ledB, HIGH);
    }else{
      digitalWrite(ledA, LOW);
      digitalWrite(ledB, LOW);
    }
  }
}

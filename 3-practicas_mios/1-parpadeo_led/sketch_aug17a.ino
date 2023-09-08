// pines
int pin1 = 8;
int pin2 = 9;
int pin3 = 10;
int pin4 = 11;

int delayTime = 1000;
void setup() {
  // put your setup code here, to run once:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin3, OUTPUT);
  pinMode(pin4, OUTPUT);
}

void loop() {
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
    delay(delayTime);
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, LOW);
    delay(delayTime);
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, LOW);
    delay(delayTime);
    digitalWrite(pin1, LOW);
    digitalWrite(pin2, LOW);
    digitalWrite(pin3, LOW);
    digitalWrite(pin4, HIGH);
    delay(delayTime);
}

void allOn(){
    digitalWrite(pin1, HIGH);
    digitalWrite(pin2, HIGH);
    digitalWrite(pin3, HIGH);
    digitalWrite(pin4, HIGH);
 }

 void parpedeo(){
  for(int i = 0; i <= 5; i++){
    digitalWrite(pin1, HIGH);
    delay(delayTime);
    digitalWrite(pin1, LOW);
    delay(delayTime);
  }

  for(int i = 0; i <= 5; i++){
    digitalWrite(pin2, HIGH);
    delay(delayTime);
    digitalWrite(pin2, LOW);
    delay(delayTime); 
  }

  for(int i = 0; i <= 5; i++){
    digitalWrite(pin3, HIGH);
    delay(delayTime);
    digitalWrite(pin3, LOW);
    delay(delayTime);
  }

  for(int i = 0; i <= 5; i++){
    digitalWrite(pin4, HIGH);
    delay(delayTime);
    digitalWrite(pin4, LOW);
    delay(delayTime);
  }
  }

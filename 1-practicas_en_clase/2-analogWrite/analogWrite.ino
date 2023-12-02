
const int led = 10;
const int led2 = 9;
int brillo = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
}

void loop() {
  cicloForMas();
  cicloForMenos();
}

void cicloForMas(){
  for(brillo = 0; brillo <= 255; brillo +=5){
    analogWrite(led, brillo);
    analogWrite(led2, 0);
    delay(25);
  }
}

void cicloForMenos(){
  for(brillo = 255; brillo >= 0; brillo -=5){
    analogWrite(led, 0);
    analogWrite(led2, brillo);
    delay(25);
  }
}

int potenciometro=0;
int valor=0;
int brillo;
int led=11;
int led1=10;
int modulador=255;
void setup() {
  //pinMode(potenciometro,INPUT);
  Serial.begin(9600);
  pinMode(led,OUTPUT);
  pinMode(led1,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //analogRead  (PIN) leo valores de 0 a 1024 
  //analogWrite  0 a 255
  //digitalRead(PIN) leo valores de [ 0=heigh al 1=low ]
  //


  
  valor= analogRead(potenciometro);// 0 a 1023
  //brillo= valor*0.25;
  brillo= map(valor,0,1023,0,255);
  
  //Serial.println(valor);
  Serial.println(brillo);
  // foruma de 3 es valor ->1023   , 255
  if(brillo >=0 && brillo <=255){
    modulador=modulador-brillo;
    analogWrite(led1, modulador);
  }
  
  analogWrite(led, brillo); //esto va hasta dos 255
  
  
  delay(200);


  
  
}

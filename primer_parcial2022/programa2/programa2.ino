int led=10;
int brillo=0;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  if(brillo>=0 ) {
    brillo+=25;
    analogWrite(led,brillo);
    delay(200);

    
  }

 
 
 /* for(int i=255; i>=0; i-=30){
   analogWrite(led,i);
    delay(100);
  }

  for(int i=0; i<=255; i+=30){
   analogWrite(led,i);
    delay(100);
  }
  */
  
  
  /*if(brillo<=0){
    analogWrite(led,0);
     brillo=255;
     delay(200);
  }else if(brillo){  
    analogWrite(led,brillo);
    brillo-=40;
    delay(200);
  }*/
  
  /*for(int i=255; i>=0; i-=20){
   analogWrite(led,i);
  delay(100);
  }*/
  /*analogWrite(led,255);
  delay(500);
  analogWrite(led,170);
  delay(500);
  analogWrite(led,85);
  delay(500);
  analogWrite(led,50);
  delay(500);
  analogWrite(led,0);
  delay(500);*/
}

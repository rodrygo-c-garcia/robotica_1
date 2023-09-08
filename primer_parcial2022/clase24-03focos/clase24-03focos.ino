
int potenciometro=0;
int valor=0;
int estado=0;
int led1=8;
int led2=7;
int led3=6;
int led4=5;
int led5=4;
int modulador=255;
int brillo;
int aux=0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  pinMode(led5,OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  valor= analogRead(potenciometro);// 0 a 1023
  //brillo= valor*0.25;
  brillo= map(valor,0,1023,0,255);



  //204
  /*
  if(estado == 0){
        
    Serial.println(valor);
    Serial.println(brillo);

    
    if(valor>=0 && valor>204){
      aux=brillo;
      analogWrite(led1,aux);
      
    }
    if(valor>=204 && valor> 407){
      aux=brillo/2;
      analogWrite(led2,aux);
      
    }
    if(valor>=407 && valor> 611){
      aux=brillo/3;
      analogWrite(led3,aux);
    
    }
    if(valor>=611 && valor> 815){
      aux=brillo/4;
      analogWrite(led4,aux);
    
    }
    if(valor>=815 && valor> 1024){
      aux=brillo/5;
      analogWrite(led5,aux);
      estado=1;
    }
  }
  
    if(estado==1){
      brillo=255;
      brillo-=int(valor*0.25);
      if( valor> 815 && valor<=1024){
        analogWrite(led5,brillo);
      }
      if(valor >611 && valor < 815){
        analogWrite(led4,brillo);
      }
      if(valor > 408 && valor < 611){
         analogWrite(led3,brillo);      
      }
      if(valor >205 && valor < 407){
         analogWrite(led2,brillo);
      }
      if(valor >0 && valor < 204){
         analogWrite(led1,brillo);
         estado=0;
      }
      
     }*/
  
    
}

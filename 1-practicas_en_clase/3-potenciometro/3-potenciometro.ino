  // pin analogico
  int pot = 0; // pin analogico del A0
  // pines PWM
  int led1 = 8; // pin digital 10
  int led2 = 9; // pin digital 10
  int led3 = 10; // pin digital 10
  int value;

  int brillo1 = 0;
  int brillo2 = 0;
  int brillo3 = 0;

  int paso = 0;
  void setup() {
    // put your setup code here, to run once:
    pinMode(pot, INPUT); // pin analogico, se sobreentiende que es entrada siempre

    pinMode(led1, OUTPUT); // pin digital, indicamos que es salida
    pinMode(led2, OUTPUT); // pin digital, indicamos que es salida
    pinMode(led3, OUTPUT); // pin digital, indicamos que es salida
    Serial.begin(9600); // inciamos la comunicacion serial
  }


  void loop() {
    // put your main code here, to run repeatedly:
    value = analogRead(pot); // para leer el pin analogo, para recibir señal, retorna valores entre 0 - 1023
    //Serial.print("Valor del potenciometro: ");
    //Serial.println(value);


    //Serial.print("Valor de 0 a 255: ");
    //Serial.println(map(value, 0, 1023, 0, 255));

    if(value <= 341) {
      brillo1 = map(value, 0, 341, 0, 255);
      
      analogWrite(led1, brillo1); // indicamos el cambio de rango
      analogWrite(led2, 0); // indicamos el cambio de rango
      analogWrite(led3, 0); // indicamos el cambio de 
     }
    

    if(value >= 341 && value <= 341*2) {
      brillo2 = map(value, 341, (341*2), 0, 255);
      analogWrite(led1, brillo1); // indicamos el cambio de rango
      analogWrite(led2, brillo2); // indicamos el cambio de rango
      analogWrite(led3, 0); // indicamos el cambio de 
    }
    

    if(value >= 341*2 && value <= 1023) {
      brillo3 = map(value, (341*2), 1023, 0, 255);
      analogWrite(led1, brillo1); // indicamos el cambio de rango
      analogWrite(led2, brillo2); // indicamos el cambio de rango
      analogWrite(led3, brillo3); // indicamos el cambio de 
    }
} 



void bajarBrillo(int value){
    if(value <= 341) {
      // mientras no llegue al tope
      while(true){
         brillo1 = map(value, 0, 1023, 0, 255);
    
        analogWrite(led1, brillo1); // indicamos el cambio de rango
        analogWrite(led2, 0); // indicamos el cambio de rango
        analogWrite(led3, 0); // indicamos el cambio de

        if(brillo1 == 255){
          break;
        }
      } 
    }

    if(value >= 341 && value <= 341*2) {
      while(true){
        brillo2 = map(value, 0, 1023, 0, 255);
        analogWrite(led1, brillo1); // indicamos el cambio de rango
        analogWrite(led2, brillo2); // indicamos el cambio de rango
        analogWrite(led3, 0); // indicamos el cambio de
        
        if(brillo2 == 255){
          break;
        }
      }
    }


    if(value >= 341*2 && value <= 1023) {
      while(true){
        brillo3 = map(value, 0, 1023, 0, 255);
        analogWrite(led1, brillo1); // indicamos el cambio de rango
        analogWrite(led2, brillo2); // indicamos el cambio de rango
        analogWrite(led3, brillo3); // indicamos el cambio de

        if(brillo3 == 255){
        break;
        }
      }
    }
}

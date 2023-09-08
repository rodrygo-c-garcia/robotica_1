#include <Ultrasonic.h>
  //  v=d/t
  // d = v*t
  // libreria que hace ultrasonic.h
//ping y echo
Ultrasonic sensor(9,10);
int distancia;
void setup() {
    Serial.begin(9600);
    pinMode(12,OUTPUT);
     pinMode(13,OUTPUT);
}
void loop() {
  //le pasemos las disntacia en pulgadas con INC;
  //sino en centimetros;
  distancia=sensor.read();
  
  Serial.print("Distancia en CM:");
  Serial.println(distancia);
  if(distancia <= 10){
    digitalWrite(12,HIGH);
    digitalWrite(13,LOW);
  }else{
  digitalWrite(12,LOW);
      digitalWrite(13,HIGH);
  }
  delay(1000); 
 

  
}


//practica haacer un programa hacer un alerta cuando 
//alguien entrra si detecta una distancia menos a 10cm
// si es mayor o igual que este 

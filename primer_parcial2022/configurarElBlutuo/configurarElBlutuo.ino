#include <SoftwareSerial.h>

#include <Ultrasonic.h>
//trigel echo, //el vcc va a 5 voltios la conexion  
Ultrasonic sensor(12,13);


SoftwareSerial serialBt(11, 10);

void setup() {
  Serial.begin(38400); //Comenzar serial para monitor serial del IDE de Arduino
  pinMode(9, OUTPUT); digitalWrite(9, HIGH); //Poner en alto el pin configurador
  Serial.println("Estamos listos. Ingresa un comando AT:");
  serialBt.begin(38400); //Comenzar comunicación para Bluetooth
} 

void loop() {

  /*
    Comenzamos una simple comunicación
    ¿Hay respuesta del módulo? recíbelos e imprímelos en el monitor
    ¿Hay comandos ingresados por el monitor serial que mandar? envíalos
  */
  distancia=sensor.read();
  Serial.print("Distancia en CM:");
  Serial.println(distancia);

  
  if (serialBt.available())
    Serial.write(serialBt.read());

  if (Serial.available())
    serialBt.write(Serial.read());
    
}

//#include <SoftwareSerial.h>
//// #include <Ultrasonic.h>
//SoftwareSerial mySerial(10,11); //RX,Tx
//// Ultrasonic ultrasonic(11, 10);
//int distancia;
//int a=5;
//void setup() {
//  Serial.begin(9600);
//  mySerial.begin(9600);
//}
//
//void loop() {
////  distancia = ultrasonic.read();  
//  delay(1);
//  Serial.print("Distancia: ");
//  Serial.println(a);
//
//  mySerial.write(a);
//}



//ARDUINO 1
//     -> MAESTRO
//     -> SENSOR ULTRASONIC
//
//ARDUINO 2
//    -> MOTOR 2      -> MOTOR 1
//    -> LED1
//    -> ESCLAVO 
//
//
//SI SENSOR > 12CM
// MOTOR 1 Y MOTOR 2 
// PRENDIDO 
// LED 2 PRENDIDO 
// LED 2 PRENDIDO

 

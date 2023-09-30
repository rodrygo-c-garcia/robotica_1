/* Primer Parcial
 *  Led de Prendido
 *  Led A
 *  Led B
 *  Sensor Ultrasonico
 *  Potenciometro
 *  
 *  Si el potenciometro esta en el extremo derecho, entonces:
 *  El sistema se prende (Led de Prendido ON)
 *  
 *  Si el potenciometro esta en el extremo izquierdo
 *  Led prendido en OFF (Sistema apagado)
 *  
 *  Si el Sistema esta prendido
 *  Si el sensor ultrasonico detecta:
 *  Distancia mayor a 20 cm (Led A prendido y Led B apagado)
 *  Distancia menor a 10 cm (Led B prendido y Led A apagado)
 *  Distancia entre 10 y 20 cm (Led A y Led B se prenden )
 */
#include <Ultrasonic.h>

// Ultrasonic sensor
int triggerPin = 11; // disparador (emisor)
int echoPin = 12; // echo (receptor)
Ultrasonic ultrasonicSensor(triggerPin, echoPin);
int distance;

// Potentiometer
int potentiometerPinAnalog = A0;
int potentiometerValue;

// LEDs
int ledPins[] = {8, 9, 10};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // indicamos los pines como salida
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  distance = ultrasonicSensor.read(); // Obtenemos la distancia en cm
  potentiometerValue = analogRead(potentiometerPinAnalog); // Obtenemos el valor del potenciómetro entre 0 - 1023
  Serial.print("Valor del sensor (cm): ");
  Serial.println(distance);

  Serial.print("Valor del potenciómetro: ");
  Serial.println(potentiometerValue);

  if (potentiometerValue <= 1000) { // Extremo izquierdo OFF (apagado)
    apagarLeds();
  } else { // Extremo derecho ON (encendido)
    encenderLed(0);
    
    if (distance > 20) {
      encenderLed(1);
      apagarLed(2);
    } else if (distance < 10) {
      apagarLed(1);
      encenderLed(2);
    } else {
      flashLeds(1, 2, 500); // Intermitencia entre los LEDs 1 y 2
    }
  }
  delay(500);
}

void apagarLeds() {
  for (int i = 0; i < 3; i++) {
    apagarLed(i);
  }
}

void apagarLed(int ledPin) {
  digitalWrite(ledPins[ledPin], LOW);
}

void encenderLed(int ledPin) {
  digitalWrite(ledPins[ledPin], HIGH);
}

void flashLeds(int ledPin1, int ledPin2, int tiempo) {
  encenderLed(ledPin1);
  encenderLed(ledPin2);
  delay(tiempo);
  apagarLed(ledPin1);
  apagarLed(ledPin2);
  delay(tiempo);
}

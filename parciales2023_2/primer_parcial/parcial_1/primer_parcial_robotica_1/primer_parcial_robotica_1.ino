#include <Ultrasonic.h>

// Ultrasonic sensor
int triggerPin = 11;
int echoPin = 12;
Ultrasonic ultrasonicSensor(triggerPin, echoPin);
int distance;

// Potentiometer
int potentiometerPinAnalog = A0;
int potentiometerValue;

// LEDs
int ledPins[] = {8, 9, 10};

void setup() {
  Serial.begin(9600);
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  distance = ultrasonicSensor.read();
  Serial.print("Distance in cm: ");
  Serial.println(distance);

  potentiometerValue = analogRead(potentiometerPinAnalog); // valor entre 0 - 1023
  Serial.print("Potentiometer value: ");
  Serial.println(potentiometerValue);

  manageLEDs();
  delay(1000);
}

void manageLEDs() {
  if (potentiometerValue <= 1) { // Turned on towards right end
    digitalWrite(ledPins[0], HIGH);
    digitalWrite(ledPins[2], LOW);
  } else if (potentiometerValue >= 1023) { // Turned off towards left end
    digitalWrite(ledPins[1], LOW);
    digitalWrite(ledPins[0], LOW);
    digitalWrite(ledPins[2], HIGH);
  } else { // Control LED based on distance
    digitalWrite(ledPins[1], distance < 12 ? HIGH : LOW);
  }
}

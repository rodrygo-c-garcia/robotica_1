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
  // put your setup code here, to run once:
  Serial.begin(9600);
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:

}

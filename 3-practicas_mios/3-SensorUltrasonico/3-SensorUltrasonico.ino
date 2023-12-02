
int triggerPin = 11; // trigger es la salida es decir envia una onda de sonido (emisor)
int echoPin = 12; // recibe la onda de sonido (receptor)
int pingTravelTime; // para calcular el tiempo de viaje de la onda de sonido
void setup() {
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(triggerPin, HIGH); //encedemos nuestro trigger para enviar la onda de sonido
  delayMicroseconds(10); // millonesima parte de un segundo
  pingTravelTime = pulseIn(echoPin, HIGH); // recibimos el pulso u onda de sonido
  delay(25);
  digitalWrite(triggerPin, LOW);
  Serial.println(pingTravelTime);
}

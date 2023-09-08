const int redPin = 8;     // Pin para el LED rojo
const int yellowPin = 9;  // Pin para el LED amarillo
const int greenPin = 10;   // Pin para el LED verde

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Estado de semáforo: Rojo
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  delay(2000);  // Espera 2 segundos

  // Estado de semáforo: Amarillo
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, LOW);
  delay(500);  // medio segundo el amarillo

  // Estado de semáforo: Verde
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(2000);  // Espera 2 segundos

  // Estado de semáforo: Amarillo
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, LOW);
  delay(500); // Espera medio segundo
}

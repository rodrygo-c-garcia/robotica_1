float vOut;  // Declaración de una variable de tipo float llamada vOut para almacenar el valor analógico.
float vRead; // Declaración de otra variable de tipo float llamada vRead.
float analogVal;

void setup() {
  pinMode(vRead, INPUT);  // Configura el pin especificado por vRead como una entrada analógica.
  Serial.begin(9600);     // Inicia la comunicación serial a una velocidad de 9600 baudios.
}

void loop() {
  analogVal = analogRead(vRead); // Lee el valor analógico en el pin especificado por vRead y lo almacena en vOut.
  vOut = (5. * analogVal) / 1023.;
  Serial.print("Voltaje actual: ");
  Serial.print(vOut); 
  Serial.println(" Voltios");
  delay(500);               // Espera medio segundo antes de repetir el bucle.
}

  // pin analogico
  int pot = 0; // pin analogico del A0
  // pines PWM  
  int led1 = 8; // pin digital 10
  int led2 = 9; // pin digital 10
  int led3 = 10; // pin digital 10
  int value;

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
    Serial.print("Valor del potenciometro: ");
    Serial.println(value);
    analogWrite(led1, map(value, 0, 1023, 0, 255)); // indicamos el cambio de rango
    analogWrite(led2, map(value, 0, 1023, 0, 255)); // indicamos el cambio de rango
    analogWrite(led3, map(value, 0, 1023, 0, 255)); // indicamos el cambio de rango
    delay(100);
}

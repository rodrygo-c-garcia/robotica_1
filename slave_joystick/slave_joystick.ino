// CODE SLAVE
int DATOS = 0;

int der1 = 9,
    der2 = 10,
    izq1 = 11,
    izq2 = 12;

int velocidad = 120;


void setup() {
  Serial.begin(9600);
  pinMode(der1, OUTPUT);
  pinMode(der2, OUTPUT);
  pinMode(izq1, OUTPUT);
  pinMode(izq2, OUTPUT);

  // inicializamos con los motores apagados
  analogWrite(der1, 0);
  analogWrite(der2, 0);
  analogWrite(izq1, 0);
  analogWrite(izq2, 0);
}

void loop() {
  if(Serial.available() > 0){ // Si recibimos algo
    DATOS = Serial.read();
    
    // para avanzar
    if(DATOS == '1'){
      analogWrite(der1, 0);
      analogWrite(der2, velocidad);
      analogWrite(izq1, velocidad);
      analogWrite(izq2, 0);
    }
    // para retroceder
    else if(DATOS == '2'){
      analogWrite(der1, velocidad);
      analogWrite(der2, 0);
      analogWrite(izq1, 0);
      analogWrite(izq2, velocidad);
    }
    // para parar
    else if(DATOS == '5'){
      analogWrite(der1, 0);
      analogWrite(der2, 0);
      analogWrite(izq1, 0);
      analogWrite(izq2, 0);
    }
    // para girar a la derecha
    else if(DATOS == '3'){
      analogWrite(der1, 0);
      analogWrite(der2, velocidad);
      analogWrite(izq1, 0);
      analogWrite(izq2, 0);
    }
    // para girar a la izquierda
    else if(DATOS == '4'){
      analogWrite(der1, 0);
      analogWrite(der2, 0);
      analogWrite(izq1, velocidad);
      analogWrite(izq2, 0);
    }
  }

}

int der1 = 9,
    der2 = 10,
    izq1 = 11,
    izq2 = 12;
    
void setup() {
  // put your setup code here, to run once:
  pinMode(der1, OUTPUT);
  pinMode(der2, OUTPUT);
  pinMode(izq1, OUTPUT);
  pinMode(izq2, OUTPUT);
  Serial.begin(9600);  
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){ // Si recibimos algo
    char tecla = Serial.read();
    // para avanzar
    if(tecla == 'W' || tecla == 'w'){
      analogWrite(der1, 0);
      analogWrite(der2, 100);
      analogWrite(izq1, 100);
      analogWrite(izq2, 0);
    }
    // para retroceder
    else if(tecla == 'S' || tecla == 's'){
      analogWrite(der1, 100);
      analogWrite(der2, 0);
      analogWrite(izq1, 0);
      analogWrite(izq2, 100);
    }
    // para parar
    else if(tecla == 'E' || tecla == 'e'){
      analogWrite(der1, 0);
      analogWrite(der2, 0);
      analogWrite(izq1, 0);
      analogWrite(izq2, 0);
    }
    // para girar a la derecha
    else if(tecla == 'D' || tecla == 'd'){
      analogWrite(der1, 0);
      analogWrite(der2, 100);
      analogWrite(izq1, 0);
      analogWrite(izq2, 0);
    }
    // para girar a la izquierda
    else if(tecla == 'E' || tecla == 'e'){
      analogWrite(der1, 0);
      analogWrite(der2, 0);
      analogWrite(izq1, 100);
      analogWrite(izq2, 0);
    }
  }
}

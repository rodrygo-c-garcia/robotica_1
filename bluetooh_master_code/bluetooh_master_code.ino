//////MAESTRO/////
// Incluye la librería SoftwareSerial
#include <SoftwareSerial.h>

// Define los pines RX y TX del Bluetooth
#define BT_RX  10
#define BT_TX  11

// Crea un objeto SoftwareSerial llamado BTSerial
SoftwareSerial BTSerial(BT_RX, BT_TX);

void setup()
{
  // Inicializa la comunicación serie con el monitor
  Serial.begin(9600);

  // Inicializa la comunicación serie con el Bluetooth
  BTSerial.begin(9600);
}

void loop()
{
  // Si hay datos disponibles en el monitor
  if (Serial.available())
  {
    // Lee el carácter enviado por el monitor serial
    char c = Serial.read();

    // Si el carácter es '1'
    if (c == '1')
    {
      // Envía el carácter '1' al Bluetooth
      BTSerial.write('1');

      // Muestra un mensaje en el monitor
      Serial.println("Enviando '1' al esclavo");
    } else {
      // Envía el carácter '1' al Bluetooth
      BTSerial.write(c);

      // Muestra un mensaje en el monitor
      Serial.println("Enviando x al esclavo");
    }
  }
}

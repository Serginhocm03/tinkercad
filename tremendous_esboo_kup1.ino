// C++ code
const int DLed1 = 11; 
const int D1 = 12;     
const int D2 = 13;    


bool isBlinking = false;

void setup() {
  
  pinMode(DLed1, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);

  
  Serial.begin(9600);
  Serial.println("Control de luces. Usa numero del 1 al 9.");
}

void loop() {

  if (Serial.available() > 0) {
    
    char input = Serial.read();

 
    switch (input) {
      case '1': 
        digitalWrite(DLed1, HIGH);
        Serial.println("Luz verde encendida.");
        break;
      
      case '2': 
        digitalWrite(DLed1, LOW);
        Serial.println("Luz verde apagada.");
        break;

      case '3': 
        digitalWrite(D1, HIGH);
        Serial.println("Luz roja encendida.");
        break;

      case '4': 
        digitalWrite(D1, LOW);
        Serial.println("Luz roja apagada.");
        break;

      case '5': 
        digitalWrite(D2, HIGH);
        Serial.println("Luz amarilla encendida.");
        break;

      case '6': 
        digitalWrite(D2, LOW);
        Serial.println("Luz amarilla apagada.");
        break;

      case '7': 
        digitalWrite(DLed1, HIGH);
        digitalWrite(D1, HIGH);
        digitalWrite(D2, HIGH);
        Serial.println("Todas las luces encendidas.");
        break;

      case '8': 
        digitalWrite(DLed1, LOW);
        digitalWrite(D1, LOW);
        digitalWrite(D2, LOW);
        Serial.println("Todas las luces apagadas.");
        break;

      case '9': 
        isBlinking = !isBlinking;
        if (isBlinking) {
          Serial.println("Modo intermitente activado.");
        } else {
          Serial.println("Modo intermitente desactivado.");
        }
        break;

      default:
        Serial.println("Opcion no disponible.");
        break;
    }
  }


  if (isBlinking) {
    digitalWrite(DLed1, HIGH);
    digitalWrite(D1, HIGH);
    digitalWrite(D2, HIGH);
    delay(500);
    digitalWrite(DLed1, LOW);
    digitalWrite(D1, LOW);
    digitalWrite(D2, LOW);
    delay(500);
  }
}
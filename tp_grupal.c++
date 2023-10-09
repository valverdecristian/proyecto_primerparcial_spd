// C++ code
//

#define PIN_A 10
#define PIN_B 11
#define PIN_C 5
#define PIN_D 6
#define PIN_E 7
#define PIN_F 9
#define PIN_G 8

#define PIN_SUBIR 4
#define PIN_RESET 3
#define PIN_BAJAR 2

#define DISPLAY_DERECHA A4
#define DISPLAY_IZQUIERDA A5

int numeroActual = 0; // Variable para almacenar el número actual a mostrar en el display

void setup()
{
  Serial.begin(9600);
  
  //displays
  for(int i=5; i<12; i++)
  {
    pinMode(i, OUTPUT);
  }

  //pulsadores
  for(int i=2; i<5; i++)
  {
    pinMode(i, INPUT_PULLUP);
  }

  pinMode(DISPLAY_DERECHA, OUTPUT);
  pinMode(DISPLAY_IZQUIERDA, OUTPUT);
}

void loop()
{
  // Verificar si se presionó el botón de subir
  if (digitalRead(PIN_SUBIR) == LOW) {
    numeroActual++;
    delay(200);
  }

  // Verificar si se presionó el botón de bajar
  if (digitalRead(PIN_BAJAR) == LOW) {
    numeroActual--;
    delay(200);
  }

  // Verificar si se presionó el botón de reset
  if (digitalRead(PIN_RESET) == LOW) {
    numeroActual = 0;
    delay(200);
  }

  if (numeroActual > 99) {
    numeroActual = 0;
  } else if (numeroActual < 0) {
    numeroActual = 99;
  }

  // Mostrar el número actual en el display
  printDigit(numeroActual%10, DISPLAY_DERECHA);
  printDigit(numeroActual/10, DISPLAY_IZQUIERDA);
}

void apagarSegmentos(int i) {
  for(i=5; i<12; i++)
  {
    digitalWrite(i, LOW);
  }
}

void cambiarEstadoSegmento(int pinSegmento, int estado) {
  digitalWrite(pinSegmento, estado);
}

void printDigit(int numero, int display) {

  encenderDisplay(display);

  switch (numero) {
    case 0:
      cambiarEstadoSegmento(PIN_A, 1);
      cambiarEstadoSegmento(PIN_B, 1);
      cambiarEstadoSegmento(PIN_C, 1);
      cambiarEstadoSegmento(PIN_D, 1);
      cambiarEstadoSegmento(PIN_E, 1);
      cambiarEstadoSegmento(PIN_F, 1);
      cambiarEstadoSegmento(PIN_G, 0);
      break;
    case 1:
      cambiarEstadoSegmento(PIN_A, 0);
      cambiarEstadoSegmento(PIN_B, 1);
      cambiarEstadoSegmento(PIN_C, 1);
      cambiarEstadoSegmento(PIN_D, 0);
      cambiarEstadoSegmento(PIN_E, 0);
      cambiarEstadoSegmento(PIN_F, 0);
      cambiarEstadoSegmento(PIN_G, 0);
      break;
    case 2:
      cambiarEstadoSegmento(PIN_A, 1);
      cambiarEstadoSegmento(PIN_B, 1);
      cambiarEstadoSegmento(PIN_C, 0);
      cambiarEstadoSegmento(PIN_D, 1);
      cambiarEstadoSegmento(PIN_E, 1);
      cambiarEstadoSegmento(PIN_F, 0);
      cambiarEstadoSegmento(PIN_G, 1);
      break;
    case 3:
      cambiarEstadoSegmento(PIN_A, 1);
      cambiarEstadoSegmento(PIN_B, 1);
      cambiarEstadoSegmento(PIN_C, 1);
      cambiarEstadoSegmento(PIN_D, 1);
      cambiarEstadoSegmento(PIN_E, 0);
      cambiarEstadoSegmento(PIN_F, 0);
      cambiarEstadoSegmento(PIN_G, 1);
      break;
    case 4:
      cambiarEstadoSegmento(PIN_A, 0);
      cambiarEstadoSegmento(PIN_B, 1);
      cambiarEstadoSegmento(PIN_C, 1);
      cambiarEstadoSegmento(PIN_D, 0);
      cambiarEstadoSegmento(PIN_E, 0);
      cambiarEstadoSegmento(PIN_F, 1);
      cambiarEstadoSegmento(PIN_G, 1);
      break;
    case 5:
      cambiarEstadoSegmento(PIN_A, 1);
      cambiarEstadoSegmento(PIN_B, 0);
      cambiarEstadoSegmento(PIN_C, 1);
      cambiarEstadoSegmento(PIN_D, 1);
      cambiarEstadoSegmento(PIN_E, 0);
      cambiarEstadoSegmento(PIN_F, 1);
      cambiarEstadoSegmento(PIN_G, 1);
      break;
    case 6:
      cambiarEstadoSegmento(PIN_A, 1);
      cambiarEstadoSegmento(PIN_B, 0);
      cambiarEstadoSegmento(PIN_C, 1);
      cambiarEstadoSegmento(PIN_D, 1);
      cambiarEstadoSegmento(PIN_E, 1);
      cambiarEstadoSegmento(PIN_F, 1);
      cambiarEstadoSegmento(PIN_G, 1);
      break;
    case 7:
      cambiarEstadoSegmento(PIN_A, 1);
      cambiarEstadoSegmento(PIN_B, 1);
      cambiarEstadoSegmento(PIN_C, 1);
      cambiarEstadoSegmento(PIN_D, 0);
      cambiarEstadoSegmento(PIN_E, 0);
      cambiarEstadoSegmento(PIN_F, 0);
      cambiarEstadoSegmento(PIN_G, 0);
      break;
    case 8:
      cambiarEstadoSegmento(PIN_A, 1);
      cambiarEstadoSegmento(PIN_B, 1);
      cambiarEstadoSegmento(PIN_C, 1);
      cambiarEstadoSegmento(PIN_D, 1);
      cambiarEstadoSegmento(PIN_E, 1);
      cambiarEstadoSegmento(PIN_F, 1);
      cambiarEstadoSegmento(PIN_G, 1);
      break;
    case 9:
      cambiarEstadoSegmento(PIN_A, 1);
      cambiarEstadoSegmento(PIN_B, 1);
      cambiarEstadoSegmento(PIN_C, 1);
      cambiarEstadoSegmento(PIN_D, 1);
      cambiarEstadoSegmento(PIN_E, 0);
      cambiarEstadoSegmento(PIN_F, 1);
      cambiarEstadoSegmento(PIN_G, 1);
      break;
    default:
      // Si no se reconoce el número, apaga todos los segmentos
      apagarSegmentos(5);
  
  }
  delay(10);
  apagarSegmentos(5);
}

void encenderDisplay(int display)
{
  if(display == DISPLAY_DERECHA)
  {
    digitalWrite(DISPLAY_DERECHA, LOW); //low: funciona como high
    digitalWrite(DISPLAY_IZQUIERDA, HIGH);
  }
  else
  {
    digitalWrite(DISPLAY_DERECHA, HIGH);
    digitalWrite(DISPLAY_IZQUIERDA, LOW);
  }
}


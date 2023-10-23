// Este código controla un contador de 0 a 99 usando un display de 7 segmentos y botones.

// Definición de pines para los segmentos del display de 7 segmentos
#define PIN_A 10
#define PIN_B 11
#define PIN_C 5
#define PIN_D 6
#define PIN_E 7
#define PIN_F 9
#define PIN_G 8

// Definición de pines para los botones
#define SUBIR 4
#define RESET 3
#define BAJAR 2

// Definición de pines para los displays multiplexados
#define DISPLAY_DERECHA A4
#define DISPLAY_IZQUIERDA A5

// Variable que almacena el número actual mostrado en el display
int numeroActual = 0;

// variables para mantener un registro del estado anterior de los botones
// inicialmente se asume que no se presiono dichos botones
int subePrevia = 1;
int bajaPrevia = 1;
int resetPrevia = 1;

void setup()
{
  // Inicialización del puerto serie para la comunicación
  Serial.begin(9600);
  
  // Configuración de los pines del display como salidas
  for(int i=5; i<12; i++) {
    pinMode(i, OUTPUT);
  }

  // Configuración de los pines de los botones como entradas con resistencias pull-up
  pinMode(SUBIR, INPUT_PULLUP);
  pinMode(BAJAR, INPUT_PULLUP);
  pinMode(RESET, INPUT_PULLUP);

  // Configuración de los pines de los displays multiplexados como salidas
  pinMode(DISPLAY_DERECHA, OUTPUT);
  pinMode(DISPLAY_IZQUIERDA, OUTPUT);
}

void loop()
{
  
  int presionado = teclaPresionado();
  // Verificar si se presionó el botón de subir
	if(presionado == SUBIR) {
    numeroActual++;
  }
  // Verificar si se presionó el botón de bajar
  else if(presionado == BAJAR) {
    numeroActual--;
  }
  // Verificar si se presionó el botón de reset
  else if(presionado == RESET) {
    numeroActual = 0;
  }

  // Asegurarse de que el contador no supere los límites de 0 y 99
  if (numeroActual > 99) {
    numeroActual = 0;
  } else if (numeroActual < 0) {
    numeroActual = 99;
  }

  // Mostrar el número actual en el display
  printDigit(numeroActual%10, DISPLAY_DERECHA);
  printDigit(numeroActual/10, DISPLAY_IZQUIERDA);
}

// Función para apagar todos los segmentos del display
void apagarSegmentos(int i) {
  for(i=5; i<12; i++) {
    digitalWrite(i, LOW);
  }
}

// Función para mostrar un dígito en el display de 7 segmentos
void printDigit(int numero, int display) {
  // Enciende el display adecuado para la multiplexación
  encenderDisplay(display);

  // Configura los segmentos según el número que se va a mostrar
  switch (numero) {
    // (Casos para los dígitos 0-9)
    case 0:
      digitalWrite(PIN_A, 1);
      digitalWrite(PIN_B, 1);
      digitalWrite(PIN_C, 1);
      digitalWrite(PIN_D, 1);
      digitalWrite(PIN_E, 1);
      digitalWrite(PIN_F, 1);
      digitalWrite(PIN_G, 0);
      break;
    case 1:
      digitalWrite(PIN_A, 0);
      digitalWrite(PIN_B, 1);
      digitalWrite(PIN_C, 1);
      digitalWrite(PIN_D, 0);
      digitalWrite(PIN_E, 0);
      digitalWrite(PIN_F, 0);
      digitalWrite(PIN_G, 0);
      break;
    case 2:
      digitalWrite(PIN_A, 1);
      digitalWrite(PIN_B, 1);
      digitalWrite(PIN_C, 0);
      digitalWrite(PIN_D, 1);
      digitalWrite(PIN_E, 1);
      digitalWrite(PIN_F, 0);
      digitalWrite(PIN_G, 1);
      break;
    case 3:
      digitalWrite(PIN_A, 1);
      digitalWrite(PIN_B, 1);
      digitalWrite(PIN_C, 1);
      digitalWrite(PIN_D, 1);
      digitalWrite(PIN_E, 0);
      digitalWrite(PIN_F, 0);
      digitalWrite(PIN_G, 1);
      break;
    case 4:
      digitalWrite(PIN_A, 0);
      digitalWrite(PIN_B, 1);
      digitalWrite(PIN_C, 1);
      digitalWrite(PIN_D, 0);
      digitalWrite(PIN_E, 0);
      digitalWrite(PIN_F, 1);
      digitalWrite(PIN_G, 1);
      break;
    case 5:
      digitalWrite(PIN_A, 1);
      digitalWrite(PIN_B, 0);
      digitalWrite(PIN_C, 1);
      digitalWrite(PIN_D, 1);
      digitalWrite(PIN_E, 0);
      digitalWrite(PIN_F, 1);
      digitalWrite(PIN_G, 1);
      break;
    case 6:
      digitalWrite(PIN_A, 1);
      digitalWrite(PIN_B, 0);
      digitalWrite(PIN_C, 1);
      digitalWrite(PIN_D, 1);
      digitalWrite(PIN_E, 1);
      digitalWrite(PIN_F, 1);
      digitalWrite(PIN_G, 1);
      break;
    case 7:
      digitalWrite(PIN_A, 1);
      digitalWrite(PIN_B, 1);
      digitalWrite(PIN_C, 1);
      digitalWrite(PIN_D, 0);
      digitalWrite(PIN_E, 0);
      digitalWrite(PIN_F, 0);
      digitalWrite(PIN_G, 0);
      break;
    case 8:
      digitalWrite(PIN_A, 1);
      digitalWrite(PIN_B, 1);
      digitalWrite(PIN_C, 1);
      digitalWrite(PIN_D, 1);
      digitalWrite(PIN_E, 1);
      digitalWrite(PIN_F, 1);
      digitalWrite(PIN_G, 1);
      break;
    case 9:
      digitalWrite(PIN_A, 1);
      digitalWrite(PIN_B, 1);
      digitalWrite(PIN_C, 1);
      digitalWrite(PIN_D, 1);
      digitalWrite(PIN_E, 0);
      digitalWrite(PIN_F, 1);
      digitalWrite(PIN_G, 1);
      break;
    default:
      // Si no se reconoce el número, apaga todos los segmentos
      apagarSegmentos(5);
  
  }
  delay(10); // Retardo para mostrar el dígito
  apagarSegmentos(5); // Apaga los segmentos antes de cambiar al siguiente dígito
}

// Función para encender el display derecho o izquierdo para la multiplexación
void encenderDisplay(int display)
{
  if(display == DISPLAY_DERECHA) {
    digitalWrite(DISPLAY_DERECHA, LOW); // enciende (0v) = 0
    digitalWrite(DISPLAY_IZQUIERDA, HIGH); // apaga (5v) = 1
  }
  else {
    digitalWrite(DISPLAY_DERECHA, HIGH);
    digitalWrite(DISPLAY_IZQUIERDA, LOW);
  }
}

int teclaPresionado(void)// informa que pulsador se preciono, devuelve el numero que se preciono
{ 
	// variables para almacenar el estado actual de los botones
  int sube = digitalRead(SUBIR); // devuelve 0 si presiono, 1 si no presiono
  int baja = digitalRead(BAJAR);
	int reset = digitalRead(RESET);
  
  if(sube==1) { // si no presione SUBE
    subePrevia = 1; //entonces antes tampoco estaba presionada
  }
  if(baja) { // si no presione BAJA
    bajaPrevia = 1; //entonces antes tampoco estaba presionada
  }
  if(reset) { // si no presione RESET
    resetPrevia = 1;//entonces antes tampoco estaba presionada
  }
    	
  if(sube == 0 && sube != subePrevia) {
    subePrevia = sube;
    return SUBIR;
  }

  if(baja == 0 && baja != bajaPrevia) {
    bajaPrevia = baja;
    return BAJAR;
  }

  if(reset == 0 && reset != resetPrevia) {
    resetPrevia = reset;
    return RESET;
  }
  return 0; //o no presione ninguna tecla, o presione una que estaba presionada
 
}
// segunda parte: se modifica el proyecto de la parte 1 de la siguiente manera:
// se sustituye el boton RESET por un SWITCH de dos posiciones.
// dependiendo de la posición del interruptor, el display muestra o bien el contador
// (como en la parte 1) o los numeros primos en el rango del 0 al 99

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
#define BAJAR 3

// Definición de pines para los displays multiplexados
#define DISPLAY_DERECHA A4
#define DISPLAY_IZQUIERDA A5

// Define el pin del interruptor
#define INTERRUPTOR 2 

// Define el sensor de temperatura
#define SENSOR_TEMPERATURA A2

// Variable que almacena el número actual mostrado en el display
int numeroActual = 0;

// variables para mantener un registro del estado anterior de los botones
// inicialmente se asume que no se presiono dichos botones
int subePrevia = 1;
int bajaPrevia = 1;

//Motor
const int motorpin1 = 12; //pin positivo del motor 
const int motorpin2 = 13; //pin negativo del motor

// Variable para almacenar la temperatura
int temperaturaCelsius;

void setup()
{
  // Inicialización del puerto serie para la comunicación
  Serial.begin(9600);
  
  // Configuración de los pines del display como salidas
  for(int i=5; i<12; i++) {
    pinMode(i, OUTPUT);
  }

  pinMode(motorpin1, OUTPUT);
  pinMode(motorpin2, OUTPUT);

  // Configuración de los pines de los botones como entradas con resistencias pull-up
  pinMode(SUBIR, INPUT_PULLUP);
  pinMode(BAJAR, INPUT_PULLUP);

  // Configuración de los pines de los displays multiplexados como salidas
  pinMode(DISPLAY_DERECHA, OUTPUT);
  pinMode(DISPLAY_IZQUIERDA, OUTPUT);

  // Configura el pin del interruptor como entrada con resistencia pull-up
  pinMode(INTERRUPTOR, INPUT_PULLUP);
}

void loop()
{

  // Lee el estado del interruptor
  int interruptorEstado = digitalRead(INTERRUPTOR);
  
  int presionado = teclaPresionado();

  if (interruptorEstado == HIGH)
  {
    digitalWrite(motorpin2, HIGH);
    digitalWrite(motorpin1, LOW);
    // Verificar si se presionó el botón de subir
    if (presionado == SUBIR)
    {
      numeroActual++;
    }
    // Verificar si se presionó el botón de bajar
    else if (presionado == BAJAR)
    {
      numeroActual--;
    }

    // Asegurarse de que el contador no supere los límites de 0 y 99
    if (numeroActual > 99)
    {
      numeroActual = 0;
    }
    else if (numeroActual < 0)
    {
      numeroActual = 99;
    }
  }
  else if (interruptorEstado == LOW)
  {
    digitalWrite(motorpin1, HIGH);
    digitalWrite(motorpin2, LOW);
    // Si el interruptor está en la posición de primos, encontrar el siguiente primo
    if (presionado == SUBIR)
    {
      esPrimoSubir();
    }
    else if (presionado == BAJAR)
    {
      esPrimoBajar();
    }
  }

  // Muestra el número actual en el display
  printDigit(numeroActual % 10, DISPLAY_DERECHA);
  printDigit(numeroActual / 10, DISPLAY_IZQUIERDA);

  // Leer la temperatura desde el sensor TMP36
  int lecturaSensor = analogRead(SENSOR_TEMPERATURA);

  // Convertir el valor analógico a temperatura en grados Celsius
  temperaturaCelsius = map(lecturaSensor, 20, 358, -40, 120);

  // Mostrar la temperatura en el puerto serie
  Serial.print("Temperatura: ");
  Serial.print(temperaturaCelsius);
  Serial.println(" grados Celcius");



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
      break;
  
  }
  delay(10); // Retardo para mostrar el dígito
  apagarSegmentos(5); // Apaga los segmentos antes de cambiar al siguiente dígito
}

// Función para encender el display derecho o izquierdo para la multiplexación
void encenderDisplay(int display)
{
  if(display == DISPLAY_DERECHA) {
    digitalWrite(DISPLAY_DERECHA, LOW);
    digitalWrite(DISPLAY_IZQUIERDA, HIGH);
  }
  else {
    digitalWrite(DISPLAY_DERECHA, HIGH);
    digitalWrite(DISPLAY_IZQUIERDA, LOW);
  }
}

// informa que pulsador se preciono, devuelve el numero que se preciono
int teclaPresionado(void)
{ 
	// variables para almacenar el estado actual de los botones
  int sube = digitalRead(SUBIR); // devuelve 0 si presiono, 1 si no presiono
  int baja = digitalRead(BAJAR);
  
  if(sube) { // si no presione SUBE
    subePrevia = 1; //entonces antes tampoco estaba presionada
  }
  if(baja) { // si no presione BAJA
    bajaPrevia = 1; //entonces antes tampoco estaba presionada
  }
    	
  if(sube == 0 && sube != subePrevia) {
    subePrevia = sube;
    return SUBIR;
  }

  if(baja == 0 && baja != bajaPrevia) {
    bajaPrevia = baja;
    return BAJAR;
  }

  return 0; //o no presione ninguna tecla, o presione una que estaba presionada
 
}

// Esta funcion verifica si un numero entero es primo o no
// Valor de retorno: True si es primo, False si no lo es.
bool esPrimo(int numero)
{
  if (numero <= 1) {
    return false;
  }
  for (int i = 2; i * i <= numero; i++) {
    if (numero % i == 0) {
      return false;}
  }
  return true;
}

// Esta función se utiliza para incrementar el valor de 'numeroActual' y
// asegurarse de que 'numeroActual' apunte al siguiente número primo en orden ascendente
void esPrimoSubir()
{
    do
    {
        numeroActual++;
    } while (!esPrimo(numeroActual) && numeroActual <= 99);
    
    if(numeroActual >= 99)
    {
        numeroActual = 2;
    }
}

// Esta función se utiliza para disminuir el valor de 'numeroActual' y
// asegurarse de que 'numeroActual' apunte al siguiente número primo en orden descendente.
void esPrimoBajar()
{
    do
    {
        numeroActual--;
    } while (!esPrimo(numeroActual) && numeroActual >= 0);
    if(numeroActual <= 0)
    {
        numeroActual = 97;
    }
}
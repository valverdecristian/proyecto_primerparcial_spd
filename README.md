Integrantes:
Valverde, Cristian Jorge
Pazos, Axel

PARTE 1:
Contador de 0 a 99 usando un display de 7 segmentos y tres botones: SUBIR, BAJAR Y RESET. Al apretar estos botones se va mostrando los digitos segun corresponda y en caso de RESET se muestra siempre 0.

Lista de componentes de la PARTE 1:
Arduino Uno R3
Cátodo Visualizador de 7 segmentos (2)
Pulsador (3)
Resistencia 220 Ω (7)

![Contador de 0 a 99](https://github.com/valverdecristian/proyecto_primerparcial_spd/blob/main/1raParteTP.jpg)


PARTE 2:
Modificación con Interruptor Deslizante y Números Primos
Se sustituye el boton RESET por un interruptor deslizante (switch) de dos posiciones. Si el interruptor se encuentra en la posicion izquierda (HIGH) se muestra en el display los numeros del 0 al 99, sino (en la posicion derecha) se muestra por el display los numeros primos del 0 al 99.
Ademas se integra en esta parte un "Motor de aficionado" dependiendo el voltaje que recibe gira en un sentido. Este motor conecta su positivo y negativo a dos pines de salida (envian energia negativa o positiva) y el sentido de este giro depende de la posicion que tenga el Interruptor Deslizante.
Y por ultimo se implementa un "Sensor de temperatura" el cual se utiliza para medir la temperatura en su entorno y convertirla en una señal electrica o digital que se puede leer y procesar con el Arduino.

Lista de componentes de la PARTE 2:
Arduino Uno R3
Cátodo Visualizador de 7 segmentos (2)
Pulsador (2)
Resistencia 220 Ω (7)
Interruptor deslizante
Motor de aficionado
Sensor de temperatura [TMP36]


PARTE 3:
Se modifica la parte 2 y se implementa una "fotoresistencia" es un componente electrónico que cambia su resistencia eléctrica en función de la intensidad de la luz que incide sobre él. Básicamente, es un sensor de luz. Tiene una resistencia variable la cual es alta si esta en la oscuridad o va disminuyendo con la exposicion a la luz.

Lista de componentes de la PARTE 3:
Arduino Uno R3
Cátodo Visualizador de 7 segmentos (2)
Pulsador (2)
Resistencia 220 Ω (7)
Interruptor deslizante
Motor de aficionado
Sensor de temperatura [TMP36]
Fotoresistencia
Resistencia 1 kΩ


PARTE 4:
Se modifica la parte 3 y el Interruptor Deslizante ahora tiene dos funciones, prender o apagar el sistema. Cuando se prende muestra solo el contador de 0 a 99.

Lista de componentes de la PARTE 4:
Arduino Uno R3
Cátodo Visualizador de 7 segmentos (2)
Pulsador (2)
Resistencia 220 Ω (7)
Interruptor deslizante
Motor de aficionado
Sensor de temperatura [TMP36]
Fotoresistencia
Resistencia 1 kΩ
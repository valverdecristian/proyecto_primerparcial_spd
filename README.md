<h2>Integrantes:</h2>
<h2>Valverde, Cristian Jorge</h2>
<h2>Pazos, Axel</h2>

<h2>PARTE 1:</h2>
<p>Contador de 0 a 99 usando un display de 7 segmentos y tres botones: SUBIR, BAJAR Y RESET. Al apretar estos botones se va mostrando los dígitos según corresponda y en caso de RESET se muestra siempre 0.</p>
<h3>Lista de componentes de la PARTE 1:</h3>
<ul>
    <li>Arduino Uno R3</li>
    <li>Cátodo Visualizador de 7 segmentos (2)</li>
    <li>Pulsador (3)</li>
    <li>Resistencia 220 Ω (7)</li>
</ul>

![PARTE 1](https://github.com/valverdecristian/proyecto_primerparcial_spd/blob/main/img/SimuladorParte1.gif)


<h2>PARTE 2:</h2>
<p>Modificación con Interruptor Deslizante y Números Primos
Se sustituye el boton RESET por un interruptor deslizante (switch) de dos posiciones. Si el interruptor se encuentra en la posicion izquierda (HIGH) se muestra en el display los numeros del 0 al 99, sino (en la posicion derecha) se muestra por el display los numeros primos del 0 al 99.
Ademas se integra en esta parte un "Motor de aficionado" dependiendo el voltaje que recibe gira en un sentido. Este motor conecta su positivo y negativo a dos pines de salida (envian energia negativa o positiva) y el sentido de este giro depende de la posicion que tenga el Interruptor Deslizante.
Y por ultimo se implementa un "Sensor de temperatura" el cual se utiliza para medir la temperatura en su entorno y convertirla en una señal electrica o digital que se puede leer y procesar con el Arduino.</p>

<h3>Lista de componentes de la PART 2:</h3>
<ul>
    <li>Arduino Uno R3</li>
    <li>Cátodo Visualizador de 7 segmentos (2)</li>
    <li>Pulsador (2)</li>
    <li>Resistencia 220 Ω (7)</li>
    <li>Interruptor deslizante</li>
    <li>Motor de aficionado</li>
    <li>Sensor de temperatura [TMP36]</li>
</ul>

![PARTE 2](https://github.com/valverdecristian/proyecto_primerparcial_spd/blob/main/img/SimuladorParte2.gif)

<h2>PARTE 3:</h2>
<p>Se modifica la parte 2 y se implementa una "fotoresistencia" es un componente electrónico que cambia su resistencia eléctrica en función de la intensidad de la luz que incide sobre él. Básicamente, es un sensor de luz. Tiene una resistencia variable la cual es alta si esta en la oscuridad o va disminuyendo con la exposicion a la luz.</p>

<h3>Lista de componentes de la PART 3:</h3>
<ul>
    <li>Arduino Uno R3</li>
    <li>Cátodo Visualizador de 7 segmentos (2)</li>
    <li>Pulsador (2)</li>
    <li>Resistencia 220 Ω (7)</li>
    <li>Interruptor deslizante</li>
    <li>Motor de aficionado</li>
    <li>Sensor de temperatura [TMP36]</li>
    <li>Fotoresistencia</li>
    <li>Resistencia 1 kΩ</li>
</ul>


<h2>PARTE 4:</h2>
<p>Se modifica la parte 3 y el Interruptor Deslizante ahora tiene dos funciones, prender o apagar el sistema. Cuando se prende muestra solo el contador de 0 a 99.</p>

<h3>Lista de componentes de la PART 4:</h3>
<ul>
    <li>Arduino Uno R3</li>
    <li>Cátodo Visualizador de 7 segmentos (2)</li>
    <li>Pulsador (2)</li>
    <li>Resistencia 220 Ω (7)</li>
    <li>Interruptor deslizante</li>
    <li>Motor de aficionado</li>
    <li>Sensor de temperatura [TMP36]</li>
    <li>Fotoresistencia</li>
    <li>Resistencia 1 kΩ</li>
</ul>

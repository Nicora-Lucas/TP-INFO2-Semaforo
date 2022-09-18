# TP-INFO2-Semaforo
Funcionamiento de un semáforo en un cruce entre calles.

# Memoria descriptiva

El sistema ha representar es un semáforo en una intersección con capacidad de configurar la duración de cada estado (luces).  Este cambiara de estado una vez que se alcance el valor de tiempo establecido.

Cada ciclo del semáforo respetara el siguiente orden: Rojo -> Rojo y Amarillo -> Verde -> Amarillo -> Rojo.  

Por otro lado se dispondrá de un sensor de infrarrojos y botón. El primero podrá ser activado para determinar situaciones de emergencia para ambulancias bomberos, policía, etc. Luego el botón es para aumentar el tiempo de la luz de freno (Roja) del siguiente ciclo para dar mas tiempo a los peatones. Por motivos didácticos ambas situaciones serán emuladas.

# Maquina de estado

![](Assets/maquina%20de%20estado.png)

- t       : Variable incremental relacionada al tiempo.
- T_Ro    : Duración de la luz roja.
- T_RoAm  : Duración de la luz roja y amarilla simultáneamente.
- T_Ve    : Duración de la luz verde.
- T_AM    : Duración de la luz amarilla.
- EMG     : Variable "booleana" que indica si se da una situación de emergencia.
- SET     : Inicialización de la configuración.

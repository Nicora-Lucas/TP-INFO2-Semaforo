# TP-INFO2-Semaforo

``Nota: en la carpeta source files hay estan las funciones actualizadas en el read.me .``

Funcionamiento de un semáforo en un cruce entre calles.

## Memoria descriptiva

El sistema ha representar es un semáforo en una intersección con capacidad de configurar la duración de cada estado (luces).  Este cambiara de estado una vez que se alcance el valor de tiempo establecido.

Cada ciclo del semáforo respetara el siguiente orden: Rojo -> Rojo y Amarillo -> Verde -> Amarillo -> Rojo.  

Por otro lado se dispondrá de un sensor de infrarrojos y botón. El primero podrá ser activado para determinar situaciones de emergencia para ambulancias bomberos, policía, etc. Luego el botón es para aumentar el tiempo de la luz de freno (Roja) del siguiente ciclo para dar mas tiempo a los peatones. Por motivos didácticos ambas situaciones serán emuladas.

## Maquina de estado

![](Assets/maquina%20de%20estado.png)

- t       : Variable incremental relacionada al tiempo.
- T_Ro    : Duración de la luz roja.
- T_RoAm  : Duración de la luz roja y amarilla simultáneamente.
- T_Ve    : Duración de la luz verde.
- T_AM    : Duración de la luz amarilla.
- EMG     : Variable "booleana" que indica si se da una situación de emergencia.
- SET     : Inicialización de la configuración.


## Codigo Base (sin definir las tareas de las funciones)

### > Archivo cabecera (Header_Semaforo.h)


  ```c
#ifndef HEADER_SEMAFORO
#define HEADER_SEMAFORO

    #include <stdio.h>
    #include <stdlib.h>


    /// Tipos de datos


        //Etiquetas de los Estados

            typedef enum
            {
                ST_Red,
                ST_RednAmber,
                ST_Green,
                ST_Yellow,
                ST_Emergency

            }LightStates_t;



        // Estructura de datos a configurar

            typedef struct
                    {

                        char state_time[4];     // Tiempo maximo de duracion de cada estado


                        char emergency;   // se utilizara como variable booleana entre 0 y 1

                    }data_state;


        // temporizador
                char actual_time;


    ///Funciones



        // Funcion      :   Inicio

            // @Param       :   Ninguno
            // @Devuelve    :   Data_state estructura de con los tiempos de cada estado configurados

            data_state inicio(void);



        // Funcion      :   F_Red

            // @Param       :   Data_state configurada.
            //                  LightStates_t Estado en curso.

            // @Devuelve    :   LightState_t, tipo de variable enum (int) que define estados

            LightStates_t F_Red (data_state, LightStates_t color);



        // Funcion      :   F_RednAmber

            // @Param       :   Data_state configurada.
            //                  LightStates_t Estado en curso.

            // @Devuelve    :   LightState_t, tipo de variable enum (int) que define estados

            LightStates_t F_RednAmber (data_state, LightStates_t color);



        // Funcion      :   F_Green

            // @Param       :   Data_state configurada.
            //                  LightStates_t Estado en curso.

            // @Devuelve    :   LightState_t, tipo de variable enum (int) que define estados

            LightStates_t F_Green (data_state, LightStates_t color);



        // Funcion      :   F_Yellow

            // @Param       :   Data_state configurada.
            //                  LightStates_t Estado en curso.

            // @Devuelve    :   LightState_t, tipo de variable enum (int) que define estados

            LightStates_t F_Yellow (data_state, LightStates_t color);



        // Funcion      :   F_Emergency

            // @Param       :   Data_state configurada.
            //                  LightStates_t Estado en curso.

            // @Devuelve    :   LightState_t, tipo de variable enum (int) que define estados

            LightStates_t F_Emergency (data_state, LightStates_t color);




#endif // HEADER_SEMAFORO



  ```


### > Archivo __main.c__

```c

#include "config files\Header_Semaforo.h"



int main()
{

    ///Inicializacion

        data_state data_config;         // estructura

        LightStates_t estado = ST_Red;

        LightStates_t (*FuntionSelec[])(data_state, LightStates_t) = {F_Red,F_RednAmber,F_Green,F_Yellow,F_Emergency};

        data_config = inicio();

        //inicialización del temporizador
            actual_time = data_config.state_time[0];

    /// Maquina de estados/Selector de estados

        while(1) estado = (*FuntionSelec[estado])(data_config,estado);

}

```


### > Archivo de configuración (config.txt)

```bash
# Duracion de las luces (en segundos)

t_Ro 82

t_RoAm 5

t_Am 3

t_Ve 10

```

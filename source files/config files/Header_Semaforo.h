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
                extern volatile char actual_time;


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

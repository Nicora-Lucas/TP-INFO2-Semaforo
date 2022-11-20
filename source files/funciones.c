
#include "config files\Header_Semaforo.h"
#include <string.h>

    data_state inicio(void)
    {


        FILE *Fp;

        char cadena[40],*key,*val;
        unsigned char i;

        data_state aux;

        char claves[4][10] = {"t_Ro","t_RoAm","t_Ve","t_Am"};


            if ((Fp = fopen("config files/Config.txt","rb")) == NULL)
            {
                    printf("No se encontro o no se puede abrir el archivo de configuracion");
                    fclose(Fp);
                    return aux;
            }

            fgets(cadena,40,Fp);

            do
            {
              key = cadena;
              val = key;

                if ( *key != '#' && strlen(cadena) >= 0 )
                {

                    //Separo el nombre(clave) y valor

                    while ( *val != ' ')
                    {
                        val++;
                    }

                    *val = 0;
                     val++;

                    //Compruebo la clave que es, y le asigno su respectiva posicion en el vector

                    for (i = 0; i < 4; i++)
                    {
                            if (!strcmp(key,claves[i]))
                                aux.state_time[i] = (char) atoi(val);
                    }




                }

                fgets(cadena,40,Fp);

            }
            while (!feof(Fp));



            return aux;
    };


    // Funcion de Emergencia

        LightStates_t F_Emergency (data_state *aux, LightStates_t color)
            {

                if (aux->emergency)
                    {
                        /*
                            Rutina de emergencia
                        */

                        color = ST_Emergency;
                    }
                else color = ST_Red;

                return color;
            }






        ///Funciones de las luces


            // Funcion Luz roja




                LightStates_t F_Red (data_state *aux, LightStates_t color)
                {


                        if (aux->emergency) return color = ST_Emergency;


                        /*

                            Codigo para encender la luz roja y otros

                        */

                            aux->actual_time--;  //reduccion del temporizador

                        //Cambio al la siguiente luz

                            if (aux->actual_time <= 0)
                            {
                                color = ST_RednAmber;
                                aux->actual_time = aux->state_time[color];
                            }

                    return color; // si el temporizador no llega a 0, el estado se mantiene.
                }



            // Funcion Roja y amarilla




                LightStates_t F_RednAmber (data_state *aux, LightStates_t color)
                {


                        if (aux->emergency) return color = ST_Emergency;


                        /*

                            Codigo para encender la luz roja y amarilla, y otros

                        */


                        aux->actual_time--;  //reduccion del temporizador


                        //Cambio al la siguiente luz

                            if (aux->actual_time <= 0)
                            {
                                color = ST_Green;
                                aux->actual_time = aux->state_time[color];
                            }


                    return color; // si el temporizador no llega a 0, el estado se mantiene.
                }






            //Funcion luz verde



                LightStates_t F_Green (data_state *aux, LightStates_t color)
                {

                        if (aux->emergency)
                            return color = ST_Emergency;

                        /*

                            Codigo para encender la luz verde y otros

                        */


                        aux->actual_time--;  //reduccion del temporizador


                        //Cambio al la siguiente luz

                        if (aux->actual_time <= 0)
                            {
                                color = ST_Yellow;
                                aux->actual_time = aux->state_time[color];
                            }



                    return color; // si el temporizador no llega a 0, el estado se mantiene.
                }





           // Funcion luz Amarilla


                LightStates_t F_Yellow (data_state *aux, LightStates_t color)
                {



                        if (aux->emergency) return color = ST_Emergency;


                        /*

                            Codigo para encender la luz roja y otros

                        */


                        aux->actual_time--;  //reduccion del temporizador


                        //Cambio al la siguiente luz

                            if (aux->actual_time <= 0)
                            {
                                color = ST_Red;
                                aux->actual_time = aux->state_time[color];
                            }


                    return color; // si el temporizador no llega a 0, el estado se mantiene.
                }




#include "config files\Header_Semaforo.h"


    data_state inicio(void)
    {


        FILE *Fp;
        data_state aux;

        // Rutina de error

            if ((Fp = fopen("config files/Config.txt","rt")) == NULL)
            {

                if ((Fp = fopen("config files/Config.txt","wt+")) == NULL)
                {
                    fclose(Fp);
                    return aux;

                }

                aux.actual_time     = 0;

                aux.state_time[0]   = 82;
                aux.state_time[1]   =  5;
                aux.state_time[2]   =  3;
                aux.state_time[3]   = 10;

                aux.emergency       = 0;

                fwrite(&aux,sizeof(data_state),1,Fp);


            }

            fread(&aux,sizeof(data_state),1,Fp);



            return aux;
    };


        LightStates_t F_state_manager (data_state *aux, LightStates_t set_color)
            {

                //Estado de emergencia

                    if ( aux->emergency == 1 ) return set_color = ST_Emergency;

                    // El valor de data_state.emergency se modificara de forma externa.
                    // Para no frenar el ciclo.


                //Temporizador

                    aux->actual_time--;

                //Ciclo de estados


                    if (aux->state_time[set_color] <= 0)
                        {

                            // inicializacion del temporizador

                                aux->actual_time = aux->state_time[set_color];

                                //Uso punteros para asegurar que al salir de la funcion los datos no se reseten.


                            //Ultimo estado

                            LightStates_t Last_state = Cant_de_estados;

                            //Comprueba si no se encuentra en el ultimo estado

                            if ( set_color < Last_state )
                                    set_color++;        // Cambia al siguiente estado
                                else
                                    set_color = ST_Red; // resetea al primer estado no especial,
                                                        // el estado de emergencia no está en el ciclo.



                        }


                    return set_color;
                }



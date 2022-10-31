/*
#include "config files\Header_Semaforo.h"


    data_state inicio(void)
    {


        FILE *Fp;
        data_state aux;



            if ((Fp = fopen("config files/Config.txt","rt")) == NULL)
            {
                if ((Fp = fopen("config files/Config.txt","wt+")) == NULL)
                {

                    return aux;

                }

            }



            aux.actual_time = 0;

            for( int i=0; i<4; i++ ) aux.state_time[i] = i*10 + 15;
            aux.emergency   = 0;

            return aux;
    };

            LightStates_t F_Red (data_state aux){return 1;}

            LightStates_t F_RednAmber (data_state aux){return 2;}

            LightStates_t F_Green (data_state aux){return 3;}

            LightStates_t F_Yellow (data_state aux){return 4;}

            LightStates_t F_Emergency (data_state aux){return 5;}
*/

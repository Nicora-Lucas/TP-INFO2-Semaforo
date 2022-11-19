#include "config files\Header_Semaforo.h"



int main()
{

    ///Inicializacion

        data_state data_config;            // estructura
        data_state *Pconfig = &data_config;

        LightStates_t estado = ST_Red;

        data_config = inicio();

        data_config.actual_time = data_config.state_time[ST_Red];

    /// Maquina de estados/Selector de estados

        while(1){ estado = F_state_manager(Pconfig,estado);}

}



#include "config files\Header_Semaforo.h"



int main()
{

    ///Inicializacion

        data_state data_config;         // estructura

        LightStates_t estado = ST_Red;

        LightStates_t (*FuntionSelec[])(data_state, LightStates_t) = {F_Red,F_RednAmber,F_Green,F_Yellow,F_Emergency};

        data_config = inicio();

        //inicialización del temporizador
            data_config.actual_time = data_config.state_time[0];

    /// Maquina de estados/Selector de estados

        while(1) estado = (*FuntionSelec[estado])(data_config,estado);

}



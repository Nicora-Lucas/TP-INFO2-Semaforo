

# Funciones Utilizadas

```c

#include "config files\Header_Semaforo.h"
#include <string.h>

```
## Funcion de lectura del archivo de configuracion

```c

    data_state inicio(void)
    {


        FILE *Fp;

        char cadena[40],*key,*val,i;

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

```

### Funcion emergencia


```c

    // Funcion de Emergencia

        LightStates_t F_Emergency (data_state aux, LightStates_t color)
            {

                if (aux.emergency)
                    {
                        /*
                            Rutina de emergencia
                        */

                        return color = ST_Emergency;
                    }
                else color = ST_Red;
            }


```


## Luces 

A modo de ejemplo pongo una, porque las demas son practicamente iguales cambiando 1 o 2 parámetros.

```c


        ///Funciones de las luces


            // Funcion Luz roja




                LightStates_t F_Red (data_state aux, LightStates_t color)
                {
                    //reduccion del temporizador

                    while (aux.actual_time > 0)
                    {
                        if (aux.emergency) return color = ST_Emergency;


                        /*

                            Codigo para encender la luz roja y otros

                        */

                        //Cambio al la siguiente luz

                            if (aux.actual_time <= 0)
                            {
                                color = ST_RednAmber;
                                aux.actual_time = aux.state_time[color];
                            }

                        aux.actual_time--;  //reduccion del temporizador
                    }

                    return color;

                }

```


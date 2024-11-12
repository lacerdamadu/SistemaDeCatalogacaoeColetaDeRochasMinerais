#ifndef ROCHAMINERAL_H_
#define ROCHAMINERAL_H_
#include "RochaMineral.h"
#include "ListaMinerais.h"
#include <stdio.h>

void Coleta(RochaMineral* rocha, char* data, ListaMinerais* ListaT){
    int latitude, longitude;
    int ferrolita = 0, solarium = 0, aquavitae = 0, terranita = 0, calaris = 0;
    double peso;
    char categoria[20];

    printf("Peso: ");
    scanf("%lf", &peso);

    printf("Latitude: ");
    scanf("%d", &latitude);

    printf("Longitude: ");
    scanf("%d", &longitude);

    if(strcmp(ListaT->listaminerais[0].Nome, "Ferrolita") == 0){
        ferrolita = 1;
    }else if(strcmp(ListaT->listaminerais[1].Nome, "Ferrolita") == 0){
        ferrolita = 1;
    } else if(strcmp(ListaT->listaminerais[2].Nome, "Ferrolita") == 0){
        ferrolita = 1;
    }

    if(strcmp(ListaT->listaminerais[0].Nome, "Solarium") == 0){
        solarium = 1;
    }else if(strcmp(ListaT->listaminerais[1].Nome, "Solarium") == 0){
        solarium = 1;
    } else if(strcmp(ListaT->listaminerais[2].Nome, "Solarium") == 0){
        solarium = 1;
    }

    if(strcmp(ListaT->listaminerais[0].Nome, "Aquavitae") == 0){
        aquavitae = 1;
    }else if(strcmp(ListaT->listaminerais[1].Nome, "Aquavitae") == 0){
        aquavitae = 1;
    } else if(strcmp(ListaT->listaminerais[2].Nome, "Aquavitae") == 0){
        aquavitae = 1;
    }

    if(strcmp(ListaT->listaminerais[0].Nome, "Terranita") == 0){
        terranita = 1;
    }else if(strcmp(ListaT->listaminerais[1].Nome, "Terranita") == 0){
        terranita = 1;
    } else if(strcmp(ListaT->listaminerais[2].Nome, "Terranita") == 0){
        terranita = 1;
    }

    if(strcmp(ListaT->listaminerais[0].Nome, "Calaris") == 0){
        calaris = 1;
    }else if(strcmp(ListaT->listaminerais[1].Nome, "Calaris") == 0){
        calaris = 1;
    } else if(strcmp(ListaT->listaminerais[2].Nome, "Calaris") == 0){
        calaris = 1;
    }

    if(ferrolita == 1){
        if(aquavitae == 1){
            if(calaris == 1){
                strcpy(categoria, "Aquacalis");
            }else{
                strcpy(categoria, "Aquaferro");
            }
        }else if (terranita == 1){
            strcpy(categoria, "Terralis");
        }else if (solarium == 1){
            strcpy(categoria, "Solarisfer");
        }
    }else if(terranita){
        if(calaris){
            strcpy(categoria, "Terrolis");
        }

        if(solarium){
            strcpy(categoria, "Terrasol");
        }
    }else if(calaris && aquavitae){
        strcpy(categoria, "Calquer");
    }

    printf("\nCategoria: %s", categoria);
    printf("\nPeso: %.2f", peso);
    printf("\nLatitude: %d", latitude);
    printf("\nLongitude: %d", longitude);
    printf("\nData: %s", data);

    strcpy(rocha->categoria, categoria);
    rocha->peso = peso;
    rocha->latitude = latitude;
    rocha->longitude = longitude;
    strcpy(rocha->data, data);
}

#endif // ROCHAMINERAL_H_

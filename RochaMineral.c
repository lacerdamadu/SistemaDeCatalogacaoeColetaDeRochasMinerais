#include "RochaMineral.h"
#include "ListaMinerais.h"
#include <stdio.h>

void Coleta(RochaMineral* rocha, char* data){
    int latitude, longitude;
    int ferrolita = 0, solarium = 0, aquavitae = 0, terranita = 0, calaris = 0;
    double peso;
    char minerais[100];
    char mineral_1[20] = "", mineral_2[20] = "", mineral_3[20] = "";
    char categoria[20];

    getchar();
    printf("Minerais: ");
    fgets(minerais, sizeof(minerais), stdin);
    minerais[strcspn(minerais, "\n")] = '\0';
    sscanf(minerais, "%s %s %s", mineral_1, mineral_2, mineral_3);

    printf("Peso: ");
    scanf("%lf", &peso);

    printf("Latitude: ");
    scanf("%d", &latitude);

    printf("Longitude: ");
    scanf("%d", &longitude);

    if(strcmp(mineral_1, "Ferrolita") == 0){
        ferrolita = 1;
    }else if(strcmp(mineral_2, "Ferrolita") == 0){
        ferrolita = 1;
    } else if(strcmp(mineral_3, "Ferrolita") == 0){
        ferrolita = 1;
    }

    if(strcmp(mineral_1, "Solarium") == 0){
        solarium = 1;
    }else if(strcmp(mineral_2, "Solarium") == 0){
        solarium = 1;
    } else if(strcmp(mineral_3, "Solarium") == 0){
        solarium = 1;
    }

    if(strcmp(mineral_1, "Aquavitae") == 0){
        aquavitae = 1;
    }else if(strcmp(mineral_2, "Aquavitae") == 0){
        aquavitae = 1;
    } else if(strcmp(mineral_3, "Aquavitae") == 0){
        aquavitae = 1;
    }

    if(strcmp(mineral_1, "Terranita") == 0){
        terranita = 1;
    }else if(strcmp(mineral_2, "Terranita") == 0){
        terranita = 1;
    } else if(strcmp(mineral_3, "Terranita") == 0){
        terranita = 1;
    }

    if(strcmp(mineral_1, "Calaris") == 0){
        calaris = 1;
    }else if(strcmp(mineral_2, "Calaris") == 0){
        calaris = 1;
    } else if(strcmp(mineral_3, "Calaris") == 0){
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
    rintf("\n%s", data);

    strcpy(rocha->categoria, categoria);
    rocha->peso = peso;
    rocha->latitude = latitude;
    rocha->longitude = longitude;
    strcpy(rocha->data, data);
}

#include "RochaMineral.h"
#include <stdio.h>
#include <string.h>


void InicializaRocha(RochaMineral* Rocha, double Peso, ListaMinerais ListaMin, double Latitude, double Longitude, char DataC){
    
    ClassificaRocha(Rocha, ListaMin);

    setPesoRocha(Rocha, Peso);
    setLatitude(Rocha, Latitude);
    setLongitude(Rocha, Longitude);
    setData(Rocha, DataC);
    /*double Latitude, Longitude;
    double Peso;
    char minerais[100];
    char mineral_1[20] = "", mineral_2[20] = "", mineral_3[20] = "";
    char categoria[20];*/

    /*getchar();
    printf("Minerais: ");
    fgets(minerais, sizeof(minerais), stdin);
    minerais[strcspn(minerais, "\n")] = '\0';
    sscanf(minerais, "%s %s %s", mineral_1, mineral_2, mineral_3);

    printf("Peso: ");
    scanf("%lf", &Peso);

    printf("Latitude: ");
    scanf("%lf", &Latitude);

    printf("Longitude: ");
    scanf("%lf", &Longitude);*/

    /*if(strcmp(ListaMin[0].listaminerais->Nome, "Ferrolita") == 0){
        ferrolita = 1;
    }else if(strcmp(ListaMin[1].listaminerais->Nome, "Ferrolita") == 0){
        ferrolita = 1;
    } else if(strcmp(ListaMin[2].listaminerais->Nome, "Ferrolita") == 0){
        ferrolita = 1;
    }*/

    /*if(strcmp(ListaMin[0].listaminerais->Nome, "Solarium") == 0){
        solarium = 1;
    }else if(strcmp(ListaMin[1].listaminerais->Nome, "Solarium") == 0){
        solarium = 1;
    } else if(strcmp(ListaMin[2].listaminerais->Nome, "Solarium") == 0){
        solarium = 1;
    }*/

    /*if(strcmp(ListaMin[0].listaminerais->Nome, "Aquavitae") == 0){
        aquavitae = 1;
    }else if(strcmp(ListaMin[1].listaminerais->Nome, "Aquavitae") == 0){
        aquavitae = 1;
    } else if(strcmp(ListaMin[2].listaminerais->Nome, "Aquavitae") == 0){
        aquavitae = 1;
    }*/

    /*if(strcmp(ListaMin[0].listaminerais->Nome, "Terranita") == 0){
        terranita = 1;
    }else if(strcmp(ListaMin[1].listaminerais->Nome, "Terranita") == 0){
        terranita = 1;
    } else if(strcmp(ListaMin[2].listaminerais->Nome, "Terranita") == 0){
        terranita = 1;
    }*/  

    /*if(strcmp(ListaMin[0].listaminerais->Nome, "Calaris") == 0){
        calaris = 1;
    }else if(strcmp(ListaMin[1].listaminerais->Nome, "Calaris") == 0){
        calaris = 1;
    } else if(strcmp(ListaMin[2].listaminerais->Nome, "Calaris") == 0){
        calaris = 1;
    }*/

    /*if(ferrolita == 1){
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


    strcpy(Rocha->Categoria, categoria);

    Rocha->Peso = Peso;
    Rocha->Latitude = Latitude;
    Rocha->Longitude = Longitude;
    strcpy(Rocha->DataC, data); */

    char res;
    printf("Imprimir Rocha? (s/n) ");
    getchar();
    scanf("%c", &res);
    if(res == 's'){
        ImprimeRocha(Rocha);
    }

}

void ClassificaRocha(RochaMineral *Rocha, ListaMinerais *ListaMin){
    int ferrolita = 0, solarium = 0, aquavitae = 0, terranita = 0, calaris = 0;
    char categoria[20];
    for(int i = 0; i < MaxTam; i++){
    if ((strcmp(ListaMin->listaminerais[i].Nome, "Ferrolita") == 0)){
        ferrolita = 1;
    }
   }
    for(int i = 0; i < MaxTam; i++){
        if ((strcmp(ListaMin->listaminerais[i].Nome, "Solarium") == 0)){
            solarium = 1;
        }
   }


   for(int i = 0; i < MaxTam; i++){
        if ((strcmp(ListaMin->listaminerais[i].Nome, "Aquavitae") == 0)){
            aquavitae = 1;
        }
   }


    for(int i = 0; i < MaxTam; i++){
        if ((strcmp(ListaMin->listaminerais[i].Nome, "Terranita") == 0)){
            terranita = 1;
        }
   }


    for(int i = 0; i < MaxTam; i++){
        if ((strcmp(ListaMin->listaminerais[i].Nome, "Calaris") == 0)){
            calaris = 1;
        }

   }   


    //printf("%d %d %d %d %d\n", ferrolita, solarium, aquavitae, calaris, terranita);

   if(ferrolita && !solarium && !aquavitae && !calaris && !terranita){
        strcpy(categoria, "Ferrom");

   } 
   
   else if (!ferrolita && solarium && !aquavitae && !calaris && !terranita){
        strcpy(categoria, "Solaris");
   } 
   
   else if(ferrolita && !solarium && aquavitae && !calaris && !terranita){ //3
        strcpy(categoria, "Aquaferro");
   } 
   
   else if(!ferrolita && !solarium && !aquavitae && calaris && terranita){ //4
        strcpy(categoria, "Terrolis");
   } 
   
   else if(!ferrolita && solarium && !aquavitae && !calaris && terranita){ //5
        strcpy(categoria, "Terrasol");
   } 
   
   else if(!ferrolita && !solarium && aquavitae && !calaris && terranita){ //6
        strcpy(categoria, "Aquaterra");
   } 
   
   else if(!ferrolita && !solarium && aquavitae && calaris && !terranita){ //7
        strcpy(categoria, "Calquer");
   } 
   
   else if(ferrolita && solarium && !aquavitae && !calaris && !terranita){ //8
        strcpy(categoria, "Solarisfer");
   } 
   
   else if(ferrolita && !solarium && !aquavitae && !calaris && terranita){ //9
        strcpy(categoria, "Terralis");
   } 
   
   else if(ferrolita && !solarium && aquavitae && calaris && !terranita){ //10
        strcpy(categoria, "Aquacalis");
   }

   strcpy(Rocha->Categoria, categoria);

}

void ImprimeRocha(RochaMineral *Rocha){
    printf("\nCategoria: %s", Rocha->Categoria);
    printf("\nPeso: %.2lf", Rocha->Peso);
    printf("\nLatitude: %lf", Rocha->Latitude);
    printf("\nLongitude: %lf", Rocha->Longitude);
}

void setPesoRocha(RochaMineral *Rocha, double Peso){
    Rocha->Peso = Peso;
}
double getPesoRocha(RochaMineral *Rocha){
    return(Rocha->Peso);
}

void setLatitude(RochaMineral *Rocha, double Latitude){
    Rocha->Latitude = Latitude;
}
double getLatitude(RochaMineral *Rocha){
    return(Rocha->Latitude);
}

void setLongitude(RochaMineral *Rocha, double Longitude){
    Rocha->Longitude = Longitude;
}
double getLongitude(RochaMineral *Rocha){
    return(Rocha->Longitude);
}

void setData(RochaMineral Rocha, char DataC){

    strcpy(Rocha->DataC, DataC);
}
char* getData(RochaMineral *Rocha){
    return(Rocha->DataC);

}

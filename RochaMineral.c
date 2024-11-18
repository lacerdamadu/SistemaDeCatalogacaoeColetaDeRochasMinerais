#include "RochaMineral.h"
#include <stdio.h>
#include <string.h>


void InicializaRocha(RochaMineral* Rocha, double Peso, ListaMinerais* ListaMin, double Latitude, double Longitude, char* DataC){
    
    ClassificaRocha(Rocha, ListaMin);

    setPesoRocha(Rocha, Peso);
    setLatitude(Rocha, Latitude);
    setLongitude(Rocha, Longitude);
    setData(Rocha, DataC);

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
    printf("\nPeso: %.0lf", Rocha->Peso);
    printf("\nLatitude: %lf", Rocha->Latitude);
    printf("\nLongitude: %lf\n", Rocha->Longitude);
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

void setData(RochaMineral *Rocha, char* DataC){

    strcpy(Rocha->DataC, DataC);
}
char* getData(RochaMineral *Rocha){
    return(Rocha->DataC);

}
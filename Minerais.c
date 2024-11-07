#include "Minerais.h"
#include <stdio.h>
#include <string.h>

void PreencheMineral(Minerais *Mineral, char* VetorRochas){
    float Dureza, Reatividade;
    Cor Cores;
    char* Nome;
    int tamVetor = len(VetorRochas);
    for(int i=0;i<tamVetor;i++){
        strcpy(Nome, VetorRochas[i]);
        if(strcmp(VetorRochas[i], "Ferrolita")==0){
            Dureza = 0.5;
            Reatividade = 0.7;
            Cores = 1;
        }
        if(strcmp(VetorRochas[i], "Solarium")==0){
            Dureza = 0.9;
            Reatividade = 0.2;
            Cores = 2;
        }
        if(strcmp(VetorRochas[i], "Aquavitae")==0){
            Dureza = 0.5;
            Reatividade = 0.8;
            Cores = 3;
        }
        if(strcmp(VetorRochas[i], "Terranita")==0){
            Dureza = 0.7;
            Reatividade = 0.6;
            Cores = 4;
        }
         if(strcmp(VetorRochas[i], "Calaris")==0){
            Dureza = 0.6;
            Reatividade = 0.5;
            Cores = 5;
        }
        InicializaMineral(Mineral, Nome, Dureza, Reatividade, Cores);
    }
}
void InicializaMineral(Minerais *Mineral, char* Nome, float Dureza, float Reatividade, Cor Cores){
    setNomeMineral(Mineral, Nome);
    setDureza(Mineral, Dureza);
    setReatividade(Mineral, Reatividade);
    setCor(Mineral, Cores);
    AdicionaRocha(Minerais Mineral);
}

void setNomeMineral(Minerais *Mineral, char* Nome){
    strcpy(Mineral->Nome, Nome);
}
char* getNomeMineral(Minerais *Mineral){
    return(Mineral->Nome);
}

void setDureza(Minerais *Mineral, float Dureza){
    Mineral->Dureza = Dureza;
}
float getDureza(Minerais *Mineral){
    return(Mineral->Dureza);
}

void setReatividade(Minerais *Mineral, float Reatividade){
    Mineral->Reatividade = Reatividade;
}
float getReatividade(Minerais *Mineral){
    return(Mineral->Reatividade);
}

void setCores(Minerais *Mineral, Cor Cores){
    Mineral->Cores = Cores;
}
Cor getCores(Minerais *Mineral){
    return(Mineral->Cores);
}
#include "Minerais.h"
#include <stdio.h>
#include <string.h>

void PreencheMineral(Minerais *Mineral){
    float Dureza, Reatividade;
    Cor Cores;
    char* Nome;
    if(strcmp(Nome, "Ferrolita")==0){
        Dureza = 0.5;
        Reatividade = 0.7;
        Cores = 1;
    }
    else if(strcmp(Nome, "Solarium")==0){
        Dureza = 0.9;
        Reatividade = 0.2;
        Cores = 2;
    }
    else if(strcmp(Nome, "Aquavitae")==0){
        Dureza = 0.5;
        Reatividade = 0.8;
        Cores = 3;
    }
    else if(strcmp(Nome, "Terranita")==0){
        Dureza = 0.7;
        Reatividade = 0.6;
        Cores = 4;
    }
    else if(strcmp(Nome, "Calaris")==0){
        Dureza = 0.6;
        Reatividade = 0.5;
        Cores = 5;
    }
    InicializaMineral(Mineral, Nome, Dureza, Reatividade, Cores);
}

void InicializaMineral(Minerais *Mineral, char* Nome, float Dureza, float Reatividade, Cor Cores){
    setNomeMineral(Mineral, Nome);
    setDureza(Mineral, Dureza);
    setReatividade(Mineral, Reatividade);
    setCor(Mineral, Cores);
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
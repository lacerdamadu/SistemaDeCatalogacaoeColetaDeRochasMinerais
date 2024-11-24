#include "Minerais.h"
#include <stdio.h>
#include <string.h>

void PreencheMineral(Minerais *Mineral, char *Nome){/*Esta função recebe o nome de um Mineral e 
                                                    de acordo com essa informação ela preenche os campos Dureza,
                                                    Reatividade e Cor.*/
    double Dureza, Reatividade;
    Cor Cores;
    if(strcmp(Nome, "Ferrolita")==0||strcmp(Nome, "Ferrolita\n")==0){
        Dureza = 0.5;
        Reatividade = 0.7;
        Cores = Acizentado;
    }
    else if(strcmp(Nome, "Solarium")==0||strcmp(Nome, "Solarium\n")==0){
        Dureza = 0.9;
        Reatividade = 0.2;
        Cores = Amarelo;
    }
    else if(strcmp(Nome, "Aquavitae")==0|| strcmp(Nome, "Aquavitae\n")==0){
        Dureza = 0.5;
        Reatividade = 0.8;
        Cores = Azulado;
    }
    else if(strcmp(Nome, "Terranita")==0||strcmp(Nome, "Terranita\n")==0){
        Dureza = 0.7;
        Reatividade = 0.6;
        Cores = Marrom;
    }
    else if(strcmp(Nome, "Calaris")==0||strcmp(Nome, "Calaris\n")==0){
        Dureza = 0.6;
        Reatividade = 0.5;
        Cores = Vermelho;
    }
    InicializaMineral(Mineral, Nome, Dureza, Reatividade, Cores);
}

Minerais InicializaMineral(Minerais *Mineral, char* Nome, double Dureza, double Reatividade, Cor Cores){
    setNomeMineral(Mineral, Nome);
    setDureza(Mineral, Dureza);
    setReatividade(Mineral, Reatividade);
    setCores(Mineral, Cores);
    return(*Mineral);
}

void setNomeMineral(Minerais *Mineral, char* Nome){
    strcpy(Mineral->Nome, Nome);
}
char* getNomeMineral(Minerais *Mineral){
    return(Mineral->Nome);
}

void setDureza(Minerais *Mineral, double Dureza){
    Mineral->Dureza = Dureza;
}
double getDureza(Minerais *Mineral){
    return(Mineral->Dureza);
}

void setReatividade(Minerais *Mineral, double Reatividade){
    Mineral->Reatividade = Reatividade;
}
double getReatividade(Minerais *Mineral){
    return(Mineral->Reatividade);
}

void setCores(Minerais *Mineral, Cor Cores){
    Mineral->Cores = Cores;
}
Cor getCores(Minerais *Mineral){
    return(Mineral->Cores);
}

#include "Sonda.h"
#include <stdio.h>
#include <string.h>

void InicializaSonda(Sonda *NovaSonda, double Latitude, double Longitude,
 int PesoMax, int Velocidade, int Combustivel, int Identificador){
    NovaSonda->Latitude = Latitude;
    NovaSonda->Longitude = Longitude;
    NovaSonda->EstaLigada = 0;
    CriaListaRocha(&NovaSonda->Compartimentos, PesoMax);
    NovaSonda->Velocidade = Velocidade;
    NovaSonda->Combustivel = Combustivel;
    NovaSonda->Identificador = Identificador;

}

void LigaSonda(Sonda *SondaDes){
    SondaDes->EstaLigada = 1;
}

void DesligaSonda(Sonda *Sondalig){
    Sondalig->EstaLigada = 0;
}

double MoveSonda(Sonda *SondaMov, double Latitude, double Longitude/*, int Velocidade, int Combustivel*/){

    if (!SondaMov->EstaLigada){
        LigaSonda(SondaMov);
    }

    SondaMov->Latitude = Latitude;
    SondaMov->Longitude = Longitude;

}

#include "Sonda.h"


#include <math.h>
#include <stdio.h>
#include <string.h>

void InicializaSonda(Sonda *NovaSonda, double Latitude, double Longitude,
 int PesoMax, int Velocidade, int Combustivel, int Identificador){
    NovaSonda->Latitude = Latitude;
    NovaSonda->Longitude = Longitude;
    NovaSonda->EstaLigada = 0;
    CriaListaRocha(&NovaSonda->CompartmentoS, PesoMax);
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

double MoveSonda(Sonda *SondaMov, double Latitude, double Longitude){

    if (!SondaMov->EstaLigada){
        LigaSonda(SondaMov);
    }
    
    SondaMov->Latitude = Latitude;
    SondaMov->Longitude = Longitude;
    
}

double CalculaDist(Sonda Sonda, RochaMineral Rocha){
    double DistTotal;
    double DistLat, DistLong, ResultRaiz;

    
    if(Sonda.Latitude > Rocha.Latitude){
        DistLat = Sonda.Latitude - Rocha.Latitude;
    } else {
        DistLat = Rocha.Latitude - Sonda.Latitude;
    }

    if(Sonda.Longitude > Rocha.Longitude){
        DistLong = Sonda.Longitude - Rocha.Longitude;
    } else {
        DistLong = Rocha.Longitude - Sonda.Longitude;
    }

    ResultRaiz = pow(DistLat, 2) + pow(DistLong, 2);

    DistTotal = sqrt(ResultRaiz);

    return(DistTotal);
    
}
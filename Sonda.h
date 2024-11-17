#ifndef SONDA_H_
#define SONDA_H_

#include "Compartimento.h"

typedef struct {
    int Identificador;
    Compartimento CompartmentoS;
    double Latitude;
    double Longitude;
    int EstaLigada;
    int Velocidade;
    int Combustivel;
} Sonda;

void InicializaSonda(Sonda *NovaSonda, double Latitude, double Longitude,
 int PesoMax, int Velocidade, int Combustivel, int Identificador);

void LigaSonda(Sonda *SondaDes);

void DesligaSonda(Sonda *Sondalig);

double MoveSonda(Sonda *SondaMov, double Latitude, double Longitude);

double CalculaDist(Sonda Sonda, RochaMineral Rocha);

#endif
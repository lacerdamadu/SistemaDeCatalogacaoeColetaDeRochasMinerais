#ifndef LISTASONDAS_H_
#define LISTASONDAS_H_

#include "Sonda.h"

typedef struct Celula_S* Apontador;

typedef struct Celula_S {
    Sonda Sonda;
    struct Celula_S* pProx;
} TCelula_S;


typedef struct {
     Apontador pPrimeiro;
     Apontador pUltimo;
} TSondas;

void FazListaVazia(TSondas* Sondas);
void InsereSonda(TSondas* Sondas, Sonda* sonda);
int RetiraSonda(TSondas* Sondas, int retirar);
void ImprimeSonda(TSondas* Sondas);
 
#endif
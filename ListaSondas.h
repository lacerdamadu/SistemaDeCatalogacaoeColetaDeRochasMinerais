#ifndef LISTASONDAS_H_
#define LISTASONDAS_H_

#include "Sonda.h"

typedef struct Celula_S* Apontador;

typedef struct Celula_S {
    Sonda Sonda;
    struct Celula* pProx;
} TCelula_S;


typedef struct {
     Apontador pPrimeiro;
     Apontador pUltimo;
} TSondas;

void FazListaVazia(TSondas* Sondas);
void Insere(TSondas* Sondas, Sonda* sonda);
int Retira(TSondas* Sondas, int retirar);
 
#endif


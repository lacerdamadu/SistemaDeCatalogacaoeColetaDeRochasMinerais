#include "Compartimento.h"
#include "Sonda.h"

typedef struct {
    Sonda sonda
} TSonda;

typedef struct Celula_S* Apontador;

typedef struct Celula_S {
    TSonda Sondas;
    struct Celula* pProx;
} TCelula_S;


typedef struct {
     Apontador pPrimeiro;
     Apontador pUltimo;
} TSondas;

void FazListaVazia(TSondas* Sondas);
void Insere(TSondas* Sondas, TSonda* sonda);
int Retira(TSondas* Sondas, int retirar);

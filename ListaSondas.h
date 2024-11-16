#include "Compartimento.h"

typedef struct {
    int Identificador;
    Compartimento compartimentos;
    double Latitude;
    double Longitude;
    int EstaLigada;
    int Velocidade;
    int Combustivel;
    int PesoMax;
} TSonda;

typedef struct Celula_S* Apontador;

typedef struct Celula_S {
    TSonda Sonda;
    struct Celula* pProx;
} TCelula_S;


typedef struct {
     Apontador pPrimeiro;
     Apontador pUltimo;
} TSondas;

void FazListaVazia(TSondas* Sondas);
void Insere(TSondas* Sondas, TSonda* sonda);
int Retira(TSondas* Sondas, int retirar);

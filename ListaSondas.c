#include "ListaSondas.h"
#include "Compartimento.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void FazListaVazia(TSondas* sonda)
{
     sonda->pPrimeiro = (Apontador) malloc(sizeof(TCelula_S));
     sonda->pUltimo = sonda->pPrimeiro;
     sonda->pPrimeiro->pProx = NULL;
}

void Insere(TSondas* Sondas,TSonda* sonda){
     Sondas->pUltimo->pProx = (Apontador) malloc(sizeof(TCelula_S));
     Sondas->pUltimo = Sondas->pUltimo->pProx;
     Sondas->pUltimo->Sonda = *sonda;
     Sondas->pUltimo->pProx = NULL;
}

int Retira(TSondas* Sondas, int retirar){
    TCelula_S* pAux;
    pAux = Sondas->pPrimeiro;
    TCelula_S* p_anterior = NULL;

    while (pAux != NULL){
        if (pAux->Sonda.Identificador == retirar){
            if (p_anterior == NULL){
                Sondas->pPrimeiro = pAux->pProx;
            } else{
                p_anterior->pProx = pAux->pProx;
            }
            if (pAux->pProx == NULL){
                Sondas->pUltimo = p_anterior;
            }
            free(pAux);
            return 1;
        }
        p_anterior = pAux;
        pAux = pAux->pProx;
    }
}


void Imprime(TSondas* Sonda, TSonda* sonda) {
    TCelula_S* pAux;
    pAux = Sonda->pPrimeiro->pProx;
    if (pAux == NULL) {
        return;
    }
    while (pAux != NULL) {
        printf("Identificador: %d\n", pAux->Sonda.Identificador);
        printf("Latitude: %d\n", pAux->Sonda.Latitude);
        printf("Longitude: %d\n", pAux->Sonda.Longitude);
        printf("Peso: %d\n", pAux->Sonda.PesoMax);
        printf("Velocidade: %d\n", pAux->Sonda.Velocidade);
        printf("Ligado: %d\n", pAux->Sonda.EstaLigada);
        printf("Combustivel: %d\n", pAux->Sonda.Combustivel);
        printf("Compartimentos: %d\n", pAux->Sonda.compartimentos);
        pAux = pAux->pProx;
    }
}


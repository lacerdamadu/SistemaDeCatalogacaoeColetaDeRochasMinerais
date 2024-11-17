#include "ListaSondas.h"
#include "Sonda.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void FazListaVazia(TSondas* Sondas)
{
     Sondas->pPrimeiro = (Apontador) malloc(sizeof(TCelula_S));
     Sondas->pUltimo = Sondas->pPrimeiro;
     Sondas->pPrimeiro->pProx = NULL;
}

void Insere(TSondas* Sondas,TSonda* sonda){
     Sondas->pUltimo->pProx = (Apontador) malloc(sizeof(TCelula_S));
     Sondas->pUltimo = Sondas->pUltimo->pProx;
     Sondas->pUltimo->Sondas = *sonda;
     Sondas->pUltimo->pProx = NULL;
}

int Retira(TSondas* Sondas, int retirar){
    TCelula_S* pAux;
    pAux = Sondas->pPrimeiro->pProx;
    TCelula_S* p_ant;
    p_ant = Sondas->pPrimeiro;

    while (pAux != NULL){
        if (pAux->Sondas.sonda.Identificador == retirar){
            if (p_ant == NULL){
                Sondas->pPrimeiro = pAux->pProx;
            } else{
                p_ant->pProx = pAux->pProx;
            }
            if (pAux->pProx == NULL){
                Sondas->pUltimo = p_ant;
            }
            free(pAux);
            return 1;
        }
        p_ant = pAux;
        pAux = pAux->pProx;
    }
}


void Imprime(TSondas* Sondas, TSonda* sonda) {
    TCelula_S* pAux;
    pAux = Sondas->pPrimeiro->pProx;
    if (pAux == NULL) {
        return;
    }
    while (pAux != NULL) {
        printf("Identificador: %d\n", pAux->Sondas.sonda.Identificador);
        printf("Latitude: %lf\n", pAux->Sondas.sonda.Latitude);
        printf("Longitude: %lf\n", pAux->Sondas.sonda.Longitude);
        printf("Peso: %d\n", pAux->Sondas.sonda.PesoMax);
        printf("Velocidade: %d\n", pAux->Sondas.sonda.Velocidade);
        printf("Ligado: %d\n", pAux->Sondas.sonda.EstaLigada);
        printf("Combustivel: %d\n", pAux->Sondas.sonda.Combustivel);
        printf("Compartimentos: %d\n", pAux->Sondas.sonda.compartimentos);
        printf("\n");
        pAux = pAux->pProx;
    }
}


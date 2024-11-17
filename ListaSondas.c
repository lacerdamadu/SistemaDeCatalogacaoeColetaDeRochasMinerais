#include "ListaSondas.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void FazListaVazia(TSondas* sonda)
{
     sonda->pPrimeiro = (Apontador) malloc(sizeof(TCelula_S));
     sonda->pUltimo = sonda->pPrimeiro;
     sonda->pPrimeiro->pProx = NULL;
}

void InsereSonda(TSondas* Sondas, Sonda* sonda){

     Sondas->pUltimo->pProx = (Apontador) malloc(sizeof(TCelula_S));
     Sondas->pUltimo = Sondas->pUltimo->pProx;
     Sondas->pUltimo->Sonda = *sonda;
     Sondas->pUltimo->pProx = NULL;
}

int RetiraSonda(TSondas* Sondas, int retirar){
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


int ImprimeSonda(TSondas* Sondas){
    TCelula_S* pAux;
    int passagem = 0;
    pAux = Sondas->pPrimeiro->pProx;
    if (pAux == NULL) {
        return 0;
    }
    while (pAux != NULL) {
        ImprimiLista(&pAux->Sonda.CompartmentoS);
        pAux = pAux->pProx;
    }
    return 1;
}
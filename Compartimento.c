#include "RochaMineral.h"
#include "Compartimento.h"
#include <stdio.h>
#include <string.h>

void CriaListaRocha(Compartimento *lista, int PesoMax){
    lista->primeiro = (Celula*) malloc(sizeof(Celula));
    lista->ultimo = lista->primeiro;
    lista->primeiro->pProx = NULL;
    lista->PesoMax = PesoMax;
}

int TamanhoListaRocha(Compartimento *lista){
    int contador;
    if (VerificaListaVazia(lista)){
        return 0;
    }
    Celula* pCelulaDesejada;
    pCelulaDesejada = lista->primeiro->pProx;
    while(pCelulaDesejada!=NULL){
        contador ++;
        pCelulaDesejada = pCelulaDesejada->pProx;
    }
    return contador;
}

int VerificaListaVazia(Compartimento *lista){
    return(lista->primeiro==lista->ultimo);
}

void ImprimiLista(Compartimento *lista){
    Celula* pCelulaDesejada;
    pCelulaDesejada = lista->primeiro->pProx;
    while (pCelulaDesejada != NULL){
    printf("%s\n", pCelulaDesejada->rocha.Categoria);
    pCelulaDesejada = pCelulaDesejada->pProx; /* próxima célula */
    }
}

double PesoAtual(Compartimento *lista){
    double Peso = 0;
    if(VerificaListaVazia(lista)){
        return 0;
    }
    Celula* pCelulaDesejada;
    pCelulaDesejada = lista->primeiro->pProx;
    while (pCelulaDesejada != NULL){
        Peso += (pCelulaDesejada->rocha.Peso);
        pCelulaDesejada = pCelulaDesejada->pProx;
    }
    return Peso;
}

void TrocaRocha(Compartimento *lista, RochaMineral *rocha){
    Celula* pCelulaDesejada;
    pCelulaDesejada =  lista->primeiro->pProx;
    while(strcmp(pCelulaDesejada->rocha.Categoria, rocha->Categoria)!=0){
        pCelulaDesejada = pCelulaDesejada->pProx;
    }
    (pCelulaDesejada->rocha.Peso) = (rocha->Peso);
}

int InsereRocha(Compartimento *lista, RochaMineral *rocha, int PesoMax){
    int Peso = PesoAtual(lista);
    Peso += (rocha->Peso);
    if(Peso>PesoMax){
        return 0;
    }
    lista->ultimo->pProx = (Celula*) malloc(sizeof(Celula));
    lista->ultimo = lista->ultimo->pProx;
    lista->ultimo->rocha = *rocha;
    lista->ultimo->pProx = NULL;
    return 1;
}

int RemoveRocha(Compartimento *lista, char* nomerocha){
    if (VerificaListaVazia(lista)){
        return 0;
    }
    Celula* pDesejada;
    Celula* pAnterior;
    pDesejada = lista->primeiro->pProx;
    while((strcmp(pDesejada->rocha.Categoria,nomerocha))!=0){
        pAnterior = pDesejada;
        pDesejada = pDesejada->pProx;
    }
    Celula* pAux = pDesejada;
    pAnterior->pProx = pDesejada->pProx;
    free(pAux);
    return 1;
}
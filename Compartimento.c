#include "RochaMineral.h"
#include "Compartimento.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void CriaListaRocha(Compartimento* lista, int PesoMax){
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
    Celula* pAux;
    pAux = lista->primeiro->pProx;
    while(pAux!=NULL){
        contador ++;
        pAux = pAux->pProx;
    }
    return contador;
}

int VerificaListaVazia(Compartimento *lista){
    return(lista->primeiro==lista->ultimo);
}

void ImprimiLista(Compartimento *lista){
    printf("entrou no imprime lista\n");
    int passagem = 0;
    Celula* pAux;
    pAux = lista->primeiro->pProx;
    while(pAux != NULL){
    passagem++; printf("entrou no while imprime lista %d vez\n", passagem);
    printf("%s %d\n", pAux->rocha.Categoria, pAux->rocha.Peso);
    pAux = pAux->pProx; /* próxima célula */
    }
}

double PesoAtual(Compartimento *lista){
    double Peso = 0;
    if(VerificaListaVazia(lista)){
        return 0;
    }
    Celula* pAux;
    pAux = lista->primeiro->pProx;
    while (pAux != NULL){
        Peso += (pAux->rocha.Peso);
        pAux = pAux->pProx;
    }
    return Peso;
}

void TrocaRocha(Compartimento *lista, RochaMineral *rocha){
    Celula* pAux;
    pAux =  lista->primeiro->pProx;
    while(strcmp(pAux->rocha.Categoria, rocha->Categoria)!=0){
        pAux = pAux->pProx;
    }
    (pAux->rocha.Peso) = (rocha->Peso);
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

RochaMineral *RemoveRocha(Compartimento *lista, RochaMineral *rocha){
    if (VerificaListaVazia(lista)){
        return 0;
    }
    Celula* pAux;
    Celula* pAux2;
    pAux = lista->primeiro->pProx;//Primeira rocha da lista
    while((strcmp(pAux->rocha.Categoria,rocha->Categoria))!=0){
        pAux2 = pAux;
        pAux = pAux->pProx;
    }
    RochaMineral* pAux3 = &pAux->rocha;
    pAux2->pProx = pAux->pProx;
    return pAux3;
}


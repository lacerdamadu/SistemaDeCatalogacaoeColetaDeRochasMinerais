#include "RochaMineral.h"
#include "Compartimento.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void CriaListaRocha(Compartimento* lista, double PesoMax){
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
    Celula* pAux;
    pAux = lista->primeiro->pProx;
    while(pAux != NULL){
    printf("%s %.0lf\n", pAux->rocha.Categoria, pAux->rocha.Peso);
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

int InsereRocha(Compartimento *lista, RochaMineral *rocha, double PesoMax){
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
    
    Celula* pAux2; //achar o anterior

    pAux = lista->primeiro->pProx; //Primeira rocha da lista
 
    RochaMineral* pAux3; //Reservar a memória que será removida


    if(pAux->pProx == NULL){ //Se a lista dó tiver um elemento, esvazia a lista
        pAux3 = &pAux->rocha;
        CriaListaRocha(lista, 1000);
        
    } else {

        while((strcmp(pAux->rocha.Categoria,rocha->Categoria)) !=0 && pAux->rocha.Peso != rocha->Peso){

            pAux2 = pAux;
            pAux = pAux->pProx;
            
            pAux3 = &pAux->rocha;

            if(pAux->pProx == NULL){
                pAux2->pProx == NULL;
            }
        
        }

        pAux2->pProx = pAux->pProx;
    }
    printf("rocha que quero remover %s\n", pAux3->Categoria);

    return pAux3;
}


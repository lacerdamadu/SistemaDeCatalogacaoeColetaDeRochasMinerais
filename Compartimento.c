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

int TrocaRocha(Compartimento *lista, RochaMineral *rocha){
    Celula* pAux;
    pAux =  lista->primeiro->pProx;
    while(strcmp(pAux->rocha.Categoria, rocha->Categoria)!=0){
        pAux = pAux->pProx;
    }
    if(pAux->rocha.Peso > rocha->Peso){
        (pAux->rocha.Peso) = (rocha->Peso);
        return 1;
    } else {
        return 0;
    }
}

int InsereRocha(Compartimento *lista, Celula* rocha, double PesoMax){
    lista->ultimo->pProx = (Celula*) malloc(sizeof(Celula));
    lista->ultimo = lista->ultimo->pProx;
    *lista->ultimo = *rocha;
    lista->ultimo->pProx = NULL;
    return 1;
}
//se der errado pare aqui
Celula* RemoveRocha(Compartimento *lista, Celula* rocha){
    if (VerificaListaVazia(lista)){
        return 0;
    }
    Celula* pAux;
    Celula* pAux2; //achar o anterior
    pAux = lista->primeiro->pProx; //Primeira rocha da lista
    Celula* pAux3; //Reservar a memória que será removida

    if(pAux->pProx == NULL){ 
    //Se a lista só tiver um elemento, esvazia a lista
    printf("entrou aqui\n");
        pAux3 = pAux;
        lista->ultimo = lista->primeiro;
        lista->ultimo->pProx = NULL;

    } else if((strcmp(pAux->rocha.Categoria,rocha->rocha.Categoria) == 0) && (pAux->rocha.Peso == rocha->rocha.Peso)){ 
    //caso esteja retirando o primeiro da lista

        pAux3 = pAux;
        lista->primeiro = lista->primeiro->pProx;

    } else if((strcmp(lista->ultimo->rocha.Categoria,rocha->rocha.Categoria) == 0) 
    && (lista->ultimo->rocha.Peso == rocha->rocha.Peso)){
    //caso esteja retirando do final da lista

        pAux3 = lista->ultimo;
        while(pAux->pProx->pProx != NULL){          
            pAux = pAux->pProx;

        }
        lista->ultimo = pAux;
        lista->ultimo->pProx = NULL;

    } else{
    //caso esteja retirando do meio
        while(pAux != NULL){          
            pAux2 = pAux;

            if((strcmp(pAux->rocha.Categoria,rocha->rocha.Categoria) == 0) && (pAux->rocha.Peso == rocha->rocha.Peso)){
                pAux3 = pAux;
            }
            pAux = pAux->pProx;
        }

        pAux2->pProx = NULL;
        lista->ultimo = pAux2;

    }

    return pAux3;
}

int VerificaRochaExistente(Compartimento *lista, RochaMineral *rocha){
    Celula *pAux = lista->primeiro->pProx;

    int ver = 0;

    while(pAux != NULL){
        if((strcmp(pAux->rocha.Categoria,rocha->Categoria)) == 0){
            ver = 1;
        }
        pAux = pAux->pProx;
    }

    return ver;
}
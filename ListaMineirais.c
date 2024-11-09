#include "ListaMineirais.h"
#include <stdio.h>
#include <string.h>

void IniVListaM(ListaMinerais* ListaM){
    ListaM->Primeiro = InicioArranjo;
    ListaM->Ultimo = ListaM->Primeiro;
}

void InsMineral(ListaMinerais* ListaM, Minerais *NovoM){
    PreencheMineral(NovoM);
    ListaM->listaminerais[ListaM->Ultimo] = *NovoM;
    ListaM->Ultimo++;
} /*Não tratei pro caso da lista estar cheia,
    porque obrigatoriamente só receberemos no
    máximo três mineirais de entrada em cada lista*/

int RetMineral(ListaMinerais* ListaM, char *Nomed, Minerais *MinRet){
    if(ListaM->Ultimo == ListaM->Primeiro){
        return 0;
    }
    int i = 0; int pos;
    while(ListaM->listaminerais[i]!= NULL){
        if (ListaM->listaminerais[i] == Nomed){
            *MinRet = ListaM->listaminerais[i];
            pos = i;
        }
        i++;
    }
    for (int j = pos+1; j <= ListaM->Ultimo; j++){
        ListaM->listaminerais[j-1] = ListaM->listaminerais[j];
    }
    return 1;
}

void ImprimeListaM(ListaMinerais* ListaM){
    int i = 0;
    while (ListaM->listaminerais[i]!= NULL){
        printf("%s\n", ListaM->listaminerais[i].Nome);
        printf("%.2f\n", ListaM->listaminerais[i].Reatividade);
        printf("%.2f", ListaM->listaminerais[i].Dureza);
        printf("%s\n", ListaM->listaminerais[i].Cores);
    }
}
#include "ListaMineirais.h"
#include <stdio.h>
#include <string.h>

void IniVListaM(ListaMinerais* ListaM){
    ListaM->Primeiro = InicioArranjo;
    ListaM->Ultimo = ListaM->Primeiro;
}

void InsMineral(ListaMinerais* ListaM, char *NomeNov){
    Minerais NovoM;
    PreencheMineral(&NovoM, NomeNov);
    ListaM->listaminerais[ListaM->Ultimo] = NovoM;
    ListaM->Ultimo++;
} /*Não tratei pro caso da lista estar cheia,
    porque obrigatoriamente só receberemos no
    máximo três mineirais de entrada em cada lista*/

int RetMineral(ListaMinerais* ListaM, char *Nomed, Minerais *MinRet){
    if(ListaM->Ultimo == ListaM->Primeiro){
        return 0;
    }
    int i = 0; int pos;
    while(ListaM->listaminerais[i].Nome!= NULL){
        if (ListaM->listaminerais[i].Nome == Nomed){
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

const char *tranformacor(Cor Cores){
  switch (Cores){
  case Acizentado: return "Acinzentado";
  case Amarelo: return "Amarelo";
  case Azulado: return "Azulado";
  case Marrom: return "Marrom";
  case Vermelho: return "Vermelho";
  }   
}

void ImprimeListaM(ListaMinerais* ListaM){
    int i = 0;
    while (ListaM->listaminerais[i].Nome!= NULL){
        printf("%s\n", ListaM->listaminerais[i].Nome);
        printf("%.2f\n", ListaM->listaminerais[i].Reatividade);
        printf("%.2f", ListaM->listaminerais[i].Dureza);
        printf("%s\n", tranformacor(ListaM->listaminerais[i].Cores));
        printf("\n");
    }
}
#include "ListaMinerais.h"
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

int RetMineral(ListaMinerais* ListaM, char *Nomed){
    if(ListaM->Ultimo == ListaM->Primeiro){
        return 0;
    }

    int pos;

    for(int i = 0; i<ListaM->Ultimo;i++){
        if (ListaM->listaminerais[i].Nome == Nomed){
            pos = i;
        }
    }
    for (int j = pos+1; j <= ListaM->Ultimo; j++){
        ListaM->listaminerais[j-1] = ListaM->listaminerais[j];
    }

    ListaM->Ultimo--;

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
    for(int i = 0; i < ListaM->Ultimo; i++){
        printf("%s\n", ListaM->listaminerais[i].Nome);
        printf("Reat: %.2f\n", ListaM->listaminerais[i].Reatividade);
        printf("Dureza: %.2f\n", ListaM->listaminerais[i].Dureza);
        printf("Cor: %s\n", tranformacor(ListaM->listaminerais[i].Cores));
        printf("\n");
    }
}

void EsvaziaLista(ListaMinerais *ListaM){
    int num = ListaM->Ultimo;

    for(int i = 0; i < num; i++){
        RetMineral(ListaM, ListaM->listaminerais[i].Nome);
    }
}
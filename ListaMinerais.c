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
} /*N�o tratei pro caso da lista estar cheia,
    porque obrigatoriamente s� receberemos no
    m�ximo tr�s mineirais de entrada em cada lista*/

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
    for(int i = 0; i < ListaM->Ultimo; i++){
        printf("%s\n", ListaM->listaminerais[i].Nome);
        printf("Reat: %.2f\n", ListaM->listaminerais[i].Reatividade);
        printf("Dureza: %.2f\n", ListaM->listaminerais[i].Dureza);
        printf("Cor: %s\n", tranformacor(ListaM->listaminerais[i].Cores));
        printf("\n");
    }
}

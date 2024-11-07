#include "ListaMineirais.h"
#include <stdio.h>
#include <string.h>

void IniVListaM(ListaMinerais* ListaM){
    ListaM->Primeiro = InicioArranjo;
    ListaM->Ultimo = ListaM->Primeiro;
}

int InsMineral(ListaMinerais* ListaM, Minerais NovoM); //Insere um mineral ao final da lista

int RetMineral(ListaMinerais* ListaM, int pos, Minerais *MinRet); //Retira o mineiral da lista que está na posição "pos"

void ImprimeListaM(ListaMinerais* ListaM); //Imprime toda a lista de Minerais
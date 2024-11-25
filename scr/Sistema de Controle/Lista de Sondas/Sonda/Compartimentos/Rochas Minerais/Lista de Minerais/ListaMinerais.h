#ifndef LISTAMINERAIS_H_
#define LISTAMINERAIS_H_
#define InicioArranjo 0
#define MaxTam 3
#include "Minerais.h"

typedef struct {

 Minerais listaminerais[MaxTam];
 int Primeiro, Ultimo;

} ListaMinerais;

void IniVListaM(ListaMinerais* ListaM);

void InsMineral(ListaMinerais* ListaM, char *NomeNov);

int RetMineral(ListaMinerais* ListaM, char *Nomed);

void ImprimeListaM(ListaMinerais* ListaM);

void EsvaziaLista(ListaMinerais *ListaM);

#endif // LISTAMINERAIS_H_

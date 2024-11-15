#ifndef COMPARTIMENTO_H_
#define COMPARTIMENTO_H_
#include "RochaMineral.h"

typedef struct Celula{
    RochaMineral rocha;
    struct Celula* pProx;
} Celula;

typedef struct Compartimento{
    double PesoMax;
    Celula* primeiro;
    Celula* ultimo;
} Compartimento;

void CriaListaRocha(Compartimento *lista, int PesoMax);//Cria uma Lista de Rocha Mineral Vazia
int TamanhoListaRocha(Compartimento *lista);//Retorna o numero(int) de Rochas armazenadas no compartimento
int VerificaListaVazia(Compartimento *lista);//Verifica se a Lista esta vazia
void ImprimiLista(Compartimento *lista);//Exibe todo o conteudo do compartimento
double PesoAtual(Compartimento *lista);//Retorna o peso total do compartimento/lista
void TrocaRocha(Compartimento *lista, RochaMineral *rocha);//Adiciona uma rocha mais leve no lugar da rocha mais pesada do mesmo tipo
int InsereRocha(Compartimento *lista, RochaMineral *rocha, int PesoMax);//Insere uma rocha encontrada no final da lista, seguindo as regras
int RemoveRocha(Compartimento *lista, char* nomerocha);//Remove a rocha de acordo com a categoria(nome)

#endif
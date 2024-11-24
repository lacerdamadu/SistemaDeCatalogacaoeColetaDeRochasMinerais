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

void CriaListaRocha(Compartimento *lista, double PesoMax);//Cria uma Lista de Rocha Mineral Vazia
int TamanhoListaRocha(Compartimento *lista);//Retorna o numero(int) de Rochas armazenadas no compartimento
int VerificaListaVazia(Compartimento *lista);//Verifica se a Lista esta vazia
void ImprimiLista(Compartimento *lista);//Exibe todo o conteudo do compartimento
double PesoAtual(Compartimento *lista);//Retorna o peso total do compartimento/lista
int TrocaRocha(Compartimento *lista, RochaMineral *rocha);//Adiciona uma rocha mais leve no lugar da rocha mais pesada do mesmo tipo
int InsereRocha(Compartimento *lista, Celula* rocha, double PesoMax);//Insere uma rocha encontrada no final da lista, seguindo as regras
Celula* RemoveRocha(Compartimento *lista, Celula* rocha);//Remove a rocha de acordo com a categoria(nome)
int VerificaRochaExistente(Compartimento *lista, RochaMineral *rocha);//Verifica se já existe uma rocha daquele tipo no compartimento


#endif

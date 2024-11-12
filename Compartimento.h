#ifndef COMPARTIMENTO_H_
#define COMPARTIMENTO_H_
#include "RochaMineral.h"

typedef struct Celula{
    RochaMineral Mineral;
    struct Celula* pProx;
}Celula;

typedef struct Compartimento{
    Celula* primeiro;
    Celula* ultimo;
}Compartimento;

void CriaListaRocha();//Cria uma Lista de Rocha Mineral Vazia
void TamanhoListaRocha();//Retorna o numero de Rochas armazenadas no compartimento
void VerificaListaVazia();//Verifica se a Lista esta vazia
void
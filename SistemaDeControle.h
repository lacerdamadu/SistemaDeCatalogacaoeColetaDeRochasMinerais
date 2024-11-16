#ifndef SISTEMADECONTROLE_H_
#define SISTEMADECONTROLE_H_
#define STRING 100
#define Data 11

#include "ListaSondas.h"

void Central();//Contem um menu interativo dando ao usuario a opção de decidir o que ele quer fazer
int LeituraPorArquivo(TSondas *lista);//Lê o arquivo teste e passa os valores lidos para as outras funções
int LeituraPeloTerminal(TSondas *lista);//Lê as informações digitadas no terminal e inicializa o que for passado
void RedistribuiçãodeRochas(TSondas* lista);

#endif
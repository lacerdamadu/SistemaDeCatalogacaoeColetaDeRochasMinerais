#ifndef SISTEMADECONTROLE_H_
#define SISTEMADECONTROLE_H_

#define STRING 100
#define Data 11

#include "ListaSondas.h"

void Central(TSondas *lista);//Contem um menu interativo dando ao usuario a opção de decidir o que ele quer fazer
int LeituraPorArquivo(TSondas *lista);//Lê o arquivo teste e passa os valores lidos para as outras funções
int LeituraPeloTerminal(TSondas *lista);//Lê as informações digitadas no terminal e inicializa o que for passado
void Coleta(Celula Rocha,TSondas *ListaSondas, int numsondas);//Escolhe a sonda mais próxima da rocha para inserir
void RedistribuiRochas(TSondas *ListaSondas, int numsondas);//Faz a redistribuição de rochas


//Funções auxiliares
int VerificaSeTemQuemReceber(TSondas *lista, Compartimento *Comp, double peso);//
void OrdenaPesos(Sonda **Sondas, int numsondas);//
void PreencheVetor(TSondas *Sondas, Sonda **VetorSondas, int numsondas);//

#endif
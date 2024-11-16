#ifndef SISTEMADECONTROLE_H_
#define SISTEMADECONTROLE_H_
#define STRING 100
#define Data 11

#include "ListaDeSondas.h"

void Central();//Contem um menu interativo dando ao usuario a opção de decidir o que ele quer fazer
int LeituraPorArquivo(ListaDeSondas *lista);//Lê o arquivo teste e passa os valores lidos para as outras funções
int LeituraPeloTerminal(ListaDeSondas *lista);//Lê as informações digitadas no terminal e inicializa o que for passado
void RedistribuiçãodeRochas(ListaDeSondas *lista); /*posicionará todas as sondas na mesma localização(0,0) 
                                                e redistribuirá as rochas de seus compartimentos de maneira que cada sonda
                                                fique com aproximadamente a média calculada entre o peso atual de todas as N
                                                sondas no momento*/

#endif
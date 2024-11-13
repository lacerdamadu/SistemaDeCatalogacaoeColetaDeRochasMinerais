#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ListaMinerais.h"
#include "RochaMineral.h"
#define TSTRING 100

int main(){

   char data[10];

    ListaMinerais ListaT;
    RochaMineral* rocha;


    IniVListaM(&ListaT);

    char minerais[TSTRING];    
    char cadamineral[TSTRING]; 


    int i, j = 0;

    fgets(minerais, sizeof(minerais), stdin);


    for (i = 0; i < strlen(minerais); i++) {
        if (minerais[i] == ' ' || minerais[i] == '\n' || minerais[i] == '\0') {  
            cadamineral[j] = '\0';       // Finaliza a string cadamineral
            if (strlen(cadamineral) > 0) { // Verifica se cadamineral não está vazio
                InsMineral(&ListaT, cadamineral); // Chama a função InsMineral passando nome por nome
                j = 0; // Reseta o índice de cadamineral para o próximo cadamineral
            }
            if (minerais[i] == '\n' || minerais[i] == '\0') {
                break; // Sai do loop se encontrar o fim da linha ou da string
            }
        } else {
            cadamineral[j++] = minerais[i];
        }
    }


    ImprimeListaM(&ListaT);

    mytime = time(NULL);

    ListaMinerais listaM;


    return 0;
}
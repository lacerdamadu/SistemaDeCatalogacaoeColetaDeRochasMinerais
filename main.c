#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ListaMinerais.h"
#include "RochaMineral.h"

int main(){

   char data[10];

    ListaMinerais ListaT;
    RochaMineral rocha;

    time_t mytime;
    mytime = time(NULL);

    IniVListaM(&ListaT);

    char input[300];
    char nome[100];

 // Vari�vel para armazenar temporariamente cada nome
    int i, j = 0;

    printf("Digite ate tres nomes separados por espa�os:\n");
    fgets(input, sizeof(input), stdin);

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\0') {
            nome[j] = '\0'; // Finaliza a string nome
            if (strlen(nome) > 0) { // Verifica se nome n�o est� vazio
                InsMineral(&ListaT, nome); // Chama a fun��o preenchemineral
                j = 0; // Reseta o �ndice de nome para o pr�ximo nome
            }
            if (input[i] == '\n' || input[i] == '\0') {
                break; // Sai do loop se encontrar o fim da linha ou da string
            }
        } else {
            nome[j++] = input[i];
        }
    }


    ImprimeListaM(&ListaT);

    Coleta(&rocha, ctime(&mytime), &ListaT);
}

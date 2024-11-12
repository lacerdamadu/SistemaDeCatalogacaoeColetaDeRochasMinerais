#include <stdio.h>
#include <string.h>
#include "ListaMineirais.h"

int main(){
    ListaMinerais ListaT;
    IniVListaM(&ListaT);

    char input[300];    
    char nome[100];

 // Variável para armazenar temporariamente cada nome
    int i, j = 0;

    printf("Digite até três nomes separados por espaços:\n");
    fgets(input, sizeof(input), stdin);

    for (i = 0; i < strlen(input); i++) {
        if (input[i] == ' ' || input[i] == '\n' || input[i] == '\0') {
            nome[j] = '\0'; // Finaliza a string nome
            if (strlen(nome) > 0) { // Verifica se nome não está vazio
                InsMineral(&ListaT, nome); // Chama a função preenchemineral
                j = 0; // Reseta o índice de nome para o próximo nome
            }
            if (input[i] == '\n' || input[i] == '\0') {
                break; // Sai do loop se encontrar o fim da linha ou da string
            }
        } else {
            nome[j++] = input[i];
        }
    }


    ImprimeListaM(&ListaT);
}
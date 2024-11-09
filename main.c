#include <stdio.h>
#include "ListaMineirais.h"

int main(){
    ListaMinerais ListaT;
    IniVListaM(&ListaT);
    for(int i=0; i < 2; i++){
        char nome[100];
        scanf("%s", nome);
        InsMineral(&ListaT, nome);
    }
    ImprimeListaM(&ListaT);
}
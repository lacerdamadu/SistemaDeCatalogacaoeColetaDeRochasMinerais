#include <stdio.h>
#include "ListaSondas.h"
#include "SistemaDeControle.h"

int main(){
    TSondas ListaSondas;
    FazListaVazia(&ListaSondas);
    Central(&ListaSondas);
    return 0;
}



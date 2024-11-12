#include <stdio.h>
<<<<<<< HEAD
#include "ListaMineirais.h"

int main(){
    ListaMinerais ListaT;
    IniVListaM(&ListaT);
=======
#include "ListaMinerais.h"
#include "RochaMineral.h"
#include <time.h>

int main(){
    char data[10];

    ListaMinerais ListaT;
    RochaMineral* rocha;

    time_t mytime;
    mytime = time(NULL);

    IniVListaM(&ListaT);

>>>>>>> 45f4f07 (Rocha Mineral)
    for(int i=0; i < 2; i++){
        char nome[100];
        scanf("%s", nome);
        InsMineral(&ListaT, nome);
    }
<<<<<<< HEAD
    ImprimeListaM(&ListaT);
}
=======

    ImprimeListaM(&ListaT);
    ListaMinerais listaM;
    Coleta(&listaM, ctime(&mytime));

}
>>>>>>> 45f4f07 (Rocha Mineral)

#ifndef ROCHAMINERAL_H_INCLUDED
#define ROCHAMINERAL_H_INCLUDED
#include "ListaMinerais.h"

typedef struct{
    double peso;
    char categoria[20];
    int latitude, longitude;
    char data[10];
    ListaMinerais listaM;
}RochaMineral;

void Coleta(RochaMineral* rocha, char* data, ListaMinerais* listaT);


#endif // ROCHAMINERAL_H_INCLUDED

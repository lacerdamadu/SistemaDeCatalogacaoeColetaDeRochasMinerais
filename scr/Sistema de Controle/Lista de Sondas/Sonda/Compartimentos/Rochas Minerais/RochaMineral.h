#ifndef ROCHAMINERAL_H_INCLUDED
#define ROCHAMINERAL_H_INCLUDED
#define Data 11
#include "ListaMinerais.h"

typedef struct{
    int Identificador;
    double Peso;
    char Categoria[max_tam];
    ListaMinerais ListaM;
    double Latitude, Longitude;
    char DataC[Data];
} RochaMineral;


void InicializaRocha(RochaMineral* rocha, double Peso, ListaMinerais* ListaMin, double Latitude, double Longitude, char* data);

void ClassificaRocha(RochaMineral *Rocha, ListaMinerais *ListaMin);

void ImprimeRocha(RochaMineral *Rocha);

void setPesoRocha(RochaMineral *Rocha, double Peso);
double getPesoRocha(RochaMineral *Rocha);

void setLatitude(RochaMineral *Rocha, double Latitude);
double getLatitude(RochaMineral *Rocha);

void setLongitude(RochaMineral *Rocha, double Longitude);
double getLongitude(RochaMineral *Rocha);


void setData(RochaMineral *Rocha, char* DataC);
char* getData(RochaMineral *Rocha);

#endif // ROCHAMINERAL_H_INCLUDED
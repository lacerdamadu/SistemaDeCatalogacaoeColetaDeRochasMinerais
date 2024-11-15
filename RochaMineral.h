#ifndef ROCHAMINERAL_H_INCLUDED
#define ROCHAMINERAL_H_INCLUDED

typedef struct{
    double peso;
    char categoria[20];
    int latitude, longitude;
    char data[10];
}RochaMineral;

void Coleta(RochaMineral* rocha, char* data);


#endif // ROCHAMINERAL_H_INCLUDED

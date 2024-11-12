#ifndef MINERAIS_H_
#define MINERAIS_H_
#define max_tam 100

typedef enum{
    Acizentado,
    Amarelo,
    Azulado,
    Marrom,
    Vermelho
}Cor;

typedef struct{
    char Nome[max_tam];
    double Dureza;
    double Reatividade;
    Cor Cores;
}Minerais;

void PreencheMineral(Minerais *Mineral, char *Nome); //Recebe o nome do Mineral e preenche os valores predeterminados
<<<<<<< HEAD
Minerais InicializaMineral(Minerais *Mineral, char* Nome, double Dureza, double Reatividade, Cor Cores);//Chama as funÃ§Ãµes sets para guardar os valores das variaveis
=======
Minerais InicializaMineral(Minerais *Mineral, char* Nome, double Dureza, double Reatividade, Cor Cores);//Chama as funções sets para guardar os valores das variaveis
>>>>>>> 45f4f07 (Rocha Mineral)

//Sets e Gets
void setNomeMineral(Minerais *Mineral, char* Nome);
char* getNomeMineral(Minerais *Mineral);

void setDureza(Minerais *Mineral, double Dureza);
double getDureza(Minerais *Mineral);

void setReatividade(Minerais *Mineral, double Reatividade);
double getReatividade(Minerais *Mineral);

void setCores(Minerais *Mineral, Cor Cores);
Cor getCores(Minerais *Mineral);

<<<<<<< HEAD
#endif
=======
#endif
>>>>>>> 45f4f07 (Rocha Mineral)

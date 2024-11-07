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

void PreencheMineral(Minerais *Mineral);//Recebe o nome do Mineral e preenche os valores predeterminados
void InicializaMineral(Minerais Mineral, char Nome, float Dureza, float Reatividade, Cor Cores);//Chama as funções sets para guardar os valores das variaveis

//Sets e Gets
void setNomeMineral(Minerais Mineral, char Nome);
char* getNomeMineral(Minerais *Mineral);

void setDureza(Minerais *Mineral, float Dureza);
float getDureza(Minerais *Mineral);

void setReatividade(Minerais *Mineral, float Reatividade);
float getReatividade(Minerais *Mineral);

void setCor(Minerais *Mineral, Cor Cores);
Cor getCor(Minerais *Mineral);

#endif

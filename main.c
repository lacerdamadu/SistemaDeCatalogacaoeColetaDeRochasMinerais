#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Sonda.h"
#include "ListaSondas.h"
#define TSTRING 100

int main(){

    int sondas;
    printf("Numero de sondas: ");
    scanf("%d", &sondas);
    printf("\n");

    TSondas sonda;
    ListaMinerais ListaM;
    Compartimento CompartimentoTeste;
    ListaMinerais ListaT;
    FazListaVazia(&sonda);
    Sonda NovaSonda[sondas];
    int pesos[sondas];

    for(int i = 0; i<sondas; i++){
        double Latitude, Longitude;
        int PesoMax, Velocidade, Combustivel, Identificador;

        printf("Latitude Sonda %d: ", i+1);
        scanf("%lf", &Latitude);

        printf("Longitude Sonda %d: ", i+1);
        scanf("%lf", &Longitude);

        printf("Peso Sonda %d: ", i+1);
        scanf("%d", &PesoMax);

        printf("Velocidade Sonda %d: ", i+1);
        scanf("%d", &Velocidade);

        printf("Combustivel Sonda %d: ", i+1);
        scanf("%d", &Combustivel);

        Identificador = i + 1;

        printf("\n");

        InicializaSonda(&NovaSonda[i], Latitude, Longitude, PesoMax, Velocidade, Combustivel, Identificador);
        Insere(&sonda,&NovaSonda[i]);
        pesos[i] = PesoMax;
    }

    int n_op;

    printf("Numero de operacoes: ");
    scanf("%d", &n_op);

    for(int i; i<n_op; i++){
        //RochaMineral* Rocha;
        char operacao;
        scanf(" %c", operacao);
        if(operacao == 'R'){
            IniVListaM(&ListaM);
            char minerais[TSTRING];
            char cadamineral[TSTRING];


            int i, j = 0;

            getchar();
            fgets(minerais, sizeof(minerais), stdin);


            for (i = 0; i < strlen(minerais); i++) {
                if (minerais[i] == ' ' || minerais[i] == '\n' || minerais[i] == '\0') {
                    cadamineral[j] = '\0';       // Finaliza a string cadamineral
                    if (strlen(cadamineral) > 0) { // Verifica se cadamineral não está vazio
                        InsMineral(&ListaT, cadamineral); // Chama a função InsMineral passando nome por nome
                        j = 0; // Reseta o índice de cadamineral para o próximo cadamineral
                    }
                    if (minerais[i] == '\n' || minerais[i] == '\0') {
                        break; // Sai do loop se encontrar o fim da linha ou da string
                    }
                } else {
                    cadamineral[j++] = minerais[i];
                }
            }
                char data[Data];

                time_t mytime;
                mytime = time(NULL);

                RochaMineral RochaTeste;

                double Latitude, Longitude;
                double Peso;

                printf("Peso: ");
                scanf("%lf", &Peso);

                printf("Latitude: ");
                scanf("%lf", &Latitude);

                printf("Longitude: ");
                scanf("%lf", &Longitude);

                InicializaRocha(&RochaTeste, Peso, &ListaT, Latitude, Longitude, ctime(&mytime));
                InsereRocha(&CompartimentoTeste, &RochaTeste, &sonda);
                CriaListaRocha(&CompartimentoTeste, pesos[i]);
            } else if(operacao == 'I'){

            }
        }



        ImprimiLista(&CompartimentoTeste);

        Imprime(&sonda);

    return 0;
}

#include <stdio.h>
#include <string.h>
#include <time.h>
#include "Compartimento.h"
#define TSTRING 100

//void DigitaMineirais();


int main(){
    
    double PesoMax;

    printf("Digite o peso maximo suportado: ");
    scanf("%lf", &PesoMax);

    int RochasColetadas;

    printf("Digite a quantidade de Rochas coletadas: ");
    scanf("%d", &RochasColetadas);

    Compartimento CompartimentoTeste;

    CriaListaRocha(&CompartimentoTeste, PesoMax);

    ListaMinerais ListaT;
    //RochaMineral* Rocha;   
    

    for(int k = 0; k < RochasColetadas; k++){
        IniVListaM(&ListaT);

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
        InsereRocha(&CompartimentoTeste, &RochaTeste, PesoMax);
    }

    ImprimiLista(&CompartimentoTeste);


    return 0;
}
#include <stdio.h>
#include <string.h>
#include "SistemaDeControle.h"
#define string = 100;
#define str2 = 20;

int LeituraPorArquivo(ListaDeSondas* lista){
    FILE* entrada;
    entrada = fopen("TP1CCF211-2024-TESTES.pdf", "r");
    if(entrada==NULL){
        printf("Erro ao ler o arquivo.");
        return 0;
    }
    int numsondas;
    numsondas = fgetc(entrada);
    char str[string];
    for(int i = 0; i<numsondas;i++){
        char *linha = fgets(str, 100, entrada);//Tentei definir o numero 100 como constante mas a função nao aceitou
        if(linha==NULL){
            printf("Erro ao ler a linha.");
        }
        else{
            int i=0;
            char latitude[str2];
            while(str[i]!='\0'){
                
            }
        }
    }

    fclose(entrada);
}






    /*char data[Data];
    time_t mytime;
    mytime = time(NULL);

    int numsondas;
    double lat_i, long_i;
    int  c_i, v_i, vc_i, identificador;

    scanf("%d", &numsondas);//A primeira entrada é o numero de sondas que irão ser inicializadas

    //for(int i=0;i<numsondas;i++){
        Sonda NovaSonda;
        identificador = 1;
        printf("Informações da sonda:");
        scanf("%lf %lf %d %d %d", &lat_i, &long_i, &c_i, &v_i, &vc_i);
        InicializaSonda(&NovaSonda, lat_i, long_i, c_i, v_i, vc_i, identificador);
    //}

    int numoperacoes;
    char operacao;
    double latrocha, longrocha, pesorocha; 
    char mineral1[STRING];
    char mineral2[STRING];
    char mineral3[STRING];
    printf("Numero de operacoes:");
    scanf("%d", &numoperacoes);
    ListaMinerais lista;
    for(int i=0;i<numoperacoes;i++){
        printf("Operacao:");
        scanf("%c", &operacao);
        if(operacao=='R'){
            printf("Informacoes rocha:");
            scanf("%lf %lf %d %s %s %s", &latrocha, &longrocha, &pesorocha, mineral1, mineral2, mineral3);
            InsMineral(&lista, mineral1);
            InsMineral(&lista, mineral2);
            InsMineral(&lista, mineral3);
            RochaMineral RochaTeste;
            InicializaRocha(&RochaTeste, pesorocha, &lista, latrocha, longrocha, ctime(&mytime));
            InsereRocha(&NovaSonda.CompartmentoS, &RochaTeste, c_i);
        }
    }
    
    

    /*for(int k = 0; k < RochasColetadas; k++){
        IniVListaM(&ListaT);

        char minerais[TSTRING];    
        char cadamineral[TSTRING]; 


        int i, j = 0;

        getchar();
        fgets(minerais, sizeof(minerais), stdin);


        for (i = 0; i < strlen(minerais); i++) {
            if (minerais[i] == ' ' || minerais[i] == '\n' || minerais[i] == '\0') {  
                cadamineral[j] = '\0';
                if (strlen(cadamineral) > 0) {
                    InsMineral(&ListaT, cadamineral);
                    j = 0;
                }
                if (minerais[i] == '\n' || minerais[i] == '\0') {
                    break;
                }
            } else {
                cadamineral[j++] = minerais[i];
            }
        }

        char data[Data];

        time_t mytime;
        mytime = time(NULL);

        RochaMineral RochaTeste;
        InicializaRocha(&RochaTeste, Peso, &ListaT, Latitude, Longitude, ctime(&mytime));
        InsereRocha(&CompartimentoTeste, &RochaTeste, PesoMax);
    }*/


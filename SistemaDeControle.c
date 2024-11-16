#include <stdio.h>
#include <string.h>
#include <time.h>
#include "ListaSondas.h"
#include "SistemaDeControle.h"

#define STRING 100
#define Data 11

void Central(){
    printf("Bem-vindo(a) ao Sistema de Controle e Catalogação de Rochas Minerais!\n");
    printf("Como voce deseja realizar a entrada de dados?\n");
    printf("(1)Arquivo.\n(2)Terminal.\n");
    TSondas lista;
    int escolha;
    scanf("%d", &escolha);
    switch (escolha){
        case 1:
            LeituraPorArquivo(&lista);
            break;
        case 2:
            LeituraPeloTerminal(&lista);
            break;
        default:
            break;
    }
}


int LeituraPorArquiv(TSondas *lista){
    char data[Data];
    time_t mytime;
    mytime = time(NULL);

    printf("Digite o nome do arquivo: ");
    char nome[STRING];
    scanf("%s", nome);

    FILE* entrada;
    entrada = fopen(nome, "r");
    if(entrada==NULL){
        printf("Erro ao ler o arquivo.");
        return 0;
    }

    int numsondas;
    double lat_i, long_i;
    int  c_i, v_i, vc_i, identificador;

    fscanf(entrada,"%d", &numsondas);
    InicializaListaSondas(lista);
    for(int i = 0; i<numsondas;i++){
        Sonda NovaSonda;
        identificador = 1;
        fscanf("%lf %lf %d %d %d", &lat_i, &long_i, &c_i, &v_i, &vc_i);
        InicializaSonda(&NovaSonda, lat_i, long_i, c_i, v_i, vc_i, identificador);
        InsereSondaLista(&NovaSonda);
    }
    int numoperacoes;
    char operacao;
    double latrocha, longrocha, pesorocha; 
    char mineral1[STRING];
    char mineral2[STRING];
    char mineral3[STRING];
    
    fscanf(entrada,"%d", &numoperacoes);
    ListaMinerais listaa;
    for(int i=0;i<numoperacoes;i++){
        fscanf(entrada, "%c", operacao);
        switch (operacao){
        case 'R':
            fscanf(entrada,"%lf %lf %d %s %s %s", &latrocha, &longrocha, &pesorocha, mineral1, mineral2, mineral3);
            if(strcmp(mineral1, "/n")!=0){
                InsMineral(&listaa, mineral1);
            }
            if(strcmp(mineral2, "/n")!=0){
                InsMineral(&listaa, mineral2);
            }
            if(strcmp(mineral3, "/n")!=0){
                InsMineral(&listaa, mineral3);
            }
            RochaMineral RochaTeste;
            InicializaRocha(&RochaTeste, pesorocha, lista, latrocha, longrocha, ctime(&mytime));
            break;
        case 'I':
            ImprimiListaSondas(lista);
            break;
        case 'E':
            RedistribuiçãodeRochas(lista);
            break;
        }
    }
    fclose(entrada);
    return 0;
}


int LeituraPeloTerminal(TSondas *lista){
    char data[Data];
    time_t mytime;
    mytime = time(NULL);

    printf("Inicializando a entrada...\n");
    printf("Qual operacao deseja realizar?\n");
    printf("(1)Inicializacao de sondas.\n"
    "(2)Inicializacao de rochas.\n"
    "(3)Redistribuição de rochas.\n"
    "(4)Impressão do estado atual das sondas.\n");
    int escolha;
    scanf("%d", &escolha);
    switch (escolha){
    case 1:
        printf("Esta operacao irá criar uma nova sonda de acordo com os tributos digitados."
        "A sonda tambem será ligada e disparada para o solo Marciano."
        "Concorda em prosseguir?(s/n)\n");
        char res;
        scanf("%c", res);
        if(res == 's'){
            Sonda NovaSonda;
            double lat_i, long_i;
            int  c_i, v_i, nc_i, identificador;
            printf("Digite as informações da sonda:\n");
            printf("Latitude:");
            scanf("%lf", &lat_i);
            printf("Longitude:");
            scanf("%lf", &long_i);
            printf("Capacidade de armazenamento em kg:");
            scanf("%d", &c_i);
            printf("Velocidade:");
            scanf("%d", &v_i);
            printf("Nivel de combustivel:");
            scanf("%d", &nc_i);

            InicializaSonda(&NovaSonda, lat_i, long_i, c_i, v_i, nc_i, identificador);
            InsereSondaLista(&NovaSonda);
            LigaSonda(&NovaSonda);
            printf("Deseja realizar outra operacao?(s/n)");
            char res2;
            if(res == 's'){
                LeituraPeloTerminal(lista);
            }
            else{
                return 0;
            }
        }
        else{
            LeituraPeloTerminal(lista);
        }
        break;

    case 2:
        printf("Esta operacao ira criar uma nova rocha de acordo com os atributos digitados.\n"
        "Alem de adiciona-la na sonda mais proxima ou que ja tenha uma amostra do mesmo tipo de rocha.\n"
        "Concorda em prosseguir?(s/n)");
        char res;
        scanf("%c", res);
        if(res == 's'){
            ListaMinerais listaa;
            double latrocha, longrocha;
            int pesorocha; 
            char mineral1[STRING];
            char mineral2[STRING];
            char mineral3[STRING];

            printf("Digite as informações da rocha:\n");
            printf("Latitude:");
            scanf("%lf", &latrocha);
            printf("Longitude:");
            scanf("%lf", &longrocha);
            printf("Peso da rocha:");
            scanf("%d", &pesorocha);
            printf("Minerais que formam a rocha:");
            scanf("%s %s %s", mineral1, mineral2, mineral3);
            if(strcmp(mineral1, "/n")!=0){
                InsMineral(&listaa, mineral1);
            }
            if(strcmp(mineral2, "/n")!=0){
                InsMineral(&listaa, mineral2);
            }
            if(strcmp(mineral3, "/n")!=0){
                InsMineral(&listaa, mineral3);
            }
            RochaMineral RochaTeste;
            InicializaRocha(&RochaTeste, pesorocha, lista, latrocha, longrocha, ctime(&mytime));
            //InsereRocha(&NovaSonda.CompartmentoS, &RochaTeste, c_i);
            printf("Deseja realizar outra operacao?(s/n)");
            char res2;
            if(res == 's'){
                LeituraPeloTerminal(lista);
            }
            else{
                return 0;
            }
        }
        else{
            LeituraPeloTerminal(lista);
        }
    case 3:
        ImprimiListaSondas(lista);
        char res2;
        if(res == 's'){
            LeituraPeloTerminal(lista);
        }
        else{
            return 0;
        }
        break;
    case 4:
        /*Chama a função de redistribuição que colocara as sondas no ponto (0,0) 
        e redistribuira as rochas de modo que elas carreguem aproximadamente a media 
        do peso atual das sondas*/
        printf("Deseja realizar outra operacao?(s/n)");
        char res2;
        if(res == 's'){
            LeituraPeloTerminal(lista);
        }
        else{
            return 0;
        }
        break;
    default:
        break; 
    } 
    return 0;
}

void RedistribuiçãodeRochas(TSondas *lista){

}
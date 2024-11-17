#include <stdio.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#include "SistemaDeControle.h"

#define PESOMAXIMO 10000
#define STRING 100
#define Data 11

void Central(TSondas *lista){
    setlocale(LC_ALL, "Portuguese_Brazil");
    printf("Bem-vindo(a) ao Sistema de Controle e Catalogaçãoo de Rochas Minerais!\n");
    printf("Como voce deseja realizar a entrada de dados?\n");
    printf("(1)Arquivo.\n(2)Terminal.\n");
    int escolha;
    scanf("%d", &escolha);
    switch (escolha){
        case 1:
            LeituraPorArquivo(lista);
            break;
        case 2:
            LeituraPeloTerminal(lista);
            break;
        default:
            break;
    }
}


int LeituraPorArquivo(TSondas *lista){
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
    FazListaVazia(lista);
    for(int i = 0; i<numsondas;i++){
        Sonda NovaSonda;
        identificador = i+1;
        fscanf(entrada,"%lf %lf %d %d %d", &lat_i, &long_i, &c_i, &v_i, &vc_i);
        InicializaSonda(&NovaSonda, lat_i, long_i, c_i, v_i, vc_i, identificador);
        InsereSonda(lista, &NovaSonda);
    }

    int numoperacoes;
    char operacao;
    double latrocha, longrocha, pesorocha; 
    char mineral1[STRING];
    char mineral2[STRING];
    char mineral3[STRING];
    
    fscanf(entrada,"%d", &numoperacoes);
    ListaMinerais listaa;
    IniVListaM(&listaa);
    for(int i=0;i<numoperacoes;i++){

        double Distancias[numsondas];
        fscanf(entrada, "%c", operacao);
        switch(operacao){

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
            InicializaRocha(&RochaTeste, pesorocha, &listaa, 
             latrocha, longrocha, ctime(&mytime)); /*Inicializa uma rocha nova a 
                                                    partir da linha do arquivo*/
            
            

            Apontador AuxLis = lista->pPrimeiro;

            for(int i = 0; i > numsondas; i++){
                Distancias[i] = CalculaDist(AuxLis->Sonda, RochaTeste);
                AuxLis = AuxLis->pProx;
            } /*preenche as distâncias relativas das sondas até a rocha*/

            double MenorDist = Distancias[0];
            int IndDes;

            for(int j = 0; j > numsondas; j++){
                if(MenorDist > Distancias[i]){
                    MenorDist = Distancias[i];
                    IndDes = j+1;
                }
            } /*acha o identificador da sonda de menor distância*/

            
            Apontador pAux;
            pAux = lista->pPrimeiro->pProx;

            while(pAux->Sonda.Identificador != IndDes){
                pAux = pAux->pProx;
            } /*A partir do identificador acha o enderço de memória da sonda de menor distância*/
            
            InsereRocha(&pAux->Sonda.CompartmentoS, &RochaTeste, pAux->Sonda.CompartmentoS.PesoMax);
            /*Insere a rocha nessa sonda*/
            
            break;
        case 'I':
            ImprimeSonda(lista);
            break;
        case 'E':
            RedistribuiRochas(lista, numsondas);
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

    int numsondas = 1;

    printf("Inicializando a entrada...\n");
    printf("Qual operação deseja realizar?\n");
    printf("(1)Inicializacao de sondas.\n"
    "(2)Inicialização de rochas.\n"
    "(3)Redistribuiçãoo de rochas.\n"
    "(4)Impressão do estado atual das sondas.\n");
    int escolha; 
    scanf("%d", &escolha);
    switch (escolha){
    case 1:
        printf("Esta operacao irá criar uma nova sonda de acordo com os tributos digitados.\n"
        "A sonda tambem será ligada e disparada para o solo Marciano.\n"
        "Concorda em prosseguir?(s/n)\n");
        getchar();
        char res;
        scanf("%c", &res);
        if(res == 's'){
            Sonda NovaSonda;
            
            double lat_i, long_i;
            int  c_i, v_i, nc_i, identificador = 1;
            printf("Digite as informações da sonda:\n");
            getchar();

            printf("Latitude:");
            scanf("%lf", &lat_i);
            getchar();
            
        
            printf("Longitude:");
            scanf("%lf", &long_i);
            getchar();
            printf("%lf", long_i);
           
            printf("Capacidade de armazenamento em kg:");
            scanf("%d", &c_i);

            printf("Velocidade:");
            scanf("%d", &v_i);

            printf("Nivel de combustível:");
            scanf("%d", &nc_i);

            InicializaSonda(&NovaSonda, lat_i, long_i, c_i,
             v_i, nc_i, identificador);

            InsereSonda(lista,&NovaSonda);

            LigaSonda(&NovaSonda);

            identificador++;
            numsondas++;

            printf("Deseja realizar outra operação?(s/n)");
            getchar();
            char res2;
            scanf("%c", &res2);
            if(res2 == 's'){
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
        if(numsondas == 0){
            printf("Antes de realizar essa operação e necessário criar uma sonda.\n");
            LeituraPeloTerminal(lista);
        }
        else{
            ListaMinerais listaa;
            IniVListaM(&listaa);
            printf("Esta operacao irá criar uma nova rocha de acordo com os atributos digitados.\n"
            "Alem de adicioná-la na sonda mais próxima ou que ja tenha uma amostra do mesmo tipo de rocha.\n"
            "Concorda em prosseguir?(s/n)\n");
            getchar();
            char res6;
            scanf("%c", &res6);
            if(res6 == 's'){
                printf("entrou\n");
                ListaMinerais listaa;
                double latrocha, longrocha;
                int pesorocha; 
        

                printf("Digite as informações da rocha:\n");
                printf("Latitude:");
                scanf("%lf", &latrocha);
                getchar();

                printf("Longitude:");
                scanf("%lf", &longrocha);
                getchar();

                printf("Peso da rocha:");
                scanf("%d", &pesorocha);
             

                char TodosMinerais[300];
                char nome[100];
                int i, j = 0;
                printf("Digite até três minerais separados por espaços:\n");
                getchar();
                fgets(TodosMinerais, sizeof(TodosMinerais), stdin);
                printf("%s", TodosMinerais);
                for (i = 0; i < strlen(TodosMinerais); i++) {
                    if (TodosMinerais[i] == ' ' || TodosMinerais[i] == '\n' || TodosMinerais[i] == '\0') {
                        nome[j] = '\0'; 
                    
                        if (strlen(nome) > 0) { 
                            printf("%s", nome);
                            InsMineral(&listaa, nome);
                            j = 0; 
                        }
                        if (TodosMinerais[i] == '\n' || TodosMinerais[i] == '\0') {
                            break;
                        }
                    } 
                    else {
                        nome[j++] = TodosMinerais[i];
                    }
                ImprimeListaM(&listaa);
                RochaMineral RochaTeste;
                InicializaRocha(&RochaTeste, pesorocha, &listaa,
                latrocha, longrocha, ctime(&mytime));  /*Inicializa uma rocha nova a 
                                                                                partir do que o usuÃ¡rio digita*/
                printf("%s", RochaTeste.Categoria);
                double Distancias[numsondas];       /*Vetor para armazenar as distÃ¢ncias das sondas em relaÃ§Ã£o Ã  rocha*/

                Apontador AuxLis = lista->pPrimeiro;

                for(int i = 0; i > numsondas; i++){
                    Distancias[i] = CalculaDist(AuxLis->Sonda, RochaTeste);
                    AuxLis = AuxLis->pProx;
                } /*Percorre a lista de sondas armazenando as distância ralativas*/


                double MenorDist = Distancias[0];
                int IndDes;

                for(int j = 0; j > numsondas; j++){
                    if(MenorDist > Distancias[j]){
                        MenorDist = Distancias[j];
                        IndDes = j+1;
                    }
                } /*Acha o identificador da sonda com menor distância*/

                
                Apontador pAux;
                pAux = lista->pPrimeiro->pProx;

                while(pAux->Sonda.Identificador != IndDes){
                    pAux = pAux->pProx;
                } /*Acha o endereço de memória da sonda com menor distânica a partir do identificador*/
                
                InsereRocha(&pAux->Sonda.CompartmentoS, &RochaTeste, pAux->Sonda.CompartmentoS.PesoMax);
                /*Insere a rocha no compartimento da sonda com menor distância*/
                
                printf("Deseja realizar outra operação?(s/n)");
                getchar();
                char res1;
                scanf("%c", &res1);
                if(res1 == 's'){
                    LeituraPeloTerminal(lista);
                }
                else{
                    return 0;
                }   
            }
            }
        else{
            LeituraPeloTerminal(lista);
        }
    }
        break;
    case 4:
        printf("Esta opercação ira imprimir as informações das rochas coletadas até o momento,\n"
        "além da identificação de qual sonda ela está armazenda.\n"
        "Concorda em prosseguir?\n");
        getchar();
        char res5;
        scanf("%c", &res5);
        if(res5 == 's'){
            ImprimeSonda(lista);
            printf("Deseja realizar outra operação?(s/n)\n");
            char res2;
            scanf("%c", &res2);
            if(res2 == 's'){
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
    case 3:
        printf("Esta função irá mover todas as sondas para o ponto (0,0) e redistrubuir as rochas entre elas.\n"
        "Com o intuito de que cada sonda fique com aproximadamente a média do peso total delas\n."
        "Concorda em prosseguir?\n");
        getchar();
        char res4;
        scanf("%c", &res4);

        if(res=='s'){
            RedistribuiRochas(lista, numsondas);
            printf("Deseja realizar outra operacao?(s/n)\n");
            getchar();
            char res3;
            scanf("%c", &res3);
            if(res3 == 's'){
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
    default:
        break; 
    } 
    return 0;
}

void RedistribuiRochas(TSondas *lista, int numsondas){
    double PesoTotal; Apontador AuxiliarSondas = lista->pPrimeiro->pProx;
    while (AuxiliarSondas->pProx != NULL){
            MoveSonda(&AuxiliarSondas->Sonda,0,0); /*Move as sondas ao ponto (0,0)*/

            PesoTotal += PesoAtual(&AuxiliarSondas->Sonda.CompartmentoS); /*Calcula o Peso conjunto de todas as Sondas*/

            AuxiliarSondas = AuxiliarSondas->pProx; /*Percorre a Lista*/
        }

        double Med = PesoTotal/numsondas;

        Compartimento ComTemporario;
        CriaListaRocha(&ComTemporario, PESOMAXIMO);

        AuxiliarSondas = lista->pPrimeiro->pProx;

        Apontador AuxiliarSondas2 = lista->pPrimeiro->pProx;

        while(AuxiliarSondas->pProx != NULL){
            while(PesoAtual(&AuxiliarSondas->Sonda.CompartmentoS)>Med){
                if(AuxiliarSondas->Sonda.CompartmentoS.primeiro->pProx->pProx != NULL){
                    InsereRocha(&ComTemporario, RemoveRocha(&AuxiliarSondas2->Sonda.CompartmentoS,
                     &AuxiliarSondas2->Sonda.CompartmentoS.ultimo->rocha), PESOMAXIMO);
                    AuxiliarSondas2 = AuxiliarSondas2->pProx;
            }

            AuxiliarSondas = AuxiliarSondas->pProx;
        }

        AuxiliarSondas = lista->pPrimeiro->pProx;

        while(AuxiliarSondas->pProx != NULL){
            while(PesoAtual(&AuxiliarSondas->Sonda.CompartmentoS)<Med){
                if(!VerificaListaVazia(&ComTemporario)){
                    InsereRocha(&AuxiliarSondas2->Sonda.CompartmentoS, &ComTemporario.ultimo->rocha, AuxiliarSondas2->Sonda.CompartmentoS.PesoMax);
                    RemoveRocha(&ComTemporario, &ComTemporario.ultimo->rocha);
                    AuxiliarSondas2 = AuxiliarSondas2->pProx;
            }

            AuxiliarSondas = AuxiliarSondas->pProx;
            }
        }
    }
}
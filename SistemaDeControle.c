#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <locale.h>

#include "SistemaDeControle.h"



#define STRING 100
#define Data 11

const double PESOMAXIMO = 10000.0;

void Central(TSondas *ListaSondas){
    setlocale(LC_ALL, "Portuguese_Brazil");
    printf("Bem-vindo(a) ao Sistema de Controle e Cataloga��o de Rochas Minerais!\n");

    printf("Como voce deseja realizar a entrada de dados?\n");
    printf("(1)Arquivo.\n(2)Terminal.\n");
    int escolha;
    scanf("%d", &escolha);
    switch (escolha){
        case 1:
            LeituraPorArquivo(ListaSondas);
            break;
        case 2:
            LeituraPeloTerminal(ListaSondas);
            break;
        default:
            break;
    }
}


int LeituraPorArquivo(TSondas *ListaSondas){
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
    FazListaVazia(ListaSondas);
    for(int i = 0; i<numsondas;i++){
        Sonda NovaSonda;
        identificador = i+1;
        fscanf(entrada,"%lf %lf %d %d %d", &lat_i, &long_i, &c_i, &v_i, &vc_i);
        InicializaSonda(&NovaSonda, lat_i, long_i, c_i, v_i, vc_i, identificador);
        InsereSonda(ListaSondas, &NovaSonda);
    }

    int numoperacoes;
    char operacao;
    double latrocha, longrocha, pesorocha; 
    char mineral1[STRING];
    char mineral2[STRING];
    char mineral3[STRING];
    
    fscanf(entrada,"%d", &numoperacoes);
    ListaMinerais ListaMineirais;
    IniVListaM(&ListaMineirais);
    for(int i=0;i<numoperacoes;i++){

        double Distancias[numsondas];
        fscanf(entrada, "%c", operacao);
        switch(operacao){

        case 'R':
            fscanf(entrada,"%lf %lf %d %s %s %s", &latrocha, &longrocha, &pesorocha, mineral1, mineral2, mineral3);
            if(strcmp(mineral1, "/n")!=0){
                InsMineral(&ListaMineirais, mineral1);
            }
            if(strcmp(mineral2, "/n")!=0){
                InsMineral(&ListaMineirais, mineral2);
            }
            if(strcmp(mineral3, "/n")!=0){
                InsMineral(&ListaMineirais, mineral3);
            }

            RochaMineral RochaTeste;
            InicializaRocha(&RochaTeste, pesorocha, &ListaMineirais, 
             latrocha, longrocha, ctime(&mytime)); /*Inicializa uma rocha nova a 
                                                    partir da linha do arquivo*/
            
            

            Apontador AuxLis = ListaSondas->pPrimeiro;

            for(int i = 0; i > numsondas; i++){
                Distancias[i] = CalculaDist(AuxLis->Sonda, RochaTeste);
                AuxLis = AuxLis->pProx;
            } /*preenche as dist�ncias relativas das sondas at� a rocha*/

            double MenorDist = Distancias[0];
            int IndDes;

            for(int j = 0; j > numsondas; j++){
                if(MenorDist > Distancias[i]){
                    MenorDist = Distancias[i];
                    IndDes = j+1;
                }
            } /*acha o identificador da sonda de menor dist�ncia*/

            
            Apontador pAux;
            pAux = ListaSondas->pPrimeiro->pProx;

            while(pAux->Sonda.Identificador != IndDes){
                pAux = pAux->pProx;
            } /*A partir do identificador acha o ender�o de mem�ria da sonda de menor dist�ncia*/
            
            InsereRocha(&pAux->Sonda.CompartmentoS, &RochaTeste, pAux->Sonda.CompartmentoS.PesoMax);
            /*Insere a rocha nessa sonda*/
            
            break;
        case 'I':
            ImprimeSonda(ListaSondas);
            break;
        case 'E':
            RedistribuiRochas(ListaSondas, numsondas);
            break;
        }
    }
    fclose(entrada);
    return 0;
}

int numsondas = 0;

int LeituraPeloTerminal(TSondas *ListaSondas){

    char data[Data];
    time_t mytime;
    mytime = time(NULL);
    

    if(numsondas==0){

        printf(" Bem-vindos às central de Inicialização de Sondas.\n"
        "Esta operacao ir� criar uma nova sonda de acordo com os atributos digitados.\n"
        "A sonda tambem ser� ligada e disparada para o solo Marciano.\n"
        "Quantas sondas gostaria de iniciar? ");
        
        int sondas;
        scanf("%d", &sondas);
        numsondas += sondas;
        for(int s = 0; s < numsondas; s++){
            Sonda NovaSonda;
            
            double lat_i, long_i;
            int  c_i, v_i, nc_i, identificador = s+1;
            printf("Digite as informa��es da sonda %d:\n", s+1);
            getchar();

            printf("Latitude:");
            scanf("%lf", &lat_i);
            getchar();
            
        
            printf("Longitude:");
            scanf("%lf", &long_i);
            getchar();
           
            printf("Capacidade de armazenamento em kg:");
            scanf("%d", &c_i);

            printf("Velocidade:");
            scanf("%d", &v_i);

            printf("Nivel de combust�vel:");
            scanf("%d", &nc_i);

            InicializaSonda(&NovaSonda, lat_i, long_i, c_i,
             v_i, nc_i, identificador);

             printf("identificador dessa sonda: %d\n", identificador);

            InsereSonda(ListaSondas,&NovaSonda);

            LigaSonda(&NovaSonda);

        }
        printf("Inicializando informações...\n");
    }

    
    printf("Qual operação deseja realizar?\n");
    printf("(1)Inicializção de rochas.\n"
    "(2)Redistribuição de rochas.\n"
    "(3)Impressão do estado atual das sondas.\n");
    int escolha; 
    scanf("%d", &escolha);

    if(escolha == 1){
            ListaMinerais ListaMineirais;

            IniVListaM(&ListaMineirais);

            printf("Esta operacao irá coletar a rocha de acordo com os atributos digitados,\n"
            "Alem de adicion�-la na sonda mais pr�xima.\n"
            "Quantas rochas gostaria de coletar? ");
            int numrochas;
            scanf("%d", &numrochas);
            for(int r = 0; r <numrochas; r++){
                double latrocha, longrocha, pesorocha; 
        

                printf("Digite as informa��es da rocha %d:\n", r+1);

                printf("Latitude:");
                scanf("%lf", &latrocha);
                getchar();

                printf("Longitude:");
                scanf("%lf", &longrocha);
                getchar();

                printf("Peso da rocha:");
                scanf("%lf", &pesorocha);
                getchar();
             

                char TodosMinerais[300];
                char nome[100];
                int j = 0;
                printf("Digite at� tr�s minerais separados por espa�os:\n");

                fgets(TodosMinerais, sizeof(TodosMinerais), stdin);

                for (int i = 0; i < STRING; i++) {
                    if ((TodosMinerais[i] == ' ') || (TodosMinerais[i] == '\n') || (TodosMinerais[i] == '\0')) {
                        nome[j] = '\0'; 
                        if (strlen(nome) > 0) { 
                            InsMineral(&ListaMineirais, nome);
                            j = 0; 
                        }
                        if (TodosMinerais[i] == '\n' || TodosMinerais[i] == '\0') {
                            break;
                        }   
                    } 
                    else {
                        nome[j] = TodosMinerais[i];
                        j++;
                    }
                }


                RochaMineral RochaTeste;

                InicializaRocha(&RochaTeste, pesorocha, &ListaMineirais,
                latrocha, longrocha, ctime(&mytime));  /*Inicializa uma rocha nova a 
                                                                                partir do que o usuário digita*/  

                IniVListaM(&ListaMineirais);
                                                                          
                double Distancias[numsondas];       /*Vetor para armazenar as distâncias das sondas em relação à rocha*/

                Apontador AuxLis = ListaSondas->pPrimeiro->pProx;

                Apontador Memorias[numsondas]; /*Armazenando as sondas em um vetor pra poder usar o índicie*/

                for(int i = 0; i < numsondas; i++){

                    Distancias[i] = CalculaDist(AuxLis->Sonda, RochaTeste);
                    Memorias[i] = AuxLis;
                    AuxLis = AuxLis->pProx;
                } /*Percorre a lista de sondas armazenando as dist�ncia ralativas*/

                    double MenorDist = Distancias[0];
                    int IndDes = 1;


                    for(int j = 0; j < numsondas; j++){
                        for(int f = 0; f <numsondas-1;f++){
                            if(Distancias[f+1] < Distancias[f]){
                                double aux = Distancias[f];
                                Distancias[f] = Distancias[f+1];
                                Distancias[f+1] = aux;
                                Apontador auxp = Memorias[f];
                                Memorias[f] = Memorias[f+1];
                                Memorias[f+1] = auxp;
                                //IndDes = j+1;
                            }
                        } 
                    } /*Ordena o vetor das distâncias da menor para a maior e junto as sondas*/

                        Apontador MemoriaQueQueremos;

                        MemoriaQueQueremos = Memorias[0];

                     
                    for(int d = 0; d < numsondas; d++){
                        if(PesoAtual(&MemoriaQueQueremos->Sonda.CompartmentoS) + RochaTeste.Peso <= MemoriaQueQueremos->Sonda.CompartmentoS.PesoMax){
                            
                            MoveSonda(&MemoriaQueQueremos->Sonda, RochaTeste.Latitude, RochaTeste.Longitude);

                            InsereRocha(&MemoriaQueQueremos->Sonda.CompartmentoS, &RochaTeste, MemoriaQueQueremos->Sonda.CompartmentoS.PesoMax);
                            /*Insere a rocha no compartimento da sonda com menor dist�ncia*/
                            break;
                        } else {
                            MemoriaQueQueremos = Memorias[d+1];
                            }
                        }
                    }
                
        printf("Deseja realizar outra opera��o?(s/n)");
        char res1;
        scanf("%c", &res1);
        if(res1 == 's'){
            LeituraPeloTerminal(ListaSondas);
        }
        else{
            return 0;
            } 
               
    } else if(escolha == 3) {
            printf("Esta operca��o irá imprimir as informa��es das rochas coletadas at� o momento,\n"
            "al�m da identifica��o de qual sonda ela est� armazenda.\n");

            ImprimeSonda(ListaSondas);

            printf("Deseja realizar outra opera��o?(s/n)\n");
            getchar();
            char res3;
            scanf("%c", &res3);
            if(res3 == 's'){
                LeituraPeloTerminal(ListaSondas);
            }
            else{
                return 0;
            }
        } else if(escolha == 2){
            printf("Esta fun��o ir� mover todas as sondas para o ponto (0,0) e redistrubuir as rochas entre elas.\n"
            "Com o intuito de que cada sonda fique com aproximadamente a m�dia do peso total delas.\n");

                RedistribuiRochas(ListaSondas, numsondas);

                printf("Deseja realizar outra operacao?(s/n)\n");
                getchar();
                char res3;
                scanf("%c", &res3);
                if(res3 == 's'){
                    LeituraPeloTerminal(ListaSondas);
                }
                else{
                    return 0;
                }    
        }

     
    return 0;
}

void RedistribuiRochas(TSondas *ListaSondas, int numsondas){
    double PesoTotal = 0; 

    Apontador AuxiliarSondas = ListaSondas->pPrimeiro->pProx;

    while (AuxiliarSondas != NULL){

            MoveSonda(&AuxiliarSondas->Sonda,0,0); /*Move as sondas ao ponto (0,0)*/

            PesoTotal += PesoAtual(&AuxiliarSondas->Sonda.CompartmentoS); /*Calcula o Peso conjunto de todas as Sondas*/

            AuxiliarSondas = AuxiliarSondas->pProx; /*Percorre a Lista*/
        }

        double Med = PesoTotal/numsondas;

        Compartimento ComTemporario;
        
        CriaListaRocha(&ComTemporario, PESOMAXIMO);

        AuxiliarSondas = ListaSondas->pPrimeiro->pProx;

        while(AuxiliarSondas != NULL){
            while(PesoAtual(&AuxiliarSondas->Sonda.CompartmentoS) > Med) {
                if (AuxiliarSondas->Sonda.CompartmentoS.primeiro->pProx->pProx != NULL) {
                     // Verifica se há mais de uma rocha no compartimento   
                    InsereRocha(&ComTemporario,
                                RemoveRocha(&AuxiliarSondas->Sonda.CompartmentoS, &AuxiliarSondas->Sonda.CompartmentoS.ultimo->rocha),
                                PESOMAXIMO);
                } else {
                    break; 
                }
                
            }  
            if(AuxiliarSondas->pProx == NULL){
                break;
            }
            AuxiliarSondas = AuxiliarSondas->pProx;
        }


        AuxiliarSondas = ListaSondas->pPrimeiro->pProx;

        Apontador AuxiliarSondas2 = AuxiliarSondas;
        
        while (AuxiliarSondas != NULL) {

            // Itera enquanto o peso atual do compartimento é menor ou igual a média
            while (PesoAtual(&AuxiliarSondas->Sonda.CompartmentoS) <= Med) {
                printf("o peso do %d é menor que a media\n", AuxiliarSondas->Sonda.Identificador);

                // Verifica se o compartimento temporário não está vazio
                if (!VerificaListaVazia(&ComTemporario)) {

                    //verifica se a sonda comporta a rocha
                    if(PesoAtual(&AuxiliarSondas->Sonda.CompartmentoS)+ComTemporario.ultimo->rocha.Peso
                    <= AuxiliarSondas->Sonda.CompartmentoS.PesoMax){

                        // Insere a última rocha do compartimento temporário no compartimento da sonda

                        RochaMineral *RochaRemovida = RemoveRocha(&ComTemporario, &ComTemporario.ultimo->rocha);
                        InsereRocha(&AuxiliarSondas->Sonda.CompartmentoS,
                                    RochaRemovida, 
                                    AuxiliarSondas->Sonda.CompartmentoS.PesoMax);

                        printf("compartimento %d\n", AuxiliarSondas->Sonda.Identificador);
                        ImprimiLista(&AuxiliarSondas->Sonda.CompartmentoS);

                    } else {
                        //Faz sair do primeiro while se a sonda não comporta
                        break;
                    }
                } else {
                    AuxiliarSondas = ListaSondas->pUltimo->pProx; //eu acho que isso é o problema, trate
                    break; // Sai do loop se o compatimento estiver vazio
                }
            }
                // Move para o próximo nó na lista de sondas
                AuxiliarSondas = AuxiliarSondas->pProx;
            }
}
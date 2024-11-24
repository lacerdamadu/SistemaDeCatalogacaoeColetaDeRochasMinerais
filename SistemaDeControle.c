#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "SistemaDeControle.h"

#define STRING 100
#define Data 11

const double PESOMAXIMO = 10000.0;

void Central(TSondas *ListaSondas){
   
    printf("Bem-vindo(a) ao Sistema de Controle e Catalogacao de Rochas Minerais!\n");
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
    double lat_i, long_i, c_i;
    int v_i, vc_i, identificador;
    
    fscanf(entrada,"%d", &numsondas);
    FazListaVazia(ListaSondas);
    for(int m = 0; m<numsondas;m++){
        Sonda NovaSonda;
        identificador = m+1;
        fscanf(entrada,"%lf %lf %lf %d %d", &lat_i, &long_i, &c_i, &v_i, &vc_i);
        InicializaSonda(&NovaSonda, lat_i, long_i, c_i, v_i, vc_i, identificador);
        InsereSonda(ListaSondas, &NovaSonda);
        LigaSonda(&NovaSonda);
    }
    
    char numoperacoes[STRING];
    char linha1[STRING];
    char ope;
    double latrocha, longrocha, pesorocha; 
    char mineral1[STRING];
    char mineral2[STRING];
    char mineral3[STRING];
    char *ptr;
    int numoperacoes1 = 0;

    fscanf(entrada,"%d", &numoperacoes1);

    char aux;
    fscanf(entrada, "%c", &aux);//Pega o \n da linha anterior

    for(int jk=0;jk<numoperacoes1;jk++){
 
        fscanf(entrada,"%c", &ope);
        fscanf(entrada, "%c", &aux);//Pega o \n da linha anterior
        
        char linha2[STRING];
        if(ope == 'R'){
            ListaMinerais listaMinerais;
            IniVListaM(&listaMinerais);
            fgets(linha2, sizeof(linha2), entrada);//A funcao fgets le uma linha inteira e armazena em um vetor de char

            //Variaveis auxiliares
            char lat[STRING], lont[STRING], pes[STRING];
            char* pt;
            int cont = 1;

            strcpy(mineral1, "NAO TEM NADA");
            strcpy(mineral2, "NAO TEM NADA");
            strcpy(mineral3, "NAO TEM NADA");

            //Separa a linha em strings de acordo com os espacos
            pt = strtok(linha2," ");
            while(pt != NULL){
                if(pt[0]=='\n'){
                    break;
                }
                if(cont==1){
                    strcpy(lat, pt);   
                }
                if(cont==2){
                    strcpy(lont, pt);
                }
                if(cont==3){
                    strcpy(pes, pt);
                }
                if(cont==4){
                    strcpy(mineral1, pt);
                }
                if(cont==5){
                    strcpy(mineral2, pt);
                }
                if(cont==6){
                    strcpy(mineral3, pt);
                }
                cont++;
                pt = strtok(NULL," ");
            }
            //Transforma as Strings que armazenam os valores de longitude, latitude e peso em double
            latrocha = atof(lat);
            longrocha = atof(lont);
            pesorocha = atof(pes);
           
            //Verifica se ha um nome de mineral na string, inicializa um mineral e o insere na lista de minerais
            if(strcmp(mineral1, "NAO TEM NADA")!=0){
                InsMineral(&listaMinerais, mineral1);
            }
            if(strcmp(mineral2, "NAO TEM NADA")!=0){
                InsMineral(&listaMinerais, mineral2);
            }
            if(strcmp(mineral3, "NAO TEM NADA")!=0){
                InsMineral(&listaMinerais, mineral3);
            }
            //Chama a função coleta que tem por intuito encontrar qual a melhor sonda para armazenar a rocha
            Coleta(&listaMinerais, ListaSondas, numsondas, pesorocha, latrocha, longrocha);
            EsvaziaLista(&listaMinerais);  
        }
        
        if(ope == 'I'){
            ImprimeSonda(ListaSondas);
        }
        if(ope =='E'){
            RedistribuiRochas(ListaSondas, numsondas);
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

        printf("Bem-vindos a central de Inicializacao de Sondas!\n"
        "O primeiro passo e criar as sondas necessarias para a analise do solo Marciano."
        "Esta operacao ira criar uma nova sonda de acordo com os atributos digitados.\n"
        "A sonda tambem sera ligada e disparada para o solo Marciano.\n"
        "Quantas sondas gostaria de iniciar?");
        
    
        scanf("%d", &numsondas);
        printf("\n");
        for(int s = 0; s < numsondas; s++){
            Sonda NovaSonda;
            
            double lat_i, long_i, c_i;
            int v_i, nc_i, identificador = s+1;
            printf("Digite as informacoes da sonda %d:\n", s+1);
            getchar();

            printf("Latitude:");
            scanf("%lf", &lat_i);
            getchar();
            
        
            printf("Longitude:");
            scanf("%lf", &long_i);
            getchar();
           
            printf("Capacidade de armazenamento em kg:");
            scanf("%lf", &c_i);

            printf("Velocidade:");
            scanf("%d", &v_i);

            printf("Nivel de combustivel:");
            scanf("%d", &nc_i);

            InicializaSonda(&NovaSonda, lat_i, long_i, c_i,
             v_i, nc_i, identificador);

            printf("Identificador dessa sonda: %d\n", identificador);

            InsereSonda(ListaSondas,&NovaSonda);

            LigaSonda(&NovaSonda);
            printf("\n");

        }
        printf("Inicializando informacoes...\n");
    }

    
    printf("Qual operacao deseja realizar?\n");
    printf("(1)Inicializacao de rochas.\n"
    "(2)Redistribuicao de rochas.\n"
    "(3)Impressao do estado atual das sondas.\n");
    int escolha; 
    scanf("%d", &escolha);

    if(escolha == 1){
            ListaMinerais ListaMineirais;

            IniVListaM(&ListaMineirais);

            printf("Esta operacao ira coletar a rocha de acordo com os atributos digitados,\n"
            "Alem de adiciona-la na sonda mais proxima.\n"
            "Quantas rochas gostaria de coletar? ");
            int numrochas;
            scanf("%d", &numrochas);
            printf("\n");
            for(int r = 0; r <numrochas; r++){
                double latrocha, longrocha, pesorocha; 
        

                printf("Digite as informaces da rocha %d:\n", r+1);

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
                printf("Digite ate tres minerais separados por espacos:\n");

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

                //Chama a função coleta que tem por intuito encontrar qual a melhor sonda para armazenar a rocha
                Coleta(&ListaMineirais, ListaSondas, numsondas, pesorocha, latrocha, longrocha);
                EsvaziaLista(&ListaMineirais);
                printf("\n");
            }    
        printf("Deseja realizar outra operacao?(s/n)");
        char res1;
        scanf("%c", &res1);
        if(res1 == 's'){
            LeituraPeloTerminal(ListaSondas);
        }
        else{
            return 0;
        } 
    }
    else if(escolha == 3) {
            printf("Esta opercacao ira imprimir as informacoes das rochas coletadas ate o momento,\n"
            "alem da identificacao de qual sonda ela esta armazenda.\n");

            ImprimeSonda(ListaSondas);

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
        else if(escolha == 2){
            printf("Esta funcao ira mover todas as sondas para o ponto (0,0) e redistrubuir as rochas entre elas.\n"
            "Com o intuito de que cada sonda fique com aproximadamente a media do peso total delas.\n\n");
                int m = 1;
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

    double Med = PesoTotal/(double)numsondas;

    Compartimento ComTemporario;
        
    CriaListaRocha(&ComTemporario, PESOMAXIMO);

    AuxiliarSondas = ListaSondas->pPrimeiro->pProx;

    Celula* RochaEmQuestao;
    //Percorre as sondas
    while(AuxiliarSondas != NULL){
        RochaEmQuestao = AuxiliarSondas->Sonda.CompartmentoS.primeiro->pProx;
        //Começa da primeira rocha de cada compartimento

        while(PesoAtual(&AuxiliarSondas->Sonda.CompartmentoS) > Med+5){
        //Itera quando o peso da sonda sendo percorrida é maior que a média + 5

            while(RochaEmQuestao->pProx != NULL){
            // Itera até chegar na penúltima rocha do compartimento
                  
                if(VerificaSeTemQuemReceber(ListaSondas, &AuxiliarSondas->Sonda.CompartmentoS, RochaEmQuestao->rocha.Peso)){
                    //Vê se tem outra sonda pra ficar com a rocha sendo percorrida

                    Celula* RochaRemovida = RemoveRocha(&AuxiliarSondas->Sonda.CompartmentoS,
                    RochaEmQuestao);

                    InsereRocha(&ComTemporario,RochaRemovida,PESOMAXIMO);
                }

                if(PesoAtual(&AuxiliarSondas->Sonda.CompartmentoS) <= Med + 5){
                        break;
                    }
                RochaEmQuestao = RochaEmQuestao->pProx;
            }  
        break;
        }

    AuxiliarSondas = AuxiliarSondas->pProx;
    }

    Sonda *VetorSondas[numsondas];
    
    PreencheVetor(ListaSondas, VetorSondas, numsondas);
      
    AuxiliarSondas = ListaSondas->pPrimeiro->pProx;

    OrdenaPesos(VetorSondas, numsondas);

    int ver = 0;
        
    int indm = VetorSondas[0]->Identificador;

    while (AuxiliarSondas != NULL) {

        if(!VerificaListaVazia(&ComTemporario)){

            if(PesoAtual(&AuxiliarSondas->Sonda.CompartmentoS)+ComTemporario.ultimo->rocha.Peso
                <= AuxiliarSondas->Sonda.CompartmentoS.PesoMax &&
                AuxiliarSondas->Sonda.Identificador == VetorSondas[ver]->Identificador){ 

                    if(VerificaRochaExistente(&AuxiliarSondas->Sonda.CompartmentoS, &ComTemporario.ultimo->rocha)){

                        TrocaRocha(&AuxiliarSondas->Sonda.CompartmentoS, &ComTemporario.ultimo->rocha);
                        Celula* RochaRemovida = RemoveRocha(&ComTemporario, ComTemporario.ultimo);

                        PreencheVetor(ListaSondas, VetorSondas, numsondas);
                        OrdenaPesos(VetorSondas, numsondas);
                        ver = 0;

                        if(VerificaListaVazia(&ComTemporario)){
                            break;
                        }
    
                    }
                    else {
                        Celula* RochaRemovida = RemoveRocha(&ComTemporario, ComTemporario.ultimo);

                        InsereRocha(&AuxiliarSondas->Sonda.CompartmentoS,
                        RochaRemovida, AuxiliarSondas->Sonda.CompartmentoS.PesoMax);

                        PreencheVetor(ListaSondas, VetorSondas, numsondas);
                        OrdenaPesos(VetorSondas, numsondas);
                        ver = 0;
                        if(VerificaListaVazia(&ComTemporario)){
                            break;
                        }
                    }

                    if(!VerificaListaVazia(&ComTemporario) && AuxiliarSondas->pProx == NULL){
                    AuxiliarSondas = ListaSondas->pPrimeiro->pProx;
                    }
                }
                else if(PesoAtual(&AuxiliarSondas->Sonda.CompartmentoS)+ComTemporario.ultimo->rocha.Peso
                    > AuxiliarSondas->Sonda.CompartmentoS.PesoMax &&
                     AuxiliarSondas->Sonda.Identificador == indm){
                    //Caso seja a sonda de menor peso, mas não caiba a rocha nela, colocaremos na próxima de menor peso
                    ver++;

                    if(!VerificaListaVazia(&ComTemporario) && AuxiliarSondas->pProx == NULL){
                    AuxiliarSondas = ListaSondas->pPrimeiro->pProx;
                    }

                } 
                else {
                    AuxiliarSondas = AuxiliarSondas->pProx;
                } 
            }
            else {
                break;
            }
        }
}


int VerificaSeTemQuemReceber(TSondas *lista, Compartimento *Comp, double peso){

    int rec = 0;

    int iden;

    Apontador AuxiliarSondas = lista->pPrimeiro->pProx;

    while(AuxiliarSondas!= NULL){
        if(AuxiliarSondas->Sonda.CompartmentoS.PesoMax == Comp->PesoMax){
            iden = AuxiliarSondas->Sonda.Identificador;
        }
        AuxiliarSondas = AuxiliarSondas->pProx;
    }

    AuxiliarSondas = lista->pPrimeiro->pProx;

    while (AuxiliarSondas != NULL){
        if(AuxiliarSondas->Sonda.Identificador != iden){
            if(PesoAtual(&AuxiliarSondas->Sonda.CompartmentoS) + peso <= AuxiliarSondas->Sonda.CompartmentoS.PesoMax){
                rec = AuxiliarSondas->Sonda.Identificador;
                break;
            }
        }
        AuxiliarSondas = AuxiliarSondas->pProx;
    }
    return rec;
}

void OrdenaPesos(Sonda **Sondas, int numsondas){
    for(int i = 0; i< numsondas-1; i++){
        for(int j = 0; j < numsondas - 1 - i; j++){
            if(PesoAtual(&Sondas[j]->CompartmentoS)>PesoAtual(&Sondas[j+1]->CompartmentoS)){
                Sonda *auxiliar = Sondas[j];
                Sondas[j] = Sondas[j+1];
                Sondas[j+1] = auxiliar;
            }
        }
    }
}

void PreencheVetor(TSondas *Sondas, Sonda **VetorSondas, int numsondas){

    Apontador AuxiliarSondas = Sondas->pPrimeiro->pProx;

    for(int t = 0; t <numsondas; t++){
        VetorSondas[t] = &AuxiliarSondas->Sonda;
        AuxiliarSondas = AuxiliarSondas->pProx;
    }
}

void Coleta(ListaMinerais *ListaMineirais,TSondas *ListaSondas, int numsondas, double pesorocha, double latrocha, double longrocha){
    char data[Data];
    time_t mytime;
    mytime = time(NULL);
                 
                
    /*Inicializa uma rocha nova rocha a partir do que o usuário digita*/  
    Celula RochaTeste;
    InicializaRocha(&RochaTeste.rocha, pesorocha, ListaMineirais,
    latrocha, longrocha, ctime(&mytime));  

    /*Vetor para armazenar as distancias das sondas em relaçao a rocha*/                            
    double Distancias[numsondas];       
    Apontador AuxLis = ListaSondas->pPrimeiro->pProx;

    /*Armazenando as sondas em um vetor pra poder usar o indicie*/
    Apontador Memorias[numsondas]; 

    /*Percorre a lista de sondas armazenando as distancia relativas*/
    for(int i = 0; i < numsondas; i++){
        Distancias[i] = CalculaDist(AuxLis->Sonda, RochaTeste.rocha);
        Memorias[i] = AuxLis;
        AuxLis = AuxLis->pProx;
    } 

    double MenorDist = Distancias[0];
    int IndDes = 1;

    /*Ordena o vetor das distâncias da menor para a maior e junto as sondas*/
    for(int j = 0; j < numsondas-1; j++){
        for(int f = 0; f <numsondas-1-j;f++){
            if(Distancias[f+1] < Distancias[f]){
                double aux = Distancias[f];
                Distancias[f] = Distancias[f+1];
                Distancias[f+1] = aux;
                Apontador auxp = Memorias[f];
                Memorias[f] = Memorias[f+1];
                Memorias[f+1] = auxp;
            }
        } 
    } 
    
    Apontador MemoriaQueQueremos;

    /*Insere a rocha no compartimento da sonda com menor distancia*/
    for(int d = 0; d < numsondas; d++){
        MemoriaQueQueremos = Memorias[d];

        if(PesoAtual(&MemoriaQueQueremos->Sonda.CompartmentoS) + RochaTeste.rocha.Peso <= 
            MemoriaQueQueremos->Sonda.CompartmentoS.PesoMax){ 
            MoveSonda(&MemoriaQueQueremos->Sonda, RochaTeste.rocha.Latitude, RochaTeste.rocha.Longitude);
            InsereRocha(&MemoriaQueQueremos->Sonda.CompartmentoS, &RochaTeste, MemoriaQueQueremos->Sonda.CompartmentoS.PesoMax);
            break;
        }
    }
}
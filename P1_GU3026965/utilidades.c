#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "sorts.h"
#include "utilidades.h"

void linha(char formato, int tamanho){

    printf("\n ");
    for(int i = 0; i < tamanho; i++){
        printf("%c", formato);
    }
    printf("\n");

}

void gerarHeader(){

        system("cls");
        linha('#', 41);
        printf(" # Desempenho de Algoritmos de Ordenação #");
        linha('#', 41);

}

int checkResposta(int resposta, int valorMin, int valorMax){

    if(resposta >= valorMin && resposta <= valorMax){
        return 1;
    }
    return 0;

}

int obterQuantidade(){

    int op = -1;
    int resp = 0;

    do{

        system("cls");
        gerarHeader();

        printf("\n > Escolha a quantidade de amostras: \n\n\n");

        printf("    [ 1 ] 1.000 Amostras\n\n");
        printf("    [ 2 ] 5.000 Amostras\n\n");
        printf("    [ 3 ] 10.000 Amostras\n\n");
        printf("    [ 4 ] 20.000 Amostras\n\n");
        printf("    [ 5 ] 50.000 Amostras\n\n");
        printf("    [ 6 ] 100.000 Amostras\n\n");
        printf("    [ 0 ] Voltar\n\n\n");
        printf(" > Escolha uma opção: ");

        scanf("%d", &op);

        if(checkResposta(op, 1, 6)){

            switch(op){
                case 1:
                    resp = 1000;
                    break;
                case 2:
                    resp = 5000;
                    break;
                case 3:
                    resp = 10000;
                    break;
                case 4:
                    resp = 20000;
                    break;
                case 5:
                    resp = 50000;
                    break;
                case 6:
                    resp = 100000;
                    break;
            }
            op = 0;
        }
    }
    while(op);
    return resp;

}

int *gerarLista(int tamanho){

    srand((unsigned) time(NULL));

    int *lista = (int*) calloc(tamanho, sizeof(int));

    for(int i = 0; i < tamanho; i++){
        lista[i] = rand();
    }

    return lista;
}

double medirIntervalo(struct timeval Tempo_inicial, struct timeval Tempo_final){

    double deltaT = (Tempo_final.tv_sec + Tempo_final.tv_usec/1000000.0) - (Tempo_inicial.tv_sec + Tempo_inicial.tv_usec/1000000.0);
    return deltaT;

}

void amostrar(int *lista, char *descr){

    printf("    > Amostra: %s\n ", descr);

    for(int i = 0; i < 50; i++){

        printf(" %6d |", lista[i + 50] );

        if(!(i % 10)){printf("\n ");}
    }
    printf("\n\n");
}

void mostrarResultados(double *tempos, char *opNome, int quantidade, int *listaOriginal, int *listaOrganizada){

    double tempoMedio;
    int op = -1;

    for(int i = 0; i < 10; i++){ tempoMedio += tempos[i]; }
    tempoMedio /= 10;

    do{

        gerarHeader();

        printf("\n > Resultados: %s, %d itens\n\n", opNome, quantidade);

        for(int i = 0; i < 10; i++){

            printf("    -- %dª Operação: %fs.\n", i + 1, tempos[i]);

        }

        printf("    -- Tempo médio para cada operação: %fs.\n", tempoMedio);
        printf("    -- Tempo de operação para lista organizada: %fs.\n", tempos[10]);
        printf("    -- Tempo de operação para lista invertida: %fs.\n", tempos[11]);

        linha('-', 41);

        printf("\n    [ 1 ] Exibir Amostra    [ 0 ] Sair\n\n");
        printf("    > Escolha uma opção: ");
        scanf("%d", &op);

        if(op == 1){

            gerarHeader();
            printf(" > Resultados: %s\n\n", opNome);
            amostrar(listaOriginal, "Lista original");
            //amostrar(listaOrganizada, "Lista organizada");

            system("pause");

        }
    }
    while(op);

}

int executar(int op, int quant){

    struct timeval antes, depois;
    int *lista//, *listaOriginal, *listaInvertida, *listaFinal;
    double *t; // Lista para armazenar os tempos.
    char *opNome; // Nome da operação para ser exibido nos resultados

    t =  (double*) calloc(12, sizeof(int));  // Os índices de 0 a 9 armazenarão as 10 primeiras medições.
                                                             // Os índices 10 e 11 armazenarão, respectivamente, as medições
                                                             // para o comportamento natural e para o pior caso.
    system("cls");
    gerarHeader();
    printf("\n > Executando...\n\n");

    for(int i = 0; i < 10; i++){

        if(lista){}
        lista = gerarLista(quant);
    //    if(i == 9){listaOriginal = lista;} // Armazena última lista antes de organizar para verificação.

        if(!lista || !t){ return 0;}

        switch(op){

            case 1: //------------------------->

                gettimeofday(&antes, NULL);

               /// sortFunction(lista);

                gettimeofday(&depois, NULL);
                t[i] = medirIntervalo(antes, depois);
                printf("    --  T%d: %fs\n", i + 1, t[i]);

                if(i == 9){

                     gettimeofday(&antes, NULL);

                    // medição de tempo natural
                    ///sortfunction(lista);

                    gettimeofday(&depois, NULL);
                    t[10] = medirIntervalo(antes, depois);
                    printf("    --  T Natural: %fs\n", t[10]);

                    ///listaInvertida = inverterLista(lista);

                     gettimeofday(&antes, NULL);

                    // medição de tempo - pior caso
                    ///sortfunction(lista);

                    gettimeofday(&depois, NULL);
                    t[11] = medirIntervalo(antes, depois);
                    printf("    --  T Pior Caso: %fs\n", t[11]);

                    opNome = "Sorta";
                }
                free(lista);
            break;

            case 2: //------------------------->
                gettimeofday(&antes, NULL);

               bubbleSort(lista, quant);

                gettimeofday(&depois, NULL);
                t[i] = medirIntervalo(antes, depois);

                printf("    --  T%d: %fs\n", i + 1, t[i]);

                if(i == 9){
                     gettimeofday(&antes, NULL);

                    // medição de tempo natural
                    bubbleSort(lista, quant);

                    gettimeofday(&depois, NULL);
                    t[10] = medirIntervalo(antes, depois);
                    printf("    --  T Lista organizada: %fs\n", t[10]);

                    ///listaInvertida = inverterLista(lista);

                     gettimeofday(&antes, NULL);

                    // medição de tempo - pior caso
                    bubbleSort(lista, quant);

                    gettimeofday(&depois, NULL);
                    t[11] = medirIntervalo(antes, depois);
                    printf("    --  T Lista invertida: %fs\n", t[11]);

                    opNome = "Bubble Sort";
                }
            break;
        }

    }

    mostrarResultados(t, opNome, quant, listaOriginal, listaFinal);

    free(listaInvertida);
    free(listaOriginal);
    free(listaFinal);
    free(lista);
    free(t);

    return 0;
}

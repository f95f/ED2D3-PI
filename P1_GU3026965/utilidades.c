#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
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
        printf(" # Desempenho de Algoritmos de Ordena��o #");
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
        printf(" > Escolha uma op��o: ");

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

    for(int i = 0; i < 100; i++){

        printf(" %6d |", lista[i + 100] );

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

        printf(" > Resultados: %s, %d itens\n\n", opNome, quantidade);

        for(int i = 0; i < 10; i++){

            printf("    -- %d� Opera��o: %fs.\n", i + 1, tempos[i]);

        }

        printf("    -- Tempo m�dio para cada opera��o: %fs.\n", tempoMedio);
        printf("    -- Tempo de opera��o em caso natural: %fs.\n", tempos[10]);
        printf("    -- Tempo de opera��o: em pior caso: %fs.\n", tempos[11]);

        linha('-', 41);

        printf("\n    [ 1 ] Exibir Amostra    [ 0 ] Sair\n\n");
        printf("    > Escolha uma op��o: ");
        scanf("%d", &op);

        if(op == 1){

            gerarHeader();
            printf(" > Resultados: %s\n\n", opNome);
            amostrar(listaOriginal, "Lista original");
            amostrar(listaOrganizada, "Lista organizada");

            system("pause");

        }
    }
    while(op != 0);

}

int executar(int op, int quant){

    struct timeval antes, depois;
    int *lista, *listaOriginal, *listaInvertida;
    double *t; // Lista para armazenar os tempos.
    char *opNome; // Nome da opera��o para ser exibido nos resultados

    t =  (double*) calloc(12, sizeof(int));  // Os �ndices de 0 a 9 armazenar�o as 10 primeiras medi��es.
                                                             // Os �ndices 10 e 11 armazenar�o, respectivamente, as medi��es
                                                             // para o comportamento natural e para o pior caso.
    system("cls");
    gerarHeader();
    printf(" > Executando...\n\n");

    for(int i = 0; i < 10; i++){

        lista = gerarLista(quant);
        if(i == 9){listaOriginal = lista;} // Armazena �ltima lista antes de organizar para verifica��o.

        if(!lista || !t){ return 0;}

        switch(op){

            case 1:

                gettimeofday(&antes, NULL);

               /// sortFunction(lista);

                gettimeofday(&depois, NULL);
                t[i] = medirIntervalo(antes, depois);
                printf("    --  T%d: %fs\n", i + 1, t[i]);

                if(i == 9){

                     gettimeofday(&antes, NULL);

                    // medi��o de tempo natural
                    ///sortfunction(lista);

                    gettimeofday(&depois, NULL);
                    t[10] = medirIntervalo(antes, depois);
                    printf("    --  T Natural: %fs\n", t[10]);

                    ///listaInvertida = inverterLista(lista);

                     gettimeofday(&antes, NULL);

                    // medi��o de tempo - pior caso
                    ///sortfunction(lista);

                    gettimeofday(&depois, NULL);
                    t[11] = medirIntervalo(antes, depois);
                    printf("    --  T Pior Caso: %fs\n", t[11]);

                    opNome = "Sorta";
                    system("pause");
                }
            break;

        }

    }

    mostrarResultados(t, opNome, quant, listaOriginal, lista);

    free(lista);
    free(t);

    return 0;
}

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
        printf("    [ 7 ] 1.000.000 Amostras\n\n");
        printf("    [ 0 ] Voltar\n\n\n");
        printf(" > Escolha uma op��o: ");

        scanf("%d", &op);

        if(checkResposta(op, 1, 7)){

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
                case 7:
                    resp = 1000000;
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

int *copiarLista(int *lista, int tamanho){

    int *listaCopiada = (int*) calloc(tamanho, sizeof(int));

    for(int i = 0; i < tamanho; i++){

        listaCopiada[i] = lista[i];

    }

    return listaCopiada;
}

int *inverterLista(int *lista, int tamanho){

    int *listaInvertida = (int*) calloc(tamanho, sizeof(int));

    for(int i = tamanho -1, j = 0; i >= 0; i--, j++){

        listaInvertida[j] = lista[i];

    }

    return listaInvertida;
}

double medirIntervalo(struct timeval Tempo_inicial, struct timeval Tempo_final){

    double deltaT = (Tempo_final.tv_sec + Tempo_final.tv_usec/1000000.0) - (Tempo_inicial.tv_sec + Tempo_inicial.tv_usec/1000000.0);
    return deltaT;

}

void amostrar(int *lista, char *descr){
// Obtem uma amostra de 50 n�meros de uma lista e a exibe na tela.
// Esta fun��o foi implementada com a inten��o de verificar de forma simples a lista antes e depois
// de ordenada. Recebe para fins de identifica��o uma descri��o por par�metro e a exibe na tela.

    printf("    > Amostra: %s\n\n", descr);

    for(int i = 0; i < 50; i++){

        printf(" %6d |", lista[i] );
        if(i != 0 && !((i + 1) % 10)){printf("\n");}

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

            printf("    -- %d� Opera��o: %fs.\n", i + 1, tempos[i]);

        }

        printf("    -- Tempo m�dio para cada opera��o: %fs.\n", tempoMedio);
        printf("    -- Tempo de opera��o para lista organizada: %fs.\n", tempos[10]);
        printf("    -- Tempo de opera��o para lista invertida: %fs.\n", tempos[11]);

        linha('-', 41);

        printf("\n    [ 1 ] Exibir Amostra    [ 0 ] Sair\n\n");
        printf("    > Escolha uma op��o: ");
        scanf("%d", &op);

        if(op == 1){

            gerarHeader();
            printf("    > Resultados: %s\n\n", opNome);
            amostrar(listaOriginal, "Lista original");
            amostrar(listaOrganizada, "Lista organizada");

            system("pause");

        }
    }
    while(op);
}

int executar(int op, int quant){

    struct timeval antes, depois;
    int *lista, *listaOriginal, *listaInvertida, *listaOrganizada;
    double *t; // Lista para armazenar os tempos.
    char *opNome; // Nome da opera��o para ser exibido nos resultados

    t =  (double*) calloc(12, sizeof(double));  // Os �ndices de 0 a 9 armazenar�o as 10 primeiras medi��es.
                                                // Os �ndices 10 e 11 armazenar�o, respectivamente, as medi��es
                                                // para o comportamento natural e para o pior caso.
    system("cls");
    gerarHeader();
    printf("\n > Executando...\n\n");

    for(int i = 0; i < 10; i++){

        if(lista){}
        lista = gerarLista(quant);
        if(i == 9){listaOriginal = copiarLista(lista, quant);} // Armazena �ltima lista antes de organizar para verifica��o.

        if(!lista || !t){ return 0;}

        switch(op){
        case 1:

            // Shell sort

            gettimeofday(&antes, NULL);

                shellSort(lista, quant);

            gettimeofday(&depois, NULL);
            t[i] = medirIntervalo(antes, depois);

            printf("    --  T%d: %fs\n", i + 1, t[i]);

            if(i == 9){
                gettimeofday(&antes, NULL);

                    shellSort(lista, quant); // medi��o de tempo com a lista organizada

                gettimeofday(&depois, NULL);
                t[10] = medirIntervalo(antes, depois);

                printf("    --  T. Lista organizada: %fs\n", t[10]);

                listaOrganizada = copiarLista(lista, quant); // A lista utilizada no �ltimo ciclo � copiada antes de ser liberada da mem�ria.
                listaInvertida = inverterLista(lista, quant);

                gettimeofday(&antes, NULL);

                    shellSort(listaInvertida, quant); // medi��o de tempo com a lista invertida

                gettimeofday(&depois, NULL);
                t[11] = medirIntervalo(antes, depois);

                printf("    --  T. Lista invertida: %fs\n", t[11]);

                opNome = "Shell Sort";
            }
        break;

        case 2:

             // Bubble sort

            gettimeofday(&antes, NULL);

                bubbleSort(lista, quant);

            gettimeofday(&depois, NULL);
            t[i] = medirIntervalo(antes, depois);

            printf("    --  T%d: %fs\n", i + 1, t[i]);

            if(i == 9){

                gettimeofday(&antes, NULL);

                    bubbleSort(lista, quant); // medi��o com lista organizada

                gettimeofday(&depois, NULL);

                t[10] = medirIntervalo(antes, depois);
                printf("    --  T. Lista organizada: %fs\n", t[10]);

                listaOrganizada = copiarLista(lista, quant);
                listaInvertida = inverterLista(lista, quant);

                gettimeofday(&antes, NULL);

                    bubbleSort(listaInvertida, quant); // medi��o com lista invertida

                gettimeofday(&depois, NULL);

                t[11] = medirIntervalo(antes, depois);
                printf("    --  T. Lista invertida: %fs\n", t[11]);

                opNome = "Bubble Sort";
            }
        break;

        case 3:

            // Merge sort

            gettimeofday(&antes, NULL);

                mergeSort(lista, 0, quant);

            gettimeofday(&depois, NULL);

            t[i] = medirIntervalo(antes, depois);

            printf("    --  T%d: %fs\n", i + 1, t[i]);

            if(i == 9){

                gettimeofday(&antes, NULL);

                    mergeSort(lista, 0, quant); // medi��o com lista organizada

                gettimeofday(&depois, NULL);

                t[10] = medirIntervalo(antes, depois);
                printf("    --  T. Lista organizada: %fs\n", t[10]);

                listaOrganizada = copiarLista(lista, quant);
                listaInvertida = inverterLista(lista, quant);

                gettimeofday(&antes, NULL);

                    mergeSort(listaInvertida, 0, quant); // medi��o com lista invertida

                gettimeofday(&depois, NULL);

                t[11] = medirIntervalo(antes, depois);
                printf("    --  T. Lista invertida: %fs\n", t[11]);

                opNome = "Merge Sort";
            }
        break;

        case 4:

            // Insertion sort

            gettimeofday(&antes, NULL);

                insertionSort(lista, quant);

            gettimeofday(&depois, NULL);

            t[i] = medirIntervalo(antes, depois);

            printf("    --  T%d: %fs\n", i + 1, t[i]);

            if(i == 9){

                gettimeofday(&antes, NULL);

                    insertionSort(lista, quant); // medi��o de tempo com a lista organizada

                gettimeofday(&depois, NULL);
                t[10] = medirIntervalo(antes, depois);

                printf("    --  T. Lista organizada: %fs\n", t[10]);

                listaOrganizada = copiarLista(lista, quant); // A lista utilizada no �ltimo ciclo � copiada antes de ser liberada da mem�ria.
                listaInvertida = inverterLista(lista, quant);

                gettimeofday(&antes, NULL);

                    insertionSort(listaInvertida, quant); // medi��o de tempo com a lista invertida

                gettimeofday(&depois, NULL);
                t[11] = medirIntervalo(antes, depois);

                printf("    --  T. Lista invertida: %fs\n", t[11]);

                opNome = "Insertion Sort";
            }
        break;

        case 5:

            // Quick sort

            gettimeofday(&antes, NULL);

                quickSort(lista, 0, quant );

            gettimeofday(&depois, NULL);

            t[i] = medirIntervalo(antes, depois);

            printf("    --  T%d: %fs\n", i + 1, t[i]);

            if(i == 9){

                gettimeofday(&antes, NULL);

                    quickSort(lista, 0, quant); // medi��o com lista organizada

                gettimeofday(&depois, NULL);

                t[10] = medirIntervalo(antes, depois);
                printf("    --  T. Lista organizada: %fs\n", t[10]);

                listaOrganizada = copiarLista(lista, quant); // A lista utilizada no �ltimo ciclo � copiada antes de ser liberada da mem�ria.
                listaInvertida = inverterLista(lista, quant);

                gettimeofday(&antes, NULL);

                    quickSort(listaInvertida, 0, quant); // medi��o com lista invertida

                gettimeofday(&depois, NULL);

                t[11] = medirIntervalo(antes, depois);
                printf("    --  T. Lista invertida: %fs\n", t[11]);

                opNome = "Quick Sort";
            }
        break;

        case 6:

            // Selection sort

            gettimeofday(&antes, NULL);

                selectionSort(lista, quant);

            gettimeofday(&depois, NULL);
            t[i] = medirIntervalo(antes, depois);

            printf("    --  T%d: %fs\n", i + 1, t[i]);

            if(i == 9){

                gettimeofday(&antes, NULL);

                    selectionSort(lista, quant); // medi��o de tempo com a lista organizada

                gettimeofday(&depois, NULL);
                t[10] = medirIntervalo(antes, depois);

                printf("    --  T. Lista organizada: %fs\n", t[10]);

                listaOrganizada = copiarLista(lista, quant); // A lista utilizada no �ltimo ciclo � copiada antes de ser liberada da mem�ria.
                listaInvertida = inverterLista(lista, quant);

                gettimeofday(&antes, NULL);

                    selectionSort(listaInvertida, quant); // medi��o de tempo com a lista invertida

                gettimeofday(&depois, NULL);
                t[11] = medirIntervalo(antes, depois);

                printf("    --  T. Lista invertida: %fs\n", t[11]);

                opNome = "Selection Sort";
            }
        break;

        case 7:

            // Heap sort

            gettimeofday(&antes, NULL);

                heapSort(lista, quant);

            gettimeofday(&depois, NULL);
            t[i] = medirIntervalo(antes, depois);

            printf("    --  T%d: %fs\n", i + 1, t[i]);

            if(i == 9){

                gettimeofday(&antes, NULL);

                    heapSort(lista, quant); // medi��o de tempo com a lista organizada

                gettimeofday(&depois, NULL);
                t[10] = medirIntervalo(antes, depois);

                printf("    --  T. Lista organizada: %fs\n", t[10]);

                listaOrganizada = copiarLista(lista, quant); // A lista utilizada no �ltimo ciclo � copiada antes de ser liberada da mem�ria.
                listaInvertida = inverterLista(lista, quant);

                gettimeofday(&antes, NULL);

                    heapSort(listaInvertida, quant); // medi��o de tempo com a lista invertida

                gettimeofday(&depois, NULL);
                t[11] = medirIntervalo(antes, depois);

                printf("    --  T. Lista invertida: %fs\n", t[11]);

                opNome = "Heap Sort";
            }
        break;

        case 8:

            // Tim Sort

            gettimeofday(&antes, NULL);

                timSort(lista, quant);

            gettimeofday(&depois, NULL);
            t[i] = medirIntervalo(antes, depois);

            printf("    --  T%d: %fs\n", i + 1, t[i]);

            if(i == 9){

                gettimeofday(&antes, NULL);

                    timSort(lista, quant); // medi��o de tempo com a lista organizada

                gettimeofday(&depois, NULL);
                t[10] = medirIntervalo(antes, depois);

                printf("    --  T. Lista organizada: %fs\n", t[10]);

                listaOrganizada = copiarLista(lista, quant); // A lista utilizada no �ltimo ciclo � copiada antes de ser liberada da mem�ria.
                listaInvertida = inverterLista(lista, quant);

                gettimeofday(&antes, NULL);

                    timSort(listaInvertida, quant); // medi��o de tempo com a lista invertida

                gettimeofday(&depois, NULL);
                t[11] = medirIntervalo(antes, depois);

                printf("    --  T. Lista invertida: %fs\n", t[11]);

                opNome = "Tim Sort";
            }
        break;

        case 9:

            // Radix Sort

            gettimeofday(&antes, NULL);

                radixSort(lista, quant);

            gettimeofday(&depois, NULL);
            t[i] = medirIntervalo(antes, depois);

            printf("    --  T%d: %fs\n", i + 1, t[i]);

            if(i == 9){

                gettimeofday(&antes, NULL);

                    radixSort(lista, quant); // medi��o de tempo com a lista organizada

                gettimeofday(&depois, NULL);
                t[10] = medirIntervalo(antes, depois);

                printf("    --  T. Lista organizada: %fs\n", t[10]);

                listaOrganizada = copiarLista(lista, quant); // A lista utilizada no �ltimo ciclo � copiada antes de ser liberada da mem�ria.
                listaInvertida = inverterLista(lista, quant);

                gettimeofday(&antes, NULL);

                    radixSort(listaInvertida, quant); // medi��o de tempo com a lista invertida

                gettimeofday(&depois, NULL);
                t[11] = medirIntervalo(antes, depois);

                printf("    --  T. Lista invertida: %fs\n", t[11]);

                opNome = "Radix Sort";
            }
        break;
        }

        free(lista);
    }

    mostrarResultados(t, opNome, quant, listaOriginal, listaOrganizada);

    free(listaInvertida);
    free(listaOriginal);
    free(listaOrganizada);
    free(t);

    return 0;
}




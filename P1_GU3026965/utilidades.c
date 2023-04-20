#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "utilidades.h"

struct r{

};
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
                case 7:
                    resp = 100;
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

int executar(int op, int quant){

    int *lista;

    for(int i = 0; i < 10; i++){

        lista = gerarLista(quant);
        t = gerarLista(12);  // Lista para armazenar os tempos de execução do algoritmo
        if(!lista || !t){ return 0;}

        switch(op){

            case 1:

                // Iniciar contagem

                sortFunction(lista);

                // finalizar contagem

                if(i == 9){

                    //iniciar contagem

                    // medição de tempo natural
                    sortfunction(lista);

                    // finalizar contagem
                    // armazenar tempo total no indice ´[10] da lista de tempos

                    lista = inverterLista(lista);

                    //iniciar contagem

                    //medição de tempo pior caso
                    sort function(lista);

                    // finalziar contagem
                    // armazenar tempo total no indice ´[11] da lista de tempos
                }
            break;


        }
        // obter o tempo total, armazenar em uma lista
        t[i] = tempoTotal;
    }

    // imprimir resultados

    free(lista);
    free(t);

    return 0;
}

void amostrar(int *lista, char *descr){

    printf("    > Amostra: %s\n         ->", descr);

    for(int i = 100; i < 200; i++){

        printf(" %d |", lista[i]);

    }
    printf("\n\n");
}

void mostrarResultados(){

}

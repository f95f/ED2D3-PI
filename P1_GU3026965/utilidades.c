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

int obterQuantidade(char* titulo){

    int op = -1;
    int resp = 0;

    do{

        system("cls");
        gerarHeader();

        printf("\n > %s\n - Escolha a quantidade de amostras: \n\n\n", titulo);

        printf("    [ 1 ] 1.000 Amostras\n\n");
        printf("    [ 2 ] 5.000 Amostras\n\n");
        printf("    [ 3 ] 10.000 Amostras\n\n");
        printf("    [ 4 ] 20.000 Amostras\n\n");
        printf("    [ 5 ] 50.000 Amostras\n\n");
        printf("    [ 6 ] 100.000 Amostras\n\n");
        printf("    [ 0 ] Voltar\n\n\n");
        printf(" > Escolha uma opção: ");

        scanf("%d", &op);

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
        if(op > 0 && op < 8){op = 0;}
    }
    while(op);
    return resp;

}

int *gerarLista(int tamanho){

    int *lista = (int*) calloc(tamanho, sizeof(int));
    //int num, rando = rand();

    srand((unsigned) time(NULL));

    for(int i = 0; i < tamanho; i++){

        /*num = ((rand() << 1) & rando) | rando;
        num = num % 1000000;
        lista[i] = num;*/
        lista[i] = rand();
    }
    /*
    for(int i = 0; i < tamanho; i++){
        printf("%d\n", lista[i]);
    }
    system("pause");
    */
    return lista;
}

void mostrarResultados(){

}

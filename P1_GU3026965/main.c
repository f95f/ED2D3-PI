#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "utilidades.h"

void main(){

    setlocale(LC_ALL, "");
    int op = -1; // Operação
    int quant = -1; // Quantidade de elementos

    do{

        gerarHeader();

        printf("\n > Menu Principal\n");
        printf("\n\n    [ 0 ] Sair              [ 1 ] ShellSort");
        printf("\n\n    [ 2 ] BubbleSort        [ 3 ] MergeSort");
        printf("\n\n    [ 4 ] InsertionSort     [ 5 ] QuickSort");
        printf("\n\n    [ 6 ] SelectionSort     [ 7 ] HeapSort");
        printf("\n\n    [ 8 ] TimSort           [ 9 ] RadixSort");
        printf("\n\n\n > Escolha uma opção: ");
        scanf("%d", &op);

        switch(op){
            case 1:
                    quant = obterQuantidade("Shell Sort");
                    if(quant){ }   //chamar alg.
            break;
        }
    }
    while(op);

    system("cls");
    printf("\n > Aplicação encerrada.\n\n");
    linha('-', 41);
}

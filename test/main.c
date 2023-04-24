#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.h"

void main(){

    int tamanho = 10000;
    int amostra = 20;
    double* t = (double*) calloc(3, sizeof(double));
    struct timeval antes, depois;

    int *lista = vetorRand(tamanho);
    int *listaOrg= vetorOrg(tamanho);
    int *listaInv = vetorInv(tamanho);

//    mostrar(lista, amostra);
   // mostrar(listaOrg, amostra);
    //mostrar(listaInv, amostra);

    gettimeofday(&antes, NULL);
        //heapSort(lista, tamanho);
        quickSort(lista, 0, tamanho -1);
    gettimeofday(&depois, NULL);
    t[0] = medirIntervalo(antes, depois);

    gettimeofday(&antes, NULL);
        //heapSort(listaOrg, tamanho);
        quickSort(listaOrg, 0, tamanho -1);
    gettimeofday(&depois, NULL);
    t[1] = medirIntervalo(antes, depois);

    gettimeofday(&antes, NULL);
        //heapSort(listaInv, tamanho);
        quickSort(listaInv, 0, tamanho -1);
    gettimeofday(&depois, NULL);
    t[2] = medirIntervalo(antes, depois);

    printf(" > Quick:\n");
    mostrar(lista, amostra);
    printf("lista aleatória - tempo: %f", t[0]);
    mostrar(listaOrg, amostra);
    printf("lista organizada - tempo: %f", t[1]);
    mostrar(listaInv, amostra);
    printf("lista invertida - tempo: %f", t[2]);

    free(t);
    free(lista);
    free(listaInv);
    free(listaOrg);
}

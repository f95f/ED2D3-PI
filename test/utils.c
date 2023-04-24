#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "utils.h"

int *vetorRand(int tamanho){

    int *vetor = (int*) calloc(tamanho, sizeof(int));
    srand((unsigned) time(NULL));

    for(int i = 0; i < tamanho; i++){

        vetor[i] = rand() % tamanho +1;

    }

    return vetor;
}

int *vetorOrg(int tamanho){

    int *vetor = (int*) calloc(tamanho, sizeof(int));

    for(int i = 0; i < tamanho; i++){

        vetor[i] = i + 1;

    }

    return vetor;
}

int *vetorInv(int tamanho){

    int *vetor = (int*) calloc(tamanho, sizeof(int));

    for(int i = 0, j = tamanho; i < tamanho; i++, j--){

        vetor[i]= j;

    }

    return vetor;
}

void mostrar(int *vetor, int tamanho){
    printf("\n --- \n\n");
    for(int i = 0; i < tamanho; i++){

        printf(" %2d |", vetor[i]);

        if(i != 0 && !((i + 1) % 10)){printf("\n");}

    }
    printf("\n --- \n");

}

double medirIntervalo(struct timeval Tempo_inicial, struct timeval Tempo_final){

    double deltaT = (Tempo_final.tv_sec + Tempo_final.tv_usec/1000000.0) - (Tempo_inicial.tv_sec + Tempo_inicial.tv_usec/1000000.0);
    return deltaT;

}

void shellSort (int A[], int n){

    int i, j;
    int h = 1;
    int aux;
   //int ps = 1;

    do{
        h = h * 3 + 1;
    }
    while(h < n);

    do{
        h /= 3; /* h = (h - 1) / 3 */
        for(i = h; i < n; i++){

            aux = A[i];
            j = i;
            while(A[j - h] > aux){
                A[j] = A[j - h];
                j -= h;
                if(j < h) break;
            }
            A[j] = aux;

        }

    }
    while(h != 1);
}

void heapify(int vet[], int n, int i) {
    int max = i;
    int e = 2 * i + 1;
    int d = 2 * i + 2;

    if (e < n && vet[e] > vet[max])
        max = e;

    if (d < n && vet[d] > vet[max])
        max = d;

    if (max != i) {
        int aux = vet[i];
        vet[i] = vet[max];
        vet[max] = aux;
        heapify(vet, n, max);
    }
}
void heapSort(int vet[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(vet, n, i);

    for (int i = n - 1; i >= 0; i--) {
        int aux = vet[0];
        vet[0] = vet[i];
        vet[i] = aux;
        heapify(vet, i, 0);
    }
}

void quickSort(int *vetor, int inicio, int fim) {
    int pivo;

    if(fim > inicio) {
        pivo = particiona(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo-1);
        quickSort(vetor, pivo+1, fim);
    }
}
int particiona(int *vetor, int inicio, int fim) {
    int esquerda, direita, pivo, aux;

    esquerda = inicio;
    direita = fim;
    pivo = vetor[inicio];
    while(esquerda < direita) {
        while(vetor[esquerda] <= pivo)
            esquerda++;
        while(vetor[direita] > pivo)
            direita--;
        if(esquerda < direita) {
            aux = vetor[esquerda];
            vetor[esquerda] = vetor[direita];
            vetor[direita] = aux;
        }
    }
    vetor[inicio] = vetor[direita];
    vetor[direita] = pivo;

    return direita;
}

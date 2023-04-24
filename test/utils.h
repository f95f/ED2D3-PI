#include <stdio.h>
#include <stdlib.h>

int *vetorRand(int tamanho);
int *vetorOrg(int tamanho);
int *vetorInv(int tamanho);

void mostrar(int *vetor, int tamanho);
double medirIntervalo(struct timeval Tempo_inicial, struct timeval Tempo_final);

void shellSort (int A[], int n);
void heapSort(int vet[], int n);
void quickSort(int *vetor, int inicio, int fim);

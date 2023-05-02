#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"

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

void bubbleSort(int *vetor, int quant){

    int i, continua, aux, fim = quant;
    do{
        continua = 0;
        for(i = 0; i < fim -1; i++){
            if(vetor[i] > vetor[i +1]){
                aux = vetor[i];
                vetor[i] = vetor[i +1];
                vetor[i +1] = aux;

                continua = i;
            }
        }
        fim--;
    }
    while(continua != 0);
}

void selectionSort(int *v, int n){
    int i, j, menor, troca;
    for(i = 0; i < n - 1; i++){
        menor = i;
        for(j = i + 1; j < n; j++){
            if(v[j] < v[menor]){
                menor = j;
            }
        }
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}

void insertionSort(int *v, int n){
    int i, j, aux;

    for(i = 1; i < n; i++){
        aux = v[i];
        for(j = i; (j > 0) && (aux < v[j -1]); j--){
            v[j] = v[j -1];
        }
        v[j] = aux;
    }
}

void mergeSort(int arr[], int inicio, int fim){
    if (inicio < fim)
    {
        // Encontra o ponto médio para dividir o array em duas metades
        int meio = inicio + (fim - inicio) / 2;

        // Ordena a primeira e a segunda metade
        mergeSort(arr, inicio, meio);
        mergeSort(arr, meio + 1, fim);

        // Mescla as duas metades ordenadas
        merge(arr, inicio, meio, fim);
    }
}
void merge(int arr[], int inicio, int meio, int fim){
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Cria vetores temporários para os subvetores da esquerda e direita
    int INICIO[n1], FIM[n2];

    // Copia os dados para os vetores temporários
    for (i = 0; i < n1; i++)
        INICIO[i] = arr[inicio + i];
    for (j = 0; j < n2; j++)
        FIM[j] = arr[meio + 1 + j];

    // Intercala os dois vetores temporários de volta ao vetor original arr[l..r]
    i = 0; // Índice inicial do primeiro subvetor
    j = 0; // Índice inicial do segundo subvetor
    k = inicio; // Índice inicial do vetor mesclado

    while (i < n1 && j < n2)
    {
        if (INICIO[i] <= FIM[j])
        {
            arr[k] = INICIO[i];
            i++;
        }
        else
        {
            arr[k] = FIM[j];
            j++;
        }
        k++;
    }

    // Copia os elementos restantes de L[], se houver algum
    while (i < n1)
    {
        arr[k] = INICIO[i];
        i++;
        k++;
    }

    // Copia os elementos restantes de R[], se houver algum
    while (j < n2)
    {
        arr[k] = FIM[j];
        j++;
        k++;
    }
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
void quickSort(int *vetor, int inicio, int fim) {
    int pivo;

    if(fim > inicio) {
        pivo = particiona(vetor, inicio, fim);
        quickSort(vetor, inicio, pivo-1);
        quickSort(vetor, pivo+1, fim);
    }
}

int getMax(int *vetor, int n) {

    int max = vetor[0];
    for (int i = 1; i < n; i++) {
        if (vetor[i] > max) {
            max = vetor[i];
        }
    }
    return max;
}
void contar(int *vetor, int n, int exp) {
    int lista[n];
    int contagem[10] = {0};

    for (int i = 0; i < n; i++) {
        contagem[(vetor[i] / exp) % 10]++;
    }

    for (int i = 1; i < 10; i++) {
        contagem[i] += contagem[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        lista[contagem[(vetor[i] / exp) % 10] - 1] = vetor[i];
        contagem[(vetor[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        vetor[i] = lista[i];
    }
}
void radixSort(int *vetor, int n) {

    int max = getMax(vetor, n);

    for (int exp = 1; max / exp > 0; exp *= 10) {
        contar(vetor, n, exp);
    }
}

const int RUN = 64;
int minimo(int a, int b){

    if(a < b){
        return a;
    }
    else{
        return b;
    }
}
void timInsertion(int a[], int inicio, int fim){

    int i, j, temp;

    for (i = inicio + 1; i <= fim; i++) {

        temp = a[i];
        j = i - 1;

        while(j >= 0 && temp <= a[j]){

            a[j+1] = a[j];
            j = j-1;
        }
        a[j+1] = temp;
    }
}
void timMerge(int a[], int inicio, int meio, int fim){

    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    int vetorEsquerdo[n1], vetorDireito[n2];

    for (int i = 0; i < n1; i++) vetorEsquerdo[i] = a[inicio + i];
    for (int j = 0; j < n2; j++) vetorDireito[j] = a[meio +1 + j];

    i = 0;
    j = 0;
    k = inicio;

    while(i < n1 && j < n2){

        if(vetorEsquerdo[i] <= vetorDireito[j]){

            a[k] = vetorEsquerdo[i];
            i++;
        }
        else{

            a[k] = vetorDireito[j];
            j++;
        }
        k++;
    }
    while(i < n1){

        a[k] = vetorEsquerdo[i];
        i++;
        k++;
    }
    while(j < n2){

        a[k] = vetorDireito[j];
        j++;
        k++;
    }
}
void timSort(int a[], int n){

    for(int i = 0; i < n; i+=RUN) timInsertion(a, i, minimo((i + RUN -1), (n -1)));

    for(int size = RUN; size < n; size = 2*size){

        for(int inicio = 0; inicio < n; inicio += 2*size){

            int meio = inicio + size - 1;
            int fim = minimo((inicio + 2 * size - 1),(n-1));

            if(meio < fim) timMerge(a, inicio, meio, fim);
        }
    }
}

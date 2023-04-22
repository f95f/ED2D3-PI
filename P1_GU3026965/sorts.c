#include <stdio.h>
#include <stdlib.h>
#include "sorts.h"
#define min(a,b) (a)<(b)?(a):(b)

void shellSort (int *A, int n){

    int i, j;
    int h = 1;
    int aux;
    h = h * 3 + 1;

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

void heapify(int *vet, int n, int i) {
    int min = i;
    int e = 2 * i + 1;
    int d = 2 * i + 2;

    if (e < n && vet[e] < vet[min])
        min = e;

    if (d < n && vet[d] < vet[min])
        min = d;

    if (min != i) {
        int aux = vet[i];
        vet[i] = vet[min];
        vet[min] = aux;
        heapify(vet, n, min);
    }
}
void heapSort(int *vet, int n) {

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

void radix_sort_lsd(int arr[], int n) {

    int max_num = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max_num) {
            max_num = arr[i];
        }
    }

    int exp = 1;

    while (max_num / exp > 0) {
        int buckets[10][n];
        int bucket_sizes[10] = {0};

        for (int i = 0; i < n; i++) {
            int digit = (arr[i] / exp) % 10;
            buckets[digit][bucket_sizes[digit]] = arr[i];
            bucket_sizes[digit]++;
        }

        int k = 0;
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < bucket_sizes[i]; j++) {
                arr[k] = buckets[i][j];
                k++;
            }
        }

        exp *= 10;
    }
}
void insertionSortRun(int arr[], int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        int temp = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > temp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
void mergeRun(int arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    for (int i = 0; i < len1; i++)
        left[i] = arr[l + i];
    for (int i = 0; i < len2; i++)
        right[i] = arr[m + 1 + i];
    int i = 0;
    int j = 0;
    int k = l;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < len1) {
        arr[k] = left[i];
        k++;
        i++;
    }
    while (j < len2) {
        arr[k] = right[j];
        k++;
        j++;
    }
}
void timSort(int arr[], int n, int run) {
    for (int i = 0; i < n; i += run) {
        insertionSortRun(arr, i, min((i + 3), (n - 1)));
    }

    for (int size = run; size < n; size = 2 * size) {
        for (int left = 0; left < n; left += 2 * size) {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (n - 1));
            mergeRun(arr, left, mid, right);
        }
    }
}

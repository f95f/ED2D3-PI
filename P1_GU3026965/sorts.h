#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (a)<(b)?(a):(b)
void shellSort (int *A, int n); //-*
void bubbleSort(int *v, int n);
void selectionSort(int *v, int n);
void insertionSort(int *v, int n);
void mergeSort(int arr[], int inicio, int fim);
void heapSort(int *vet, int n); //-*
void quickSort(int *vetor, int inicio, int fim);//-*
void radix_sort_lsd(int arr[], int n);//-*
void timSort(int arr[], int n, int run);//-*

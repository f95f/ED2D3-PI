#include <stdio.h>

void ShellSort (int A[], int n){

    int i, j;
    int h = 1;
    int aux;
    int ps = 1;

    do h = h * 3 + 1;

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
            printf("\n\nVetor Sendo Ordenado (passagem: %d):\n", ps++);
            for(int k = 0; k < 6; k++){
                printf("%2d", A[k]);
            }
            printf("\nValor de H: %d\n", h);
            printf("\n");
            system("pause");
        }

    }
    while(h != 1);
}

int main(){
    printf("Funcao para calcular o valor de h");
    int A[6] = {1, 8, 6, 7, 9, 5};
    ShellSort(A, 6);
    printf("\n\nVetor Organizado:\n");
    for(int i = 0; i < 6; i++){
        printf("%2d", A[i]);
    }
    printf("\n\n");
}

#include <stdio.h>

int main(){

    int L[20], temp, i, j, n=6, m;
    printf("");
    for(i = 0; i < n; i++){
        printf("Insira o numero na posicao %d: ", i);
        scanf("%d", &L[i]);
    }

    printf("\n\nVetor desorganizado:\n");

    for(i = 0; i < n; i++){
        printf("%3d", L[i]);
    }

    for(m = n/2; m > 0; m /= 2){
        for(j = m; j < n; j++){
            for(i = j - m; i >= 0; i -= m){
                if(L[i+m] >= L[i]) break;
                else{
                    temp = L[i];
                    L[i] = L[i + m];
                    L[i + m] = temp;
                }
            }
        }
    }
    printf("\n\nVetor Organizado:\n");
    for(i = 0; i < n; i++){
        printf("%3d ", L[i]);
    }
    printf("\n");
}

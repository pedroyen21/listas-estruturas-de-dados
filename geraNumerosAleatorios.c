#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    printf("Quantos numeros deseja gerar? ");
    scanf("%d", &N);

    FILE *arq;
    arq = fopen("numerosAleatorios.txt", "wt");

    fprintf(arq, "%d\n", N);
    
    for(int i = 0; i < N; i++)  {
        fprintf(arq, "%d ", rand() % 100000000);
    } 

    fprintf(arq, "\n");
    fclose(arq);
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    float *notas = malloc(3 * sizeof(int));
    float media = 0;

    for(int i = 0; i < 3; i++) {
        scanf("%f", (notas + i)); 
    }

    for(int i = 0; i < 3; i++) {
        media += *(notas + i) ; 
    }      

    free(notas);
    media /= 3;
    printf("media: %.2f\n", media);
}
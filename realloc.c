#include <stdio.h>
#include <stdlib.h>

void verificar(int *v, int limite, int *soma, int i, int tamanho) {
    *soma += *(v);
    i += 1;
    if (i > tamanho) return;

    if (*soma > limite) {
        *soma = 0; 
        verificar(v + 1, limite, soma, i, tamanho);
        printf("%d ", *v);
        return;
    }
    verificar(v + 1, limite, soma, i, tamanho);
}

int main() {
    int n, tamanho = 0;
    scanf("%d", &n);
    int *ptr = malloc(0);

    for(int i = 0; n != 0; i++) {
        tamanho += 1;
        ptr = realloc(ptr, tamanho * sizeof(int));
        *(ptr + i) = n;
        scanf("%d", &n);
    }

    int limite, soma = 0;
    scanf("%d", &limite);
    int i = 0;
    verificar(ptr, limite, &soma, i, tamanho);
    printf("\n");

    free(ptr);
}
#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct {
    Item *v;
    int inicio;
    int fim;
    int capacidade;
} fila;

int filacheia(fila *f) {
    if((f->fim - f->inicio) == f->capacidade)
        return 1;
    else 
        return 0;
}

int filavazia(fila *f) {
    if(f->fim == f->inicio)
        return 1;
    else
        return 0; 
}

int enfila(fila *f, Item x) {
    if( !filacheia(f) ) 
        f->v[f->fim++ % f->capacidade] = x;
    else    
        return 0;
}

Item desenfila(fila *f) {
    if( !filavazia(f) ) 
        return f->v[f->inicio++ % f->capacidade];
    else 
        return 0;
}

int inicializafila(fila *f, int n) {
    f->inicio = 0;
    f->fim = 0;
    f->capacidade = n;
    f->v = malloc(sizeof(Item) * n);
    return 1;
}

int alimentafila(fila *f) {
    for(int i = 1; i <= f->capacidade; i++) {
        enfila(f, i);
    }
    return 1;
}
int main(void) {
    int N;
    scanf("%d", &N);

    fila f;
    inicializafila(&f, N);

    alimentafila(&f);

    fila descartados;
    inicializafila(&descartados, N - 1);

    int p = 2 * descartados.capacidade;
    while(--p) {
        
        if (p % 2 != 0) {
            enfila(&descartados, desenfila(&f));
        }
        else 
            enfila(&f, desenfila(&f));
    }

    printf("Cartas descartadas: ");
    for(int i = 0; i < 2*descartados.capacidade-1; i++){
        if(i % 2 == 0)
            printf("%d", descartados.v[i/2]);
        else 
            printf(", ");
    }

    printf("\n");

    printf("Carta restante: %d\n", desenfila(&f));

    free(f.v);
    free(descartados.v);
}

#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct {
    Item *v;
    int inicio;
    int fim;
    int tamanho;
}fila;

int estacheia(fila *f) {
    if(f->fim - f->inicio == f->tamanho)
        return 1; 
    else
        return 0;
}
int estavazia(fila *f) {
    if(f->inicio == f->fim)
        return 1; 
    else
        return 0;
}
int enfila(fila *f, Item x) {
    if( !estacheia(f) ) {
        f->v[f->fim++] = x;
        return 1;
    }
    else printf("Fila cheia\n");
}

Item desenfilera(fila *f) {
    if( !estavazia(f) ) {
        return f->v[f->inicio++];
    }
    else printf("Fila vazia\n");
}

int inicializa_fila(fila *f, int t) {
    f->inicio = 0;
    f->fim = 0;
    f->tamanho = t;
    f->v = malloc(sizeof(Item) * t);
    return 1;
}

void printafila(fila *f) {
    for(int i = f->inicio; i < f->fim; i++) {
        printf("[%d]\n", f->v[i]);
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    fila f;
    inicializa_fila(&f, n);

    int k;
    while(scanf("%d", &k) == 1) {
        if(k == -1) printf("%d", desenfilera(&f));
        else if(k == -2) printafila(&f);
        else {
            enfila(&f, k);
        }
    }


    fila aux;
    inicializa_fila(&aux, n);


    aux = f;
    printf("printando fila f\n");
    printafila(&f);
    printf("printando fila aux\n");
    printafila(&aux);
}

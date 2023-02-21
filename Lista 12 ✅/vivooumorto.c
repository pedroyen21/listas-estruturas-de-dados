#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct {
    Item *v;
    int inicio;
    int fim;
    int capacidade;
}fila;

int estacheia(fila *f) {
    if(f->fim == f->capacidade)
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
    else return 0;
}

Item desenfila(fila *f) {
    if( !estavazia(f) ) {
        return f->v[f->inicio++];
    }
    else return 0;
}

int inicializa_fila(fila *f, int t) {
    f->inicio = 0;
    f->fim = 0;
    f->capacidade = t;
    f->v = malloc(sizeof(Item) * t);
    return 1;
}

void printafila(fila *f) {
    for(int i = f->inicio; i < f->fim; i++) {
        printf("[%d]\n", f->v[i]);
    }
}

void alimenta_fila(fila *f) {
    Item x;
    for(int i = f->inicio; i < f->capacidade; i++) {
        scanf("%d", &x);
        enfila(f, x);
    }
}   

int main(void) {

    int part, rodadas, i=0;
    scanf("%d %d", &part, &rodadas);
    while(part != 0 && rodadas != 0) {
        printf("Teste %d\n", ++i);

        fila f;
        inicializa_fila(&f, part);

        alimenta_fila(&f);

        //printafila(&f);

        while(rodadas--) {
            int p, ordem, r;
            scanf("%d %d", &p, &ordem);
            fila aux;
            inicializa_fila(&aux, p);
            
            //reacoes
            for(int j = 0; j < p; j++) {
                scanf("%d", &r);
                if(r != ordem) 
                    desenfila(&f);
                else 
                    enfila(&aux, desenfila(&f));
            }

            f = aux;
        }
        printf("%d\n\n", f.v[f.inicio]);

        
        scanf("%d %d", &part, &rodadas);
    }
}

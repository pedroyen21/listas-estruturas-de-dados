#include <stdio.h>
#include <stdlib.h>

typedef int Item;

typedef struct {
    Item *v;
    int tamanho;
    int topo;
}pilha;

int pilha_cheia(pilha *p) {
    if(p->topo == p->tamanho) return 1;
    else return 0;
}

int pilha_vazia(pilha *p) {
    if(p->topo == 0) return 1;
    else return 0;
}

int inicializa_pilha(pilha *p, int t) {
    p->topo = 0;
    p->tamanho = t;
    p->v = malloc(sizeof(Item) * p->tamanho);
    return 0;
}

int empilha(pilha *p, Item x) {
    if( !pilha_cheia(p) ) {
        p->v[p->topo++] = x;
        return 0;
    }
    else {
        printf("Pilha cheia\n");
    }
}

Item desempilha(pilha *p) {
    if( !pilha_vazia(p) ) {
        return p->v[--p->topo];
    }
    else printf("Pilha vazia\n");
}

void printapilha(pilha *p) {
    for(int i = 0; i < p->topo; i++) 
        printf("[%d]\n", p->v[i]);
}
int main(void) {
    int n;
    scanf("%d", &n);
    pilha p;
    inicializa_pilha(&p, n);

    int k;
    while(scanf("%d", &k) == 1) {
        if(k == -1) printf("desempilhado: %d\n", desempilha(&p));
        else {
            if(k == -2) 
                printapilha(&p);

            else {
                empilha(&p, k);
                printf("empilhado: %d\n", k);
            }
        }
    }
}
#include <stdio.h>
#include <stdlib.h>

#define exch(A, B) {Item t = A; A = B; B = t;};

typedef struct {
    int tam;
    char pe;
}bota;

typedef bota Item;

typedef struct {
    Item *v;
    int topo;
    int tamanho;
}pilha;

int pilha_cheia(pilha *p) {
    if(p->topo == p->tamanho) return 1;
    else return 0;
}

int pilha_vazia(pilha *p) {
    if(p->topo == 0) return 1;
    else return 0;
}

int inicializa_pilha(pilha *p, int n) {
    p->tamanho = n;
    p->v = malloc(sizeof(Item) * p->tamanho);
    p->topo = 0;
    return 0;
}

int empilha(pilha *p, Item x) {
    if( !pilha_cheia(p) ) {
        p->v[p->topo++] = x;
        return 0;
    }
    else return 1;

}

Item desempilha(pilha *p) {
    if( !pilha_vazia(p) ) {
        return p->v[--p->topo];
    }
    else -1;
}
void printapilha(pilha *p) {
    for(int i = 0; i < p->topo; i++) {
        printf("[%d , %c]\n", p->v[i].tam, p->v[i].pe);
    }
}

int recebe_bota(pilha *p) {
    bota b;
    scanf("%d %c", &b.tam, &b.pe);
    //printf("bota %d %c\n", b.tam, b.pe);
    int i = p->topo - 1;
    while(i >= 0) {
        if(p->v[i].tam == b.tam && p->v[i].pe != b.pe) {
            exch(p->v[i], p->v[p->topo-1]);
            desempilha(p);
            //printapilha(p);
            return 1;
        }
        i--;
    }
    //printf("empilhado %d %c\n", b.tam, b.pe);
    empilha(p, b);
    //printapilha(p);
    return 0;
}

int main(void) {
    int n;
    while(scanf("%d", &n) == 1) {
        pilha p;
        inicializa_pilha(&p, n);
        int pares = 0;
        for(int i = 0; i < n; i++) {
            pares += recebe_bota(&p);
        }
        free(p.v);
        printf("%d\n", pares);
    }
}
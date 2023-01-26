#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char Item;

typedef struct {
    Item *v;
    int topo;
    int capacidade;
} pilha;

int estacheia(pilha *p) {
    if(p->topo == p->capacidade)
        return 1;
        
    else return 0;
}

int estavazia(pilha *p) {
    if(p->topo == 0)
        return 1;

    else return 0;
}

int inicializa_pilha(pilha *p, int n) {
    p->capacidade = n;
    p->topo = 0;
    p->v = malloc(sizeof(Item) * p->capacidade);
    return 1;
}

int empilha(pilha *p, Item x) {
    if( !estacheia(p) ) {
        p->v[p->topo++] = x;
        return 1;
    }
    else {
        printf("Pilha cheia\n");
        return 0;    
    }
}

Item desempilha(pilha *p) {
    if( !estavazia(p) ) {
        return p->v[--p->topo];
    }
    else {
        printf("Pilha vazia\n");
        return 0;
    }
}

char bemformada(char *str) {
    int tamanhostr = strlen(str);
    pilha p;
    inicializa_pilha(&p, tamanhostr);

    for(int i = 0; i < tamanhostr; i++) {
        if(str[i] == '{' || str[i] == '[' || str[i] == '(')
            empilha(&p, str[i]);
        else {
            if (p.v[p.topo - 1] == '{' && str[i] == '}') {
                desempilha(&p);
                continue;   
            }
            if (p.v[p.topo - 1] == '[' && str[i] == ']') {
                desempilha(&p);
                continue;
            }
            if (p.v[p.topo - 1] == '(' && str[i] == ')') {
                desempilha(&p);
                continue;
            }
            else return 'N';
        }
    }

    if(estavazia(&p)) return 'S';
    else return 'N';
}

int main(void) {
    int ins;
    scanf("%d", &ins);

    while(ins--) {
        char A[100000 + 1];
        scanf("%s\n", A);
        printf("%c\n", bemformada(A));
    }
}
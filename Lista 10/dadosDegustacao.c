#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int tam;
    char c;
    int pos;
} seq;

void merge(seq *v, int l, int m, int r) {
    seq *v2 = malloc(sizeof(seq) * (r - l + 1));

    int i = 0, ia = l, ib = m + 1;
    while(ia <= m && ib <= r) {
        if(v[ib].tam > v[ia].tam){
            v2[i].tam = v[ib].tam;
            v2[i].c = v[ib].c;
            v2[i].pos = v[ib].pos;
            i++, ib++;
        } else {
            v2[i].tam = v[ia].tam;
            v2[i].c = v[ia].c;
            v2[i].pos = v[ia].pos;
            i++, ia++;
        }
    }

    while(ia <= m) {
        v2[i].tam = v[ia].tam;
        v2[i].c = v[ia].c;
        v2[i].pos = v[ia].pos;
        i++, ia++;
    }

    while(ib <= r) {
        v2[i].tam = v[ib].tam;
        v2[i].c = v[ib].c;
        v2[i].pos = v[ib].pos;
        i++, ib++;
    }
    
    i = 0;
    for(int j = l; j <= r; j++) {
        v[j].tam = v2[i].tam;
        v[j].c = v2[i].c;
        v[j].pos = v2[i].pos;
        i++;
    }
}

void mergesort(seq *v, int l, int r) {
    if(l >= r) return;

    int meio = (l + r) / 2;

    mergesort(v, l, meio);
    mergesort(v, meio + 1, r);
    merge(v, l, meio, r);
}

int leitura(char *str, seq *sequencias) {
    int seqi = 0;

    for(int i = 0; str[i] != '\0'; i++) {
        int tam = 1;
        sequencias[seqi].c = str[i];
        sequencias[seqi].pos = i;

        int j = i;
        while(str[++j] == sequencias[seqi].c)
            tam++;

        sequencias[seqi].tam = tam;
        seqi++;
        i = j - 1;
    }

    return seqi;
}

int main() {
    char str[100001];
    scanf("%s\n", str);

    seq sequencias[100001];
    int nroSequencias = leitura(str, sequencias);
    
    mergesort(sequencias, 0, nroSequencias - 1);

    for(int i = 0; i < nroSequencias; i++) {
        printf("%d %c %d\n", sequencias[i].tam, sequencias[i].c, sequencias[i].pos);
    }
    
}
#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int m, int r) {
    int *v2 = malloc(sizeof(int) * (r - l + 1));

    int i = 0, ia = l, ib = m + 1;
    while(ia <= m && ib <= r) {
        if(v[ib] < v[ia])
            v2[i++] = v[ib++];
        else v2[i++] = v[ia++];
    }

    while(ia <= m) 
        v2[i++] = v[ia++];
    
    while(ib <= r)
        v2[i++] = v[ib++];

    i = 0;
    for(int j = l; j <= r; j++) 
        v[j] = v2[i++];
}

void mergesort(int *v, int l, int r) {
    if(l >= r) return;

    int meio = (l + r) / 2;

    mergesort(v, l, meio);
    mergesort(v, meio + 1, r);
    merge(v, l , meio, r);
}

int buscaBinaria(int *v, int l, int r, int n) {
    if(l > r) return -1;

    int meio = (l + r) / 2;

    if(v[meio] == n) return meio;
    else if(v[meio] > n) r = meio - 1;
    else l = meio + 1;

    buscaBinaria(v, l, r, n);
}

int main() {
    int N;
    scanf("%d", &N);

    int v[N];
    for(int i = 0; i < N; i++) scanf("%d ", v + i);

    mergesort(v, 0, N - 1);

    int t, res;
    while(scanf("%d ", &t) != EOF) {
        res = buscaBinaria(v, 0, N - 1, t);

        if(res != -1) printf("sim\n");
        else printf("nao\n");
    }
}

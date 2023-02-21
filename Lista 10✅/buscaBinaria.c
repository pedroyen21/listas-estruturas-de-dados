#include <stdio.h>

int buscabinaria(int *v, int l, int r, int k) {
    int meio = (l + r) / 2;
    if(l > r) {
        if(v[meio] < k) return meio + 1;
        if(v[meio] > k) return meio;
    };
    if(v[meio] == k) return meio;
    if(v[meio] < k) return buscabinaria(v, meio + 1, r, k);
    else return buscabinaria(v, l, meio - 1, k);
}

int main() {
    int N, M;
    scanf("%d %d\n ", &N, &M);

    int v[N];
    for(int i = 0; i < N; i++) scanf("%d ", v + i);

    int t;
    for(int j = 0; j < M; j++) {
        scanf("%d ", &t);
        printf("%d\n", buscabinaria(v, 0, N - 1, t));
    }
}
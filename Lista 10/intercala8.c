#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int m, int r) {
    int *v2 = malloc(sizeof(int) * (r - l + 1));

    int ia = l, ib = m+1, i= 0;

    while(ia <= m && ib <= r) {
        if(v[ib] < v[ia]) {
            v2[i++] = v[ib++];
        }
        else {
            v2[i++] = v[ia++];
        }
    }

    while(ia <= m) 
        v2[i++] = v[ia++];
   
    while(ib <= r) 
        v2[i++] = v[ib++];

    i = 0;
    for(int j = l; j <= r; j++) 
        v[j] = v2[i++];

    free(v2);
}

int alimentaVetor(int *v, int inicio, int fim) {
    for(int i = inicio; i <= fim; i++) scanf("%d", v + i);
}

int main() {

    int v[800000];
    int tam;
    int r, l = 0;
    scanf("%d", &tam);

    r = tam - 1;
    alimentaVetor(v, l, r);
    l = tam;
    r++;

    for(int i = 0; i <= 7; i++) {
        scanf("%d", &tam);
        if(tam == 0) continue;
        r += tam - 1;
        alimentaVetor(v, l, r);
        printf("l = %d r = %d \n", l, r);
        merge(v, l, l + (r - l) / 2, r);
        l = tam;
        r++;

    }
    for(int i = 0; i < r; i++)
        printf("%d ", v[i]);
}
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

    i = 0
    for(int j = l; j <= r; j++) 
        v[j] = v2[i++];

    free(v2);
}

int alimentaVetor(int *v, int inicio, int fim) {
    for(int i = inicio; i < fim; i++) scanf("%d", v + i);
}

void mergesort(int *v, int l, int r) {
    if( l >= r) return;

    int meio = (l + r) / 2;

    mergesort(v, l, meio);
    mergesort(v, meio + 1, r);
    merge(v, l, meio, r);  
}

int main() {

    int l = 0, r;    
    scanf("%d", &r); 
    int *v = malloc(4 * r);
    alimentaVetor(v, l, r);

    for(int i = 1; i <= 7; i++) {
        int t;
        scanf("%d", &t);
        l = r;
        r += t;
        v = realloc(v, 4 * (r));
        alimentaVetor(v, l, r );
    }
    
    mergesort(v, 0, r-1);    
    for(int i = 0; i < r; i++) printf("%d ", v[i]);
    printf("\n");
    
}
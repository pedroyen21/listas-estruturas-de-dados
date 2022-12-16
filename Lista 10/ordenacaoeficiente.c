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
}

void mergesort(int *v, int l, int r) {
    if( l >= r) return;

    int meio = (l + r) / 2;

    mergesort(v, l, meio);
    mergesort(v, meio + 1, r);
    merge(v, l, meio, r);  
}

void printv(int *v, int tam) {
    for(int j = 0 ; j < 2 * tam - 1; j++) {
        if(j % 2 == 0) printf("%d", v[j / 2]); 
        else printf(" ");
    }
    printf("\n");
}

int main(void) {
    int n;
    scanf("%d", &n);
    
    int v[n];
    for(int i = 0; i < n; i++) scanf("%d", v + i);

    mergesort(v, 0, n - 1);

    printv(v, n);
}
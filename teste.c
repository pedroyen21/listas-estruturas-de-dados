#include <stdio.h>
#include <stdlib.h>

int tam = 0;

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

    for(int j = 0; j <= r; j++) 
        v[j] = v2[j];
}

int main() {
    int a[9] = {1, 2,4 , 5, 56, -167, -34, 43, 50};    
    merge(a, 0, 4, 8);
    for(int i = 0; i < 9; i++) printf("%d ", a[i]);
}

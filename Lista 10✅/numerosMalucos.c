#include <stdio.h>
#include <stdlib.h>

// recebe valores
// ordena com mergesort
// tira repetidos
// calcula malucos
// reinsere malucos que não estavam no vetor inicial com merge

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

void mergesort(int *v, int l, int r) {
    if(l >= r) return;

    int meio = (l + r) / 2;

    mergesort(v, l, meio);
    mergesort(v, meio + 1, r);
    merge(v, l, meio, r);  
}

int buscaBinaria(int *v, int l, int r, int n) {
    if(l > r) return -1;

    int meio = (l + r) / 2;
    
    if(v[meio] == n) return meio;
    else if(v[meio] > n) r = meio - 1;
    else l = meio + 1;

    return buscaBinaria(v, l, r, n);
}

long int *intercala(int *v1, int r1, long int *v2, int r2) {
    long int *v3 = malloc(sizeof(long int) * (r2 + r1 + 2));

     int ia = 0, ib = 0, i= 0;

    while(ia <= r1 && ib <= r2) {
        if(v2[ib] < v1[ia]) {
            v3[i++] = v2[ib++];
        }
        else {
            v3[i++] = v1[ia++];
        } 
    }

    while(ia <= r1) 
        v3[i++] = v1[ia++];
   
    while(ib <= r2) 
        v3[i++] = v2[ib++];

    return v3;

}

int main() {
    int N;
    scanf("%d", &N);

    int v[200000];
    // recebe valores
    for(int i = 0; i < N; i++) 
        scanf("%d", v + i);

    // ordena com mergesort
    mergesort(v, 0, N - 1);

    // tira os repetidos
    int novor = 0;
    for(int i = 1; i < N; i++) {
        if(v[i] != v[novor]) {
            v[++novor] = v[i];
        }
    }

    // adiciona 10⁹ se quantidade for impar
    if(novor % 2 == 0) 
        v[++novor] = 1000000000;

    // calcula numeros malucos
    long int malucos[100000];

    int mi = -1;
    for(int j = 0; j <= novor; j += 2) {
        malucos[++mi] = v[j] + v[j + 1];

        if(buscaBinaria(v, 0, novor, malucos[mi]) != -1)
            mi--;   
    }

    // merge
    long int *reinseridos = intercala(v, novor, malucos, mi);

    for(int i = 0; i <= novor + mi + 1; i += 4) 
        printf("%ld\n", reinseridos[i]);

    printf("Elementos: %d\n", novor + mi + 2);

}
#include <stdio.h>

#define exch(A , B) {int t = A; A = B; B = t;}

void printv(int *v, int i) {
    for(int j = 0 ; j < 2 * i - 1; j++) {
        if(j % 2 == 0) printf("%d", v[j / 2]); 
        else printf(" ");
    }
    printf("\n");
}

void insertionsort(int *v, int l, int r) {
    long int chave, j;
    for(int i = 1; i <= r; i++) {
        chave = v[i];
        j = i;
        while(v[j - 1] > chave && j > 0) {
            v[j] = v[j - 1];
            j--;
        } 
        v[j] = chave;
    }
}

int main(void) {
    int v[50000];
    int i = 0;
    while(scanf("%d ", v + i) != EOF) i++;

    insertionsort(v, 0, i-1);

    printv(v, i);
    
}   
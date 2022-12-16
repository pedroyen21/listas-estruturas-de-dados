/*
Mergesort
Simple. Sort the numbers on the standard input using the merge 
sort algorithm. Don't try to cheat by just calling your build 
in functions... I can see your source.

Input
On the standard input you will receive N (1 <= N <= 100000). 
Each number will fit in 32-bit integer

Output
Output the same integers in a sorted manner. Smallest to largest.
Example
Input:
7 3 2 5 4 3
Output:
2 3 3 4 5 7
*/

#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int l, int m, int r) {
    int *v2 = malloc(sizeof(int) * (r - l + 1));

    int i = 0, ia = l, ib = m + 1;
    while(ia <= m && ib <= r) {
        if(v[ib] < v[ia]) 
            v2[i++] = v[ib++]; 
        else 
            v2[i++] = v[ia++];
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
    if (l >= r) return;

    int meio = (l + r) / 2;

    mergesort(v, l, meio);
    mergesort(v, meio + 1, r);
    merge(v, l, meio, r);
}

void printv(int *v, int i) {
    for(int j = 0 ; j < 2 * i - 1; j++) {
        if(j % 2 == 0) printf("%d", v[j / 2]); 
        else printf(" ");
    }
    printf("\n");
}

int main(void) {
    int v[100000];
    int i = 0;
    while(scanf("%d ", v + i) != EOF) i++;

    mergesort(v, 0, i-1);
    printv(v, i);   
}
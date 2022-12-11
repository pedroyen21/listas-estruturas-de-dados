#include <stdio.h>

#define cmpexch(A, B) {if(A > B) {int t = A; A = B; B = t;}}

void printv(int *v, int i) {
    for(int j = 0 ; j < 2 * i - 1; j++) {
        if(j % 2 == 0) printf("%d", v[j / 2]); 
        else printf(" ");
    }
    printf("\n");
}

void bubblesort(int *v, int l, int r) {
    for (int i = l; i < r; i++) 
        for(int j = l; j < r; j++)
            cmpexch(v[j], v[j + 1]);
}

int main(void) {
    int v[50000];

    int i = 0;
    while(scanf("%d ", v + i) != EOF) i++;
    
    bubblesort(v, 0, i-1);

    printv(v, i);

}
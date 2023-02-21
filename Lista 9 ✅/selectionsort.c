#include <stdio.h>

#define exch(A, B) {int t = A; A = B; B = t;}

void printv(int *v, int i) {
    for(int j = 0 ; j < 2 * i - 1; j++) {
        if(j % 2 == 0) printf("%d", v[j / 2]); 
        else printf(" ");
    }
    printf("\n");
}

void selectionsort(int *v, int l, int r) {
    for(int i = 0; i < r; i++){
        int min = i;
        int j = i + 1;
        while(j <= r){
            if(v[j] < v[min]) min = j;
            j++;
        }
        exch(v[min], v[i]);
    }
}

int main(void) {
    int v[1000];

    int i = 0;
    while(scanf("%d ", v + i) != EOF) i++;
    
    selectionsort(v, 0, i-1);

    printv(v, i);

}
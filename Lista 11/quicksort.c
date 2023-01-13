#include <stdio.h>
#include <stdlib.h>

typedef int Item;

#define exch(A, B) {Item t = A; A = B; B = t;}

int median(Item *v, int l, int r) {
    int m = (r + l) / 2;
    if ((v[m] <= v[l] && v[l] <= v[r]) || (v[r] <= v[l] && v[l] <= v[m])) return l;
    if ((v[l] <= v[m] && v[m] <= v[r]) || (v[r] <= v[m] && v[m] <= v[l])) return m;
    if ((v[m] <= v[r] && v[r] <= v[l]) || (v[l] <= v[r] && v[r] <= v[m])) return r;
}

int partition(Item *v, int l, int r) {
    int x = v[r];
    int i = l - 1;
    for(int j = l; j < r; j++) 
        if(v[j] < x) {
            i++;
            exch(v[i], v[j]);
        }
    exch(v[r], v[i + 1]);
    return i + 1;
}

void quicksort(Item *v, int l, int r) {
    if (l >= r) return;
    //exchange the last term with the median
    int med = median(v, l, r);
    exch(v[med] , v[r]);

    int pivot = partition(v, l, r);

    quicksort(v, l, pivot - 1);
    quicksort(v, pivot + 1, r);
}

void printv(Item *v, int size) {
    for(int j = 0 ; j < 2 * size - 1; j++) {
        if(j % 2 == 0) printf("%d", v[j / 2]); 
        else printf(" ");
    }
    printf("\n");
}

int main(void) {
    int N;
    scanf("%d", &N);
    Item *v = malloc(sizeof(Item) * N);

    for(int i = 0; i < N; i++) 
        scanf("%d", v + i);

    quicksort(v, 0, N - 1);
    printv(v, N);
}



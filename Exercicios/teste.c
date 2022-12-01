#include <stdio.h>
#include <stdlib.h>

int main() {
    int *m = malloc(4*10);
    free(m + 3);
}
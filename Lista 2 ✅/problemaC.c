#include <stdio.h>

int main() {
    int v[1000], i = 0;
    while(scanf("%x", &v[i]) == 1) i++;
    printf("%s\n", &v[0]);
}
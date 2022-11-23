#include <stdio.h>

int main() {
    int num;
    int count = 0;
    while (scanf("%d",&num) != EOF) {
        count++;
    }
    printf("%d\n", count);
}
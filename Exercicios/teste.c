#include <stdio.h>
#include <stdlib.h>

void corta(char *m){
    m = m + 3;
    return m;
}

int main() {
    char m[10] = "ABCDEFGHI";
    printf("%s\n", m);
    corta(m);
    printf("%s\n", m);
}
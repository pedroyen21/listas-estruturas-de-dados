#include <stdio.h>
#include <stdlib.h>

void altera(char *a, char *n) {
    a[2] = 'Y';
    n[1] = 'G';
}
int main() {
    for(int i = 0; i < 10; i++) {
        printf("%d\n", i);
        i += 4;
    }

}
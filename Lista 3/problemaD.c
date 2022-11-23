#include <stdio.h>

void soma(char *s, int *sum) {
    if (s[0] == '\0') {
        return;
    }
    *sum += s[0] - 48;
    soma(&s[1], sum);
}

int main() {
    int S = 0;
    char n[100];
    scanf("%s", &n);
    soma(n, &S);
    printf("%d\n", S);

}
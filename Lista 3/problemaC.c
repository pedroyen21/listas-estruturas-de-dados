#include <stdio.h>
#include <string.h>

void soma(char *s, int *sum, int *dg) {
    if (s[0] == '\0') {
        return;
    }
    *sum += s[0] - 48;
    printf("%c", s[0]);
    soma(&s[1], sum, dg);
    *dg += 1;
}

int main() {
    char input[1001];
    int a;

    scanf("%s",&input);
    while(input[0] != '0') {
        int sum = 0, dg = 0;
        a = strlen(input);

        soma(input, &sum, &dg);
        
        printf("\n%d %d", sum, dg);
        
        if(sum % 9 == 0) {
            printf(" is multiple of 9 and has a 9-degree %d\n", dg);
        } else {
            printf(" is not a multiple of 9.\n");
        }

        scanf("%s",&input);

    }

}
#include <stdio.h>
#include <string.h>

void movexs(char  *s) {
    if(s[0] == '\0') return;
    if(s[0] == 'x'){
        movexs(&s[1]);
        printf("%c",s[0]);
        return;
    }
    printf("%c", s[0]);
    movexs(&s[1]);

}

int main() {
    char vetor[100];
    scanf("%s\n", vetor);
    movexs(vetor);
    printf("\n");
}
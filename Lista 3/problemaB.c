#include <stdio.h>
#include <string.h>

void movexs(char  *s) {
    char c = s[0];
    if(s[0] == '\0') return;
    if(s[0] == 'X'){
        s[0] = s[1];
        s[1] = c;
        return movexs(&s[1]);
    }
    printf("%c", s[0]);
    movexs(&s[1]);

}

int main() {
    char vetor[100] = "catXapimXbas";
    printf("%s\n", vetor);
    movexs(vetor);
}
/*
Move os xs.

Dada uma string, faça um programa que compute 
uma nova string de forma que todos os caracteres 
‘x’ minúsculos sejam movidos para o final.

Atenção: Você não pode usar laços na sua solução.

*/

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
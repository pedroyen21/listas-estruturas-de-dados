
/*

Soma dos dígitos

Dado um inteiro não negativo, sua tarefa é escrever 
uma função recursiva que calcule a soma de todos os 
dígitos deste número.

Atenção: Você não pode usar laços na sua solução.
*/

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
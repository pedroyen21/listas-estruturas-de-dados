/*

String ao contrário

Faça um programa que leia uma string e a imprima ao contrário.

Atenção: Você não pode usar laços na sua solução.
Entrada

A entrada é composta por uma única linha contendo uma string de, 
no máximo, 500 caracteres, contendo letras (maiúsculas e minúsculas, 
não acentuadas) e números.
Saída

A saída deve conter uma única linha com a string impressa ao contrário.
*/

#include <stdio.h>

void inverteString(char *vetor) {
    if(vetor[0] == '\0') return;
    inverteString(&vetor[1]);
    printf("%c", vetor[0]);
}

int main() {
    char vetor[501];
    scanf("%s", vetor);
    inverteString(vetor);
    printf("\n");
}
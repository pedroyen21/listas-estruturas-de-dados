/*

Troca X por Y

Sua tarefa nesse exercício é dada uma string, imprimir na 
tela a string trocando todas as ocorrências de ‘x’ por ‘y’.

Atenção: Você não pode usar laços na sua solução.
Entrada

A entrada é composta por uma única linha contendo uma string 
(sem espaços) com, no máximo, 80 caracteres.
Saída

A saída deve conter uma única linha com a string lida, de tal 
forma que toda ocorrência de ‘x’ seja substituída por ‘y’.
*/

#include <stdio.h>

void trocaXporY(char *vetor) {
    if(vetor[0] == '\0') return;
    if(vetor[0] == 'x') vetor[0] = 'y';
    printf("%c", vetor[0]);
    trocaXporY(&vetor[1]);
}

int main() {
    char vetor[81];
    scanf("%s", vetor);
    trocaXporY(vetor);
    printf("\n");
}
/*

Pares de caracteres

Definiremos um par de caracteres numa string quando há a ocorrência 
de um mesmo caracter separado por um caracter qualquer. Por exemplo, 
na string “AxA”, há um par. Os pares podem se sobrepor, por exemplo, 
na string “aaaa” há dois pares: os primeiros três caracteres formam 
um par de ‘a’s separados por um ’a’, os três últimos caracteres formam 
outro par de ‘a’s, separado por um ’a’. Sua tarefa neste exercício é 
fazer um algoritmo recursivo que conte a quantidade de pares numa string.

Observação: Sua recursão não pode usar laços.
Entrada

A entrada é composta por uma única linha contendo uma string de, no máximo,
 200 caracteres.
Saída

A saída deve conter uma única linha com a quantidade de pares que há na string.
*/

#include <stdio.h>

void contaPares(char *vetor, int *pares) {
    if (vetor[2] == '\0') 
    {
        printf("%d\n", *pares); 
        return;
    }
    if (vetor[0] == vetor[2]) *pares += 1;
    contaPares(&vetor[1], pares);
}

int main() {
    int pares = 0;
    char vetor[201];
    scanf("%s", vetor);

    contaPares(vetor, &pares);
}
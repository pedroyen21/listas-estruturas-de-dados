/*
6) Uma sequˆencia de N elementos Vi ORDENADOS, com N par,  ́e dita balanceada quando
a soma do maior elemento com o menor elemento  ́e igual a soma do segundo maior elemento com o segundo
menor elemento, que por sua vez  ́e igual a soma do terceiro maior elemento com o terceiro menor elemento,
e assim por diante. Escreva uma fun ̧c ̃ao RECURSIVA em C que decida se o vetor est ́a balanceado ou n ̃ao.
Esta fun ̧c ̃ao dever ́a retornar 1 quanto estiver balanceado e 0 quando n ̃ao estiver. Implemente quaisquer
fun ̧c ̃oes auxiliares que achar necess ́ario.
A fun ̧c ̃ao tem o seguinte prot ́otipo (e n ̃ao pode ser modificado):
*/
#include <stdio.h>
#include <stdlib.h>

int balanceada(int *vetor, int inicio, int fim){
    if (inicio + 1 == fim) return 1;
    if(vetor[inicio] + vetor[fim] != vetor[inicio + 1] + vetor[fim - 1]) return 0;
    balanceada(vetor, inicio + 1, fim - 1);
};

int main() {
    int vetor[12] = {3, 3, 5, 8, 9, 10, 11, 27, 32, 41, 45, 51};
    printf("%d\n", balanceada(vetor, 0, 11));
}


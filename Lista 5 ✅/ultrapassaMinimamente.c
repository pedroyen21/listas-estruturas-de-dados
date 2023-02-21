/*
7) Fazer um programa em C para ler uma sequˆencia (n ̃ao necessariamente ordenada) com
uma quantidade arbitr ́aria de n ́umeros inteiros positivos do teclado e armazen ́a-los em um vetor v. O  ́ultimo
n ́umero lido  ́e o zero, o qual n ̃ao deve fazer parte dos valores de v. Al ́em desses, mais um  ́unico valor
deve ser lido, o que representa o limite de soma. Ap ́os a leitura dos dados, o programa deve imprimir
apenas os  ́ultimos n ́umeros de cada subsequˆencia de v cuja soma de seus valores ultrapassa minimamente
o limite de soma. Uma vez ultrapassado esse limite, uma nova subsequˆencia deve ser iniciada a partir do
valor que segue o  ́ultimo da subsequˆencia identificada no momento. Ao final do processamento completo
seu programa dever ́a imprimir o valor que ultrapassa minimamente o limite da soma ao contr ́ario que da
forma que  ́e processado, e esses n ́umeros N  ̃AO podem ser armazenados em um vetor. Veja um exemplo de
execu ̧c ̃ao abaixo:
Exemplo de Entrada
33 51 23 94 66 28 11 73 19 8 31 0
90
Sa ́ıda para o exemplo
19 28 94 23
No exemplo acima, o valor 23  ́e o  ́ultimo da subsequˆencia 33 51 23, cuja soma  ́e 107, a qual minimamente
ultrapassa o limite de soma 90, sendo assim dever ́a ser impresso por  ́ultimo. Com isso, logo depois do valor
23, tem in ́ıcio a verifica ̧c ̃ao da soma dos valores de uma nova subsequˆencia que come ̧ca com o n ́umero 94.
De cara, s ́o o 94 j ́a ultrapassa o limite 90, sendo o pen ́ultimo n ́umero a ser impresso, e assim por diante at ́e
que todo o vetor v seja processado.
Note que vocˆe N  ̃AO pode iniciar o processamento pelo fim do vetor v, pois, desta forma, o resultado
seria diferente.
*/
#include <stdio.h>
#include <stdlib.h>

void verificar(int *v, int limite, int *soma, int i, int tamanho) {
    *soma += *(v);
    i += 1;
    if (i > tamanho) return;

    if (*soma > limite) {
        *soma = 0; 
        verificar(v + 1, limite, soma, i, tamanho);
        printf("%d\n", *v);
        return;
    }
    verificar(v + 1, limite, soma, i, tamanho);
}

int main() {
    int n, tamanho = 0;
    scanf("%d", &n);
    int *ptr = malloc(0);

    for(int i = 0; n != 0; i++) {
        tamanho += 1;
        ptr = realloc(ptr, tamanho * sizeof(int));
        *(ptr + i) = n;
        scanf("%d", &n);
    }

    int limite, soma = 0;
    scanf("%d", &limite);
    int i = 0;
    verificar(ptr, limite, &soma, i, tamanho);

    free(ptr);
}
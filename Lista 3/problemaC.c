

/*

RUMO9S - Rumo aos 9s

Um truque bem conhecido para descobrir se um inteiro N é um múltiplo de 
nove é computar a soma S dos seus dígitos. Se S é um múltiplo de nove, 
então N também é. Este é um teste recursivo e a profundidade da recursão 
necessária para obter a resposta para o número N é chamada o grau-9 de N.

Sua tarefa é, dado um inteiro positivo N, determinar se ele é um múltiplo 
de nove e, caso ele seja, qual o seu grau-9.
Entrada

A entrada é um arquivo tal que cada linha contém um inteiro positivo. 
Uma linha contendo o número 0 indica o fim da entrada. Os números 
fornecidos na entrada possuem até 1000 dígitos. 

Saida

A saída do programa deve indicar, para cada número da entrada, 
se ele é um múltiplo de nove e, caso ele seja, o seu grau-9. 
Veja o exemplo de saída para saber o formato esperado da saída.
Exemplo de Entrada

999999999999999999999
9
9999999999999999999999999999998
0

Exemplo de Saída:

999999999999999999999 is a multiple of 9 and has 9-degree 3.
9 is a multiple of 9 and has 9-degree 1.
9999999999999999999999999999998 is not a multiple of 9.

Author: David Déharbe adaptado por Sérgio Cipriano e João Cunha

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int soma(int *sum, int *dg);

int main() {
    char s[1001];
    int a = 0;
    while(1){
        scanf("%s %n",&s, &a);
        if (s[0] == '0') break;
        int sum = 0, dg = 1;
        for (int i = 0; i < a - 1; i++){
            sum += s[i] - 48;
        }
        if (soma(&sum, &dg) == 9) {
            printf("\n%s is a multiple of 9 and has 9-degree %d.", s, dg);
        } else {
            printf("\n%s is not a multiple of 9.\n", s);
        };
    }
}

int soma(int *sum, int *dg) {
    if (*sum / 10 == 0) return *sum;
    int s = 0;
    for (int i = 0;  (*sum % 10) != 0 || (*sum / 10) != 0; i++)
    {
        s += *sum % 10;
        *sum /= 10;
    }
    *dg += 1;
    *sum = s;
    soma(sum, dg);
}
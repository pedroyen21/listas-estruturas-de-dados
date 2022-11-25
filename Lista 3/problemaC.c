#include <stdio.h>
#include <string.h>
#include <stdlib.h>


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
// soma recursiva
// 1 - vai pegar o input, transformar cada caracter em digito e somar 
// 2 - verificar se a soma é igual a 9: return;
// 3 - depois vai pegar essa soma e transformar em caracteres
// 4 - chamar soma novamente

void soma(char *s, int length) {
    int sum = 0;
    
    // soma valores do input
    for (int i = 0; s[i] != 0; i++)
    {
        length = i;
        sum += s[i] - 48;
    }
    if(sum % 10 == 0 ) return;
    
    char novaSoma[length];

    // atribui a soma a uma string 
    for (int i = length; i >= 0; i-- ) 
    {
        novaSoma[i] =  (sum % 10) + 48;
        sum /= 10;
    }
    novaSoma[2] = '\0';
    printf("Nova soma string %s\n", novaSoma);

    soma(novaSoma, length);
    
}

int main() {
    char input[1001];
    int a;

    scanf("%s",&input);
    while(input[0] != '0') {
        int dg = 0;
        a = strlen(input);

        soma(input, a);
        
        printf("strlen %d soma %d dg %d",a, dg);
        scanf("%s",&input);

    }

}
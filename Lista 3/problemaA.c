/*

Número 91

João é um matemático e programador que adora subtrações numéricas. 
Certo dia, João encontrou um livro com o título “O Número 91”. 
Conforme lê-se no livro:

    “Aquele que abrir este livro, há de ser amaldiçoado,

    qualquer número menor ou igual a 100 será modificado.

    Aconselho-te portanto, não utilize mais a subtração,

    pois o número 91 será sua maldição.”

João não deu atenção para o livro, já que não acredita em maldições 
e coisas do tipo. Passados alguns dias, João quis escrever um programa 
que sempre fizesse a subtração de qualquer número dado em 10.

Você deve modificar o programa de João, adicionando a maldição a seguir 
para que ele aprenda a não mais abrir livros estranhos que encontrar por 
aí.

Maldição:

    Se N≥101, então f91(N)=N−10.

    Se N≤100, então f91(N)=f91(f91(N+11)).

*/

#include <stdio.h>

int f91(int N) {
    if( N >= 101 ) {
        return N - 10;
    }

    if ( N <= 100) {
        return f91(f91(N+11));
    }
}

int main() {
    int n;
    scanf("%d", &n);

    while(n != 0) {
        printf("f91(%d) = %d\n", n, f91(n));
        scanf("%d", &n);
    }
}
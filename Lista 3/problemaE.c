/*

Fibonacci

A famosa sequência de Fibonacci é aquela em que um 
elemento é definido como sendo a soma dos dois anteriores. 
Matematicamente falando,

F(n)={
    1             ,se n=1 ou n=2,
    F(n−1)+F(n−2) ,se >2;

Sua tarefa, neste exercício, é implementar, utilizando recursão, 
a função de Fibonacci de forma eficiente.
*/

#include <stdio.h>
#include <stdlib.h>


static long int fib[101];

long int fibonacci(int n) {
    if (n <= 2) {
        fib[n] = 1;
        return fib[n];
    }
    if (fib[n] == 0) fib[n] = fibonacci(n - 1) + fibonacci(n - 2);
    return fib[n];
}

int main() {
    for (int i = 1; i < 101; i++) printf("fibonacci de %d : %lld\n",i, fibonacci(i));
}
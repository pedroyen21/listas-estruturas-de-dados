#include <stdio.h>

int main() {
    int n;
    int soma = 0;
    int contador;
    scanf("%d", &n);
    for (contador = 1; contador <= n; contador++ ){
        int num;
        scanf("%d", &num);
        soma = soma + num;
    }
    printf("%d\n", soma);
}


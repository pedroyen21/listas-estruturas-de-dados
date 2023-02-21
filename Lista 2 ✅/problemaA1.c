#include <stdio.h>

int main() {
    int i, n, num, resposta;
    int soma = 0;
    
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &num);
        soma += num;
    }

    scanf("%d", &resposta);
    
    if (soma == resposta) {
        printf("Acertou\n");
    } else {
        printf("Errou\n");
    }
}
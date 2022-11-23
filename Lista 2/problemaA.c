#include <stdio.h>

int main() {
    int i, num, resposta;
    int soma = 0;

    for (i = 0; i < 3; i++) {
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
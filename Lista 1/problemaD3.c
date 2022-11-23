#include <stdio.h>
#include <string.h>

int escolheMelhor(int notas[],int codigos[], int tam) {
    int melhor = 0;
    int posMelhor = 0;
    int menorCodigo = 0;

    for (int i = 0; i < tam; i++) {
        if (notas[i] > melhor) {
            melhor = notas[i];
            posMelhor = i;
        } else if (notas[i] == melhor && codigos[posMelhor] > codigos[i]) {
            melhor = notas[i];
            posMelhor = i;
        }
    };
    return posMelhor;
    
}

int main() {
    int dia = 1;
    int n = 0; 
    int i = 0;
    while (scanf("%d", &n) != EOF) {
        int codigos[n];
        int notas[n];
    
        for (int i = 0; i < n; i ++) {
            scanf("%d", &codigos[i]);
            scanf("%d", &notas[i]);
        }
        printf("Dia %d\n%d\n\n", dia, codigos[escolheMelhor(notas, codigos, n)]);
        dia++;
    }
}
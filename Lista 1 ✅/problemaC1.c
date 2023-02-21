#include <stdio.h>
#include <string.h>

int main() {
    int n;
    int j, z;
    char testeStr[6] = "Teste";
    int teste = 1;

    scanf("%d", &n);
    while(n != 0) {
        int diferenca = 0;
        
        printf("\n%s ", testeStr);
        printf("%d\n", teste);

        for (int contador = 1; contador <= n; contador ++) {
            scanf("%d %d", &j, &z);
            diferenca = diferenca + j - z;
            
            printf("%d\n", diferenca); 
        }
        teste++;
        scanf("%d", &n);

    }
    return 0;
}
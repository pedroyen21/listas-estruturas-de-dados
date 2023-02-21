#include <stdio.h>
#include <stdlib.h>

int main() {
    int N, golsA = 0, golsB = 0;
    scanf("%d", &N);

    // cA : cobrancas restantes de A
    // cB : cobrancas restantes de B
    int cA = N, cB = N;
    char penaltiesA[N + 1];
    char penaltiesB[N + 1];
    scanf("%s", penaltiesA);
    scanf("%s", penaltiesB);

    int i = 0;
    while (N > i){
        if(golsB > cA + golsA || golsA > cB + golsB ) break;
        if(penaltiesA[i] == 'o') golsA++;
        cA--;
        
        if(golsA > cB + golsB || golsB > cA + golsA) break;
        if(penaltiesB[i] == 'o') golsB++;
        cB--;

        i++;
    }

    if(golsA == golsB) {
        printf("Empate\n");
    } else {
        // printa cobrancas feitas; 
        printf("%d\n", 2 * N - (cA + cB));
    };
}
#include <stdlib.h>
#include <stdio.h>

int main() {
    for (int i = 1; i <= 8; i++) {
        char comando[50];
        char mostrarInput[50];
        printf("Input:\n");
        sprintf(mostrarInput, "cat ./inputsMaiorSub/input%d.txt", i);
        system(mostrarInput);
        printf("\n\nResposta: \n");
        sprintf(comando, "./maiorSubString < ./inputsMaiorSub/input%d.txt", i);
        system(comando);
        printf("-----------------------------------\n");
    }
}
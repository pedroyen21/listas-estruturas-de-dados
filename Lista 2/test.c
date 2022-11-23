#include <stdlib.h>
#include <stdio.h>

int main(int escolha) {
    if (escolha == 1) {
        printf("escolha 1");
    }
    else {

    for (int i = 1; i <= 4; i++) {
        char comando[50];
        char mostrarInput[50];
        printf("Input %d:\n\n", i);
        sprintf(mostrarInput, "cat ./inputsProblemaC/input%d.txt", i);
        system(mostrarInput);
        printf("\n\nResposta %d: \n\n", i);
        sprintf(comando, "./problemaC < ./inputsProblemaC/input%d.txt", i);
        system(comando);
        printf("-------------\n");
    }
    }
}
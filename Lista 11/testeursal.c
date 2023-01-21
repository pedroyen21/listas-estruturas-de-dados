#include <stdlib.h>
#include <stdio.h>

int main() {
    for (int i = 1; i <= 2; i++) {
        char comando[50];
        char mostrarInput[50];
        printf("Input:\n");
        sprintf(mostrarInput, "cat ./inputsursal/input%d.txt", i);
        system(mostrarInput);
        sprintf(mostrarInput, "cat ./inputsursal/output%d.txt", i);
        system(mostrarInput);
        printf("\n\nResposta: \n");
        system("gcc -Wall -Wextra -O2 ursal.c -o 'ursal' ");
        sprintf(comando, "./ursal < ./inputsursal/input%d.txt", i);
        system(comando);
        printf("-----------------------------------\n");
    }
}
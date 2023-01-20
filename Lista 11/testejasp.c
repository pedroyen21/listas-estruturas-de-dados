#include <stdlib.h>
#include <stdio.h>

int main() 
{
        char comando[50];
        char mostrarInput[50];
        printf("Input:\n");
        sprintf(mostrarInput, "cat ./inputjasp.txt");
        system(mostrarInput);
        printf("\n\nResposta: \n");
        system("gcc -Wall -Wextra -Wpedantic -O2 jaspion.c -o 'jaspion'");
        sprintf(comando, "./jaspion < ./inputjasp.txt");
        system(comando);
        printf("-----------------------------------\n");   
}
#include <stdio.h>
#include <strings.h>


int main() {
    char nome[30] = "Leonardo Cicero Marciano";
    char marte[30] = "marte";
    char palavra[30];

    while(scanf("%s",&palavra) != EOF) {
        if(strcmp(palavra, marte) == 0) {
            printf("%s\n", nome);
            return 0;
        } 
    
    }
    printf("none\n");

}
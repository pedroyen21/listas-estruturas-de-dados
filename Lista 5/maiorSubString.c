#include <stdio.h>
#include <string.h>

int maiorSubString(char *str, char *sub, int maior, int tam, int contador, int *contando){
    if(str[0] == '\0' || strlen(str) < tam) {
        if(maior == 0 && contador == 0) {
            return 0;
        } else {
            return maior + tam;
        }
    }

    if(strncmp(str, sub, tam) == 0) { 
        if(*contando == 0) {
            *contando = 1;
        } 
        else {
            if(maior < contador) {
                maior = contador;
            }
        }        
    }

    if(*contando == 1) contador += 1;

    maiorSubString(str + 1, sub, maior, tam, contador, contando);   
}

int main() {
    char str[102], sub[102];
    int maior=0, tam, contador = 0, contando = 0;
    scanf("%s", str);
    
    if(scanf("%s%n", sub, &tam) == 1) {
        tam -= 1;
        printf("%d\n", maiorSubString(str, sub, maior, tam, contador, &contando));
    } else {
        printf("0\n");
    }
    
}



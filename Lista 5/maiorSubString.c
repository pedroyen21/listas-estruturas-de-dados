#include <stdio.h>
#include <string.h>

int maiorSubString(char *str, char *sub, int maior, int tam, int count, int *contando){
    if(str[0] == '\0') return maior;
    if(strncmp(str, sub, tam) == 0) {
        if(*contando == 0) {
            *contando = 1;
        } else {
            maior += count;
        }
    }
    if(*contando == 1) count += 1;

    maiorSubString(str + 1, sub, maior, tam, count, contando);   
}

int main() {
    char str[101], sub[101];
    int maior = 0, tam, count = 0, contando = 0;
    scanf("%s", str);
    scanf("%s%n", sub, &tam);
    tam -= 1;
    
    printf("%d\n", maiorSubString(str, sub, maior, tam, count, &contando) + tam);
    
}



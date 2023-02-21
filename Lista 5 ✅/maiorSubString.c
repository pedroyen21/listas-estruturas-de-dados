/*

 substring

Sua tarefa nesse exercício é, dadas duas cadeias de caracteres str e sub, 
determinar recursivamente qual a maior subcadeia de str que começa e termina 
por sub.

Atenção: Você não pode usar laços na sua solução.
Entrada

A entrada é composta por duas linhas. A primeira linha contém str, que pode 
ter tamanho entre zero e 100, e a segunda linha contém sub, que pode ter tamanho
 entre 1 e 100.
Saída

A saída deve conter uma única linha com o tamanho da maior subcadeia de str que 
começa e termina por sub.
*/
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



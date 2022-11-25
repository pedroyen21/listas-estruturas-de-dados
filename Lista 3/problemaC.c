#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// soma recursiva
// 1 - vai pegar o input, transformar cada caracter em digito e somar 
// 2 - verificar se a soma é igual a 9: return;
// 3 - depois vai pegar essa soma e transformar em caracteres
// 4 - chamar soma novamente

void soma(char *s, int length) {
    int sum = 0;
    
    // soma valores do input
    for (int i = 0; s[i] != 0; i++)
    {
        length = i;
        sum += s[i] - 48;
    }
    if(sum % 10 == 0 ) return;
    
    char novaSoma[length];

    // atribui a soma a uma string 
    for (int i = length; i >= 0; i-- ) 
    {
        novaSoma[i] =  (sum % 10) + 48;
        sum /= 10;
    }
    novaSoma[2] = '\0';
    printf("Nova soma string %s\n", novaSoma);

    soma(novaSoma, length);
    
}

int main() {
    char input[1001];
    int a;

    scanf("%s",&input);
    while(input[0] != '0') {
        int dg = 0;
        a = strlen(input);

        soma(input, a);
        
        printf("strlen %d soma %d dg %d",a, dg);
        scanf("%s",&input);

    }

}
#include <stdio.h>

int main()
{
    float d, altura, largura, profundidade;
    scanf("%f", &d);
    scanf("%f %f %f", &altura, &largura, &profundidade);

    char resposta = d > altura || d > largura || d > profundidade? 'N' : 'S';
    printf("%c\n", resposta);   
}
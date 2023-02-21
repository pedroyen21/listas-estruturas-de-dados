#include <stdio.h>

int main()
{
    float diametroBola, altura, largura, profundidade;
    scanf("%f", &diametroBola);
    scanf("%f %f %f", &altura, &largura, &profundidade);

    // alguma medida da caixa e maior que o diametro da bola? 
    char resposta = diametroBola > altura || diametroBola > largura || diametroBola > profundidade? 'N' : 'S';
    printf("%c\n", resposta);   
}
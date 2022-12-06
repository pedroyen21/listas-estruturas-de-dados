#include <stdio.h>
#include <stdlib.h>

void processaJogos(char *v, int jogos) {    
    char vencedores[jogos];
    int golsTime1, golsTime2, ntimes = jogos * 2;
    int k = 0;

    for(int i = 0; i < ntimes; i += 2) {
        scanf("%d %d", &golsTime1, &golsTime2);
        if(golsTime1 > golsTime2) {
            vencedores[k] = v[i];
        } else {
            vencedores[k] = v[i + 1];
        }
        k++;
    }
    if (jogos == 1) { 
        printf("%c\n", vencedores[0]);
        return;
    }

    processaJogos(vencedores, jogos / 2);
}

int main(void) {
    char times[16] = 
    {
    'A', 'B', 'C', 'D', 
    'E', 'F', 'G', 'H', 
    'I', 'J', 'K', 'L', 
    'M', 'N', 'O', 'P'
    };

    processaJogos(times, 8);
}
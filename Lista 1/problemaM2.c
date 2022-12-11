#include <stdio.h>
#include <strings.h>
#include <stdlib.h>


int main() {
    int n;
    scanf("%d ", &n);

    char texto[n][1000];

    for (int i = 0; i < n; i++) {
        fgets(texto[i], 1000, stdin);

    }

    int colunaDesejada, linhaCursor, colunaCursor;
    scanf("%d", &linhaCursor);
    scanf("%d", &colunaCursor);
    linhaCursor -= 1;
    colunaCursor -= 1;
    colunaDesejada = colunaCursor;

    char espaco;
    scanf("%d", &espaco);

    char comandos[1000];
    int i = 0;
    comandos[i] = getchar();

    while (comandos[i] != EOF){
        scanf("%d", &espaco);
        i++;
        comandos[i] = getchar();
    }

    char caractere = texto[linhaCursor][colunaCursor]; 
    int a = 0;
    while(a < i) {
        //j - desce linha
        if (comandos[a] == 106) {
            if(linhaCursor < n - 1) {
                linhaCursor++;
                for (int j = 0; texto[linhaCursor][j] != 10 && j <= colunaDesejada; j++){
                    caractere = texto[linhaCursor][j];
                    colunaCursor = j;
                }   
            }
        }
        // k - sobe linha
        if (comandos[a] == 107) {
            if(linhaCursor > 0) {
                linhaCursor--;
                for (int j = 0; texto[linhaCursor][j] != 10 && j <= colunaDesejada; j++){
                    caractere = texto[linhaCursor][j];
                    colunaCursor = j;
                }   
            }
        }     
        printf("%d %d %c\n", linhaCursor+1, colunaCursor+1, caractere);
        a++;
    }
}

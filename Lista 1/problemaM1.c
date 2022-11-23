#include <stdio.h>
#include <strings.h>
#include <stdlib.h>

void render( int n, char jogo[n][12], int posicaoDoJogo) {
    char linha[12] = "~~~~~~~~~~~";

    printf("%s\n", linha);
    int i = posicaoDoJogo + 4;
    while(i >= posicaoDoJogo) {
        if (i > n) {
            printf("           \n");
        } else {
            printf("%s\n", jogo[i]);
        }
        i--;
    }
    printf("%s\n", linha);
}

void posicionarLenhador(int n, char jogo[n][12], int lado, int pos, int posLenhador[2]) {
    if (lado == 68) {
        if (jogo[pos][7] != 45 && jogo[pos+1][7] != 45){
            jogo[pos][7] = 76;
            jogo[pos+1][7] = 76; 
            posLenhador[0] = lado;
            posLenhador[1] = pos;
        } else {
            printf("**morreu**\n");
            exit(0);
        }
        
    } else if (lado == 69) {
        if (jogo[pos][3] != 45 && jogo[pos+1][3] != 45){
            jogo[pos][3] = 76;
            jogo[pos+1][3] = 76;
            posLenhador[0] = lado;
            posLenhador[1] = pos;
        } else {
            printf("**morreu**");
            exit(0);
        }
    }
}

void posicionarGalho( int n, char jogo[n][12], int lado, int pos ) {
    pos -= 1;
    if (lado == 68) {
        jogo[pos][7] = 45;
        jogo[pos][8] = 45;
        jogo[pos][9] = 45;
    } else if (lado == 69) {
        jogo[pos][1] = 45;
        jogo[pos][2] = 45;
        jogo[pos][3] = 45;
    }
}

void gerarGalhos(int n, char jogo[][12]) {
    int ngalhos;
    scanf("%d", &ngalhos);

    char lado[2];
    int pos;
    for (int i = 0; i < ngalhos; i++) {
        scanf("%s", &lado[0]);
        scanf(" %d", &pos);
        posicionarGalho(n, jogo, lado[0], pos);
    } 
}

void gerarLenhador(int n, char jogo[][12], int posicaoDoJogo, int posLenhador[2]) {
    char ladoLenhador[2];
    scanf("%s", &ladoLenhador);
    posLenhador[0] = ladoLenhador[0];
    posLenhador[1] = posicaoDoJogo;
    posicionarLenhador(n, jogo, posLenhador[0], posLenhador[1],posLenhador);
}

int trocarDeLado(int n, char jogo[n][12], int posicaoDoJogo, int posLenhador[2]) {
    if (posLenhador[0] == 68) {
        if(jogo[posLenhador[1]][3] != 32 || jogo[posLenhador[1]+1][3] != 32 ) {
            printf("**beep**\n");
            return 0;
        } else {
            posicionarLenhador(n, jogo, 69, posicaoDoJogo, posLenhador);
            jogo[posLenhador[1]][7] = 32;
            jogo[posLenhador[1]+1][7] = 32;
        }
        
    } else {
        if(jogo[posLenhador[1]][7] != 32 || jogo[posLenhador[1]+1][7] != 32 ) {
            printf("**beep**\n");
            return 0;
        } else {
            posicionarLenhador(n, jogo, 68, posicaoDoJogo, posLenhador);
            jogo[posLenhador[1]][3] = 32;
            jogo[posLenhador[1]+1][3] = 32;
        }

    }
    render(n, jogo, posicaoDoJogo);
}

void bater(int n,  char jogo[n][12],  int posLenhador[2], int *posicaoDoJogo) {
    if (posLenhador[0] == 68) {
        if (jogo[posLenhador[1]][6] == 60) {
            *posicaoDoJogo += 1;
            posicionarLenhador(n, jogo, posLenhador[0], *posicaoDoJogo, posLenhador);
        } else {
            jogo[posLenhador[1]][6] = 60;
        }
    }
    if (posLenhador[0] == 69) {
        if (jogo[posLenhador[1]][4] == 62) {
            *posicaoDoJogo += 1;
            posicionarLenhador(n, jogo, posLenhador[0], *posicaoDoJogo, posLenhador);

        } else {
            jogo[posLenhador[1]][4] = 62;
        }
    }
    render(n, jogo, *posicaoDoJogo);
        
}

void jogar(int n, int jogada, char jogo[n][12], int *posicaoDoJogo, int posLenhador[2]) {
    //trocar de lado
    if(jogada == 84) {
        trocarDeLado( n, jogo, *posicaoDoJogo, posLenhador);
    }
    
    //bater
    if(jogada == 66) {
        bater(n, jogo, posLenhador, posicaoDoJogo);
    }
}

int main() {
    int n;
    scanf("%d", &n);
    int posicaoDoJogo = 0;

    char jogo[n + 2][12];

    //inicializacao do jogo;
    int i, j;
    for (i = 0; i < n + 2; i++) {
        for (j = 0; j < 12; j++) {
            if (n <= i && i < n+2) {
                jogo[i][j] = 32;
            } else {
                if (j == 4 || j == 5 || j == 6) {
                    jogo[i][j] = 124;
                } else {
                    jogo[i][j] = 32;
                }
            }
            
        }
        jogo[i][11] = 0;
    }
    int posLenhador[2] = {0,0};
    gerarGalhos(n, jogo);
    gerarLenhador(n, jogo, posicaoDoJogo, posLenhador);

    char comandos[2000];
    scanf("%s", &comandos);

    render(n, jogo, posicaoDoJogo); 
    
    int r = 0;
    while (comandos[r] != 0) {
        jogar(n, comandos[r], jogo, &posicaoDoJogo, posLenhador);
        r++;
    }

}

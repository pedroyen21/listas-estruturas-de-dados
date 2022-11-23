#include <stdio.h> 

void main() {
    int n;
    int contador;
    scanf("%d", &n);
    
    while(n != 0) {
        int vitoriasAlice = 0;
        int vitoriasBeto = 0;

        for(contador = 1; contador <= n; contador++) {
            int partida;
            scanf("%d", &partida);
            if(partida == 0){
                vitoriasAlice++;
            } else if(partida == 1) {
                vitoriasBeto++;
            }

        }

        printf("Alice ganhou %d e Beto ganhou %d\n", vitoriasAlice, vitoriasBeto);
        scanf("%d", &n);
    }


}
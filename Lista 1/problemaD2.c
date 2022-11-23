#include <stdio.h>
#include <strings.h>

int main() {
    int quantosSim = 0;
    int triagens = 0;
    char respostas[10000] = "";
    char resposta[10];
    int k = 0;

    while(fgets(resposta, 5, stdin) != NULL) {
        fflush(stdin);
        respostas[k] = resposta[0];
        respostas[k+1] = resposta[1];
        respostas[k+2] = resposta[2];

        k += 3;
    } 

    int jaFoi = 0;
    for (int j = 0; j < strlen(respostas); j++) {
        if ((j+1) % 30 == 0) {
            quantosSim = 0;
            jaFoi = 0;
        }

        if (respostas[j] == 115) {
            quantosSim++;
        }

        if (quantosSim == 2 && jaFoi == 0) {
            triagens++;
            jaFoi = 1;
        }
    }
    printf("%d\n", triagens); 
}






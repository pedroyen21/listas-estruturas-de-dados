#include <stdio.h>
#include <stdlib.h>

double ** alocaMatriz(int m, int n) {
    double **M = malloc(m * 8);

    for(int i = 0; i < m; i++) {
        M[i] = malloc(n * sizeof(double));
    }
    
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Digite o valor da celula M[%d][%d]: ", i, j);
            scanf("%f", M[i][j]);
        }
    }
    return M;
}

void printaMatriz(double **M, int m, int n) {
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("M[%d][%d] = %f\n", i, j, **(M)[i][j]);     
        }
    }
}
int main() {
    int Ai, Aj, Bi, Bj;

    printf("Digite as dimensões da matriz A: ");
    scanf("%d %d", &Ai, &Aj);

    printf("Digite as dimensões da matriz B: ");
    scanf("%d %d", &Bi, &Bj);

    double **A = alocaMatriz(Ai, Aj);
    printaMatriz(A, Ai, Aj);
    double **B = alocaMatriz(Bi, Bj);
    printaMatriz(B, Bi, Bj);


}
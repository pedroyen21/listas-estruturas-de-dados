/*

Busca geral num conjunto não ordenado

Sua tarefa, neste exercício, é ler um conjunto de N número 
inteiros e depois verificar se M elementos pertencem ou não 
ao conjunto. Se pertencerem, você deve imprimir a posição que 
ocupam. Se não, você deve imprimir -1.

M é um valor muito grande, por isso, você deve elaborar um 
algoritmo eficiente para efetuar as buscas!
Entrada

A entrada é composta M+N+1 linhas. A primeira linha contém o 
valor de N e M, respectivamente (1≤N,M≤109). As N linhas seguintes
contém números inteiros (que cabem num inteiro de 32 bits) que compõem 
o conjunto de dados de interesse de busca. As M linhas seguintes contêm
os inteiros que devem ser procurados no conjunto de dados.
Saída

Para cada inteiro x dado, você deve imprimir a posição j tal que v[j]=x,
ou −1 se x não pertencer a v.
*/

#include <stdio.h>

#define exch(A, B) {int t = A; A = B; B = t;}

void selectionsort(int *v,  int l, int r) {
    for(int i = 0; i < r; i++){
        int min = i;
        int j = i + 1;
        while(j <= r){
            if(v[j] < v[min]) min = j;
            j++;
        }
        exch(v[min], v[i]);
    }
}

int buscaBinaria(int *v, int l, int r, int n) {
    if(l > r) return -1;

    int meio = (l + r) / 2;
    
    if(v[meio] == n) return meio;
    else if(v[meio] > n) r = meio - 1;
    else l = meio + 1;

    buscaBinaria(v, l, r, n);
}

int main(void) {
    int N=0, M=0;
    scanf("%d %d", &N, &M);

    int vetor[N];
    int posOriginais[N];
    for(int i = 0; i < N; i++) scanf("%d", vetor + i);

    selectionsort(vetor,  0, N-1);

    int t;
    for(int j = 0; j < M; j++) {
        scanf("%d", &t); 
        printf("%d\n", buscaBinaria(vetor, 0, N, t));
    }
}
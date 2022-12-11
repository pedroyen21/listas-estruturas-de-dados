/*
Pesquisa de instruções

O gerente do projeto te designou a seguinte tarefa: 
você tem que desenvolver um programa que lê o código de 
uma instrução em linguagem de máquina e devolve a correspondente 
da linguagem de alto nível. Por exemplo, se o seu programa ler 
o código 20, ele deve devolver o for. Como você acabou de aprender 
um algoritmo de busca bem eficiente, você decide fazer um programa
 que carrega na memória todas as instruções, e seus respectivos 
 códigos, e depois responde às pesquisas demandadas ao seu programa.
Entrada

A entrada é composta de diversas linhas. A primeira linha contém 
um inteiro n que determina quantas instruções você precisa carregar 
na memória. As n linhas seguintes contém um inteiro e uma palavra que 
caracterizam uma instrução: o primeiro é o código da instrução, e a 
segunda a palavra-chave com, no máximo, 15 caracteres. As demais linhas 
são inteiros que correspondem aos códigos de instruções para os quais 
você precisa determinar a palavra-chave correspondente. A entrada termina 
com EOF.
Saída

A saída é composta pela mesma quantidade de consultas feitas na entrada. 
Para cada inteiro consultado, você deve imprimir a palavra-chave correspondente. 
Se a palavra chave não fizer parte do conjunto de instruções, você deve imprimir 
undefined.
*/

#include <stdio.h>
#include <string.h>

typedef struct {
    int baixoNivel;
    char altoNivel[16];
} instrucao;

void insertionsort(instrucao *v, int l, int r) {
    int j;
    instrucao chave;

    for(int i = 1; i <= r; i++) {
        chave.baixoNivel = v[i].baixoNivel;
        strcpy(chave.altoNivel, v[i].altoNivel);
        j = i;
        while(v[j - 1].baixoNivel > chave.baixoNivel && j > 0) {
            v[j] = v[j - 1];
            j--;
        } 
        v[j].baixoNivel = chave.baixoNivel;
        strcpy(v[j].altoNivel,chave.altoNivel );
    }
}

int buscaBinaria(instrucao *v, int l, int r, int n) {
    if(l > r) return -1;
    int meio = (l + r) / 2;
    if(v[meio].baixoNivel == n) return meio;
    else if(v[meio].baixoNivel > n) r = meio - 1;
    else l = meio + 1;

    buscaBinaria(v, l, r, n);
}

int main() {
    int n;
    scanf("%d", &n);

    instrucao instrucoes[n];
    for(int i = 0; i < n; i++) scanf("%d %s\n", &instrucoes[i].baixoNivel, &instrucoes[i].altoNivel);

    insertionsort(instrucoes, 0, n - 1);
        
    int c;
    while(scanf("%d", &c) != EOF){
        int busca = buscaBinaria(instrucoes, 0, n - 1, c);
        if( busca == -1) printf("undefined\n");
        else printf("%s\n", instrucoes[busca].altoNivel);
    } 

}
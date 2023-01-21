#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define less(A, B) (strcmp(A, B))

typedef struct {
    char japones[85];
    char portugues[85];
} Traducao;

typedef Traducao Item;

void merge(Item *v, int l, int m, int r) {
    Traducao *v2 = malloc(sizeof(Item) * (r - l + 1));
    
    int i = 0, ia = l, ib = m + 1;
    while(ia <= m && ib <= r) {
        if(less(v[ib].japones, v[ia].japones) < 0) {
            v2[i++] = v[ib++];
        }
        else {
            v2[i++] = v[ia++];
        }
    }
    while(ia <= m) {
        v2[i++] = v[ia++]; 
    }

    while(ib <= r) {
        v2[i++] = v[ib++];
    }

    i = 0;
    for(int k = l; k <= r; k++) {
        v[k] = v2[i++];
    }
    free(v2);
}

void mergesort(Item *v, int l, int r) {
    if(l >= r) return;
    int meio = (r - l) / 2 + l;

    mergesort(v, l, meio);
    mergesort(v, meio + 1, r);
    merge(v, l, meio, r);
}

int busca_binaria(Item *dicionario, int l, int r, char *palavra) {
    if(l > r) return -1;

    int meio = (r + l)/2;
    if(strcmp(palavra, dicionario[meio].japones) == 0) 
        return meio;
    else if(less(palavra, dicionario[meio].japones) < 0) 
        r = meio - 1;
    else { 
        l = meio + 1;
    }
    return busca_binaria(dicionario, l, r, palavra);
}

void preenche_dicionario(Traducao *v, int palavras) {
    char b;
    scanf("%c", &b);
    for(int i = 0; i < palavras; i++) {
        fgets(v[i].japones, 85, stdin);
        fgets(v[i].portugues, 85, stdin);
        v[i].japones[strcspn(v[i].japones, "\n")] = 0;      
        v[i].portugues[strcspn(v[i].portugues, "\n")] = 0;      
    }
}

void traduzir(char *palavra, Traducao *dicionario, int palavras_dic) 
{
    int tam = strlen(palavra);
    int indice = busca_binaria(dicionario, 0, palavras_dic, palavra, tam);
    //printf("BUSCA [%s,%d]\n", palavra, indice);
    if(indice == -1) {
        printf("%s", palavra);
    } else {
        printf("%s", dicionario[indice].portugues);
    }
}

void print_dicionario(Traducao *v, int n) {
    for(int i = 0; i < n; i++){
        printf("[%s,%s]\n", v[i].japones, v[i].portugues);
    }
}

int main(void) {
    int instancias;
    scanf("%d", &instancias);

    for(int i = 0; i < instancias; i++) {
        int palavras_dic;
        int linhas;
        scanf("%d %d", &palavras_dic, &linhas);

        Item *dicionario = malloc(sizeof(Item) * palavras_dic);
        if(dicionario == NULL) return 0;

        preenche_dicionario(dicionario, palavras_dic);
        
        mergesort(dicionario, 0, palavras_dic - 1);
        //print_dicionario(dicionario, palavras_dic);

        for(int j = 0; j < linhas; j++) 
        {
            char linha[200];
            Item palavra;
            fgets(linha, 200, stdin);
            int l = 0;
            for(int k = 0; linha[k] != '\0'; k++) 
            {
                if(linha[k] == ' ' || linha [k] == '\n') 
                {
                    palavra.japones[l] = '\0';
                    traduzir(palavra.japones, dicionario, palavras_dic-1);
                    l = 0;
                    printf("%c", linha[k]);
                } else palavra.japones[l++] = linha[k];
            }
        }
        free(dicionario);
        printf("\n");
    }
}
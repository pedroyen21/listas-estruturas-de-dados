#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define exch(A, B) {Item t = A; A = B; B = t;}


typedef struct {
    char codigo[6];
    int votos;
} candidato;

typedef candidato Item;

int median(Item *v, int l, int m, int r) {
    int vm = v[m].votos;
    int vr = v[r].votos;
    int vl = v[l].votos;

    if ((vm <= vl && vl <= vr) || (vr <= vl && vl <= vm)) return l;
    if ((vr <= vm && vm <= vr) || (vr <= vm && vm <= vl)) return m;
    else return r;
}

int partition(Item *v, int l, int r) {
    int x = v[r].votos;
    int i = l - 1;
    for(int j = l; j < r; j++) {
        if(v[j].votos < x) {
            i++;
            exch(v[j], v[i]);
        }
    }
    exch(v[i + 1], v[r]);
    return i + 1;
}

void quicksort(Item *v, int l, int r) {
    if(l >= r) return;
    int med = median(v, l, (r + l) / 2, r);

    exch(v[med], v[r]);
    
    int pivot = partition(v, l, r);
    quicksort(v, l, pivot - 1);
    quicksort(v, pivot + 1, r);
}

void quickselect(Item *v, int p, int l, int r) {
    int j = partition(v, l, r);

    if(j == p) return;
    if(j < p ) 
        quickselect(v, p, j + 1, r);
    else    
        quickselect(v, p, l, j - 1);
}

void print(Item *v, int l, int r) {
    for(int i = l; l <= r; i++) {
        printf("%d ", v[i].codigo);
    }
    printf("\n");
}

void eleitos(Item *v, int venc, int cod) {
    switch (cod)
    {
    case 0:
        Item max = v[0];
        int vts = 0;
        for(int i = 1; i < 100; i++) {
            vts++; 
            if(v[i].votos > max.votos) 
                max = v[i];
        }
        float res = max.votos / vts;
        if(res >= 0.51) 
            printf("%d\n", max.codigo);
        else    
            printf("Segundo turno\n");

        break;
    
    case 1:
        quickselect(v, venc, 100, 999);
        quicksort(v, 100, venc);
        print(v, 100, venc);
    
    case 2:
        quickselect(v, venc, 1000, 9999);
        quicksort(v, 1000, venc);
        print(v, 1000, venc);
    
    case 3:
        quickselect(v, venc, 10000, 99999);
        quicksort(v, 10000, venc);
        print(v, 10000, venc);
    
    default:
        break;
    }
}

int main(void) {
    int votos_validos = 0;
    int votos_invalidos = 0;
    int ncandidatos = 0;

    candidato candidatos[100000];

    int sen_venc;
    int depest_venc;
    int depfed_venc;
    scanf("%d %d %d", &sen_venc, &depfed_venc, &depest_venc);

    char voto[6];
    int k = 0;
    while(scanf("%s", &voto) == 1) {
        if(voto[0] == '-') {
            votos_invalidos++;
            break;
        }
        for(int j = 0; j <= k; j++)
            if(strcmp(candidatos[j].codigo , voto) == 0) {
                candidatos[j].votos++;
                break;
            }
        strcpy(candidatos[k].codigo, voto);
        candidatos[k].votos = 1;
        ncandidatos++;
        votos_validos++;
        k++;
    }

    for(int i = 0; i < ncandidatos; i++) {
        if(candidatos[i].votos > 0) 
            printf("[%s,%d]\n", candidatos[i].codigo, candidatos[i].votos);
    }

    printf("validos: %d\n", votos_validos);
    printf("invalidos: %d\n", votos_invalidos);
    return 0;
}

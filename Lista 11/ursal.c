#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define exch(A, B) {Item t = A; A = B; B = t;}
#define ncandidatos 90000

typedef struct {
    long int codigo;
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

int greater(Item a, Item b) {
    if(a.votos > b.votos) return 1;
    if(a.votos < b.votos) return 0;
    else return a.codigo > b.codigo;
}

int partition(Item *v, int l, int r) {
    Item x = v[r];
    int i = l - 1;
    for(int j = l; j < r; j++) {
        if(greater(v[j], x)) {
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


void printvotos(candidato *v) {
    for(int i = 0; i < ncandidatos; i++) {
        if(v[i].votos > 0) 
            printf("[%ld,%d]\n", v[i].codigo, v[i].votos);
    }
}

void resultado(candidato *v, int l, int r, int n) {

}

int main(void) {
    int votos_validos = 0;
    int votos_invalidos = 0;

    candidato candidatos[ncandidatos];

    int sv;
    int dfv;
    int dev;
    scanf("%d %d %d", &sv, &dfv, &dev);

    long int voto;

    while(scanf("%ld", &voto) == 1) {
        if(voto < 0) votos_invalidos++;
        else {
            votos_validos++;
            if(candidatos[voto].votos > 0) candidatos[voto].votos++;
            else {
                candidatos[voto].votos = 1;
                candidatos[voto].codigo = voto;
            }
        }
    }

    printvotos(candidatos);
    resultado(candidatos, 0, 0);
    printvotos(candidatos);

    quickselect(v, venc, 100, 999);
        quicksort(v, 100, venc);
        print(v, 100, venc);
    //eleitos(candidatos, sen_venc, 1);
    
    printf("validos: %d\n", votos_validos);
    printf("invalidos: %d\n", votos_invalidos);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define exch(A, B) {Item t = A; A = B; B = t;}
#define ncandidatos 100000

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
    //printf("partition l: %d r: %d j: %d ", l, r, j);
    if(j == p) return;
    if(j < p ) {
        quickselect(v, p, j + 1, r);
    }   
    else {    
        quickselect(v, p, l, j - 1);
    }
}


void printvotos(candidato *v) {
    for(int i = 0; i < ncandidatos; i++) {
        if(v[i].votos > 0) 
            printf("pos %i [%ld,%d]\n",i, v[i].codigo, v[i].votos);
    }
}
void resultado_51(candidato *v, int l, int r) {
    int vts = 0;
    candidato max = v[l];
    for(int i = l; i <= r; i++) {
        if(v[i].votos > 0) vts += v[i].votos;

        if(greater(v[i], max))
            max = v[i];
    }
    float res = (float)max.votos / (float)vts;
    //printf("max.votos : %d, votos %d\n", max.votos, vts);
    //printf("res: %f\n", res);
    if(res >= 0.51) printf("%ld\n", max.codigo);
    else printf("Segundo turno\n");
}
void resultado_maioria_simples(candidato *v, int p, int l, int r){
    p += l - 1;
    quickselect(v, p, l, r);
    quicksort(v, l, p);
    for(int i = l; i <= p; i++) {
        printf("%ld ", v[i].codigo);
    }
    printf("\n");
};

int main(void) {
    int votos_validos = 0;
    int votos_invalidos = 0;

    candidato candidatos[ncandidatos];

    int sv;
    int dfv;
    int dev;
    scanf("%d %d %d", &sv, &dfv, &dev);

    long int voto;
    for(int j = 0; j < ncandidatos; j++) 
        candidatos[j].votos = 0;

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
    printf("%d ", votos_validos);
    printf("%d\n", votos_invalidos);

    //printvotos(candidatos);
    resultado_51(candidatos, 10, 99);
    resultado_maioria_simples(candidatos, sv, 100, 999);
    resultado_maioria_simples(candidatos, dfv, 1000, 9999);
    resultado_maioria_simples(candidatos, dev, 10000, 99999);
    
}

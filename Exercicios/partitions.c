#include <stdio.h>
#include <math.h>

int partitions(int n, int m) {
    if(m == 1) return 1;

}
int main () {
    int n, m;
    scanf("%d %d",&n, &m);
    printf("%d %d\n", partitions(n, m));
}
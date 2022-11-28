#include <stdio.h>

int main() {
    int n, sum = 9000;
    printf("%d\n", sum/10);
    printf("%d\n", sum%10);
    for (int i = 0; (sum % 10) != 0 || (sum / 10) != 0; i++)
    {
        printf("%d\n", sum % 10);
        n += sum % 10;
        sum /= 10;
    }
}
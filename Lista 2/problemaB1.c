#include <stdio.h>

int faz_conta_direito(int parcelas, char op) {
    int res, num;
    scanf("%d", &res);

    for (int i = 1; i < parcelas; i++) {
        scanf("%d", &num);
        res = op == '+' ? res + num : res - num;
    }
    return res;
}


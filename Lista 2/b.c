#include <stdio.h>

int faz_conta_direito(int parcelas, char op){
    int a, b;
    scanf("%d",&a);
    if(op == '+'){
         for(int i = 1; i < parcelas; i++){
            scanf("%d",&b);
            a += b;
        }
    }else{
        for(int i = 1; i <= parcelas; i++){
            scanf("%d",&b);
            a -= b;
    }
    }

    return a;
}

int main () {
    printf("%d\n", faz_conta_direito(4,'-'));
}
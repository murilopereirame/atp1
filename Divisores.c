#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>

int main(void){

    setlocale(LC_ALL,"");

    int num, qnt;

    printf("Insira um número inteiro positivo: ");
    scanf("%d", &num);

    for(int i=1; i <= num; i++){
        if(num%i == 0){
            qnt++;
            printf("\n%d é divisor de %d\n", i, num);
        }
    }

    system("pause");

    return 0;
}

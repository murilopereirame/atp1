#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define LIM 100000

int main(void){
    //Imprimir os n primeiros números ímpares;
    
    setlocale(LC_ALL,"");

    int n, qnt=0;

    printf("Insira a quantidade de números impares desejados: ");
    scanf("%d", &n);

    for(int i=0; i <= LIM; i++){
        if(!(i%2 == 0)){
            printf("\nO número %d é ímpar!\n", i);
            qnt++;
        }
        if(qnt == n)
            break;
    }

    system("pause");

    return 0;
}

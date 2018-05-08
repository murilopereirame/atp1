#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void){
    //Encontrar o fatorial de n, com n => 0;
    
    setlocale(LC_ALL,"");

    int n, multi=1;

    printf("Insira um número inteiro positivo igual ou maior que 0: ");
    scanf("%d", &n);
    
    if(n > 0){
        for(int i=1; i<=n; i++){
            multi *= i;
        }
    }

    printf("\n%d! é igual a %d\n", n, multi);

    system("pause");

    return 0;

}

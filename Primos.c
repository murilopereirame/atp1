#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void){
    //Encontre todos os primos no intervalo [a,b];
    
    setlocale(LC_ALL,"");

    int a, b, qnt;

    printf("Insira o intervalo fechado [a,b]: ");
    scanf("%d %d", &a, &b);

    for(; a < b; a++){
        if(a > 1){
            if(a == 2)
                printf("\n2 é primo!\n");
            else{
                for(int i=1; i <= a/2; i++){
                    if(a%i == 0)
                        qnt++;
                    if(qnt > 1)
                        break;
                }
                if(qnt == 1)
                    printf("\n%d é primo!\n", a);
                qnt = 0;
            }
        }
    }

    system("pause");

    return 0;
}

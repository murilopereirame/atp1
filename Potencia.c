#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(void){
    //Encontre todos os primos no intervalo [a,b];
    
    setlocale(LC_ALL,"");

    float a, resultado=1;
    int b;

    printf("Insira a base e o expoente: ");
    scanf("%f %d", &a, &b);

    resultado = a;

    for(int i=1; i< b; i++){
        resultado = resultado * a;
    }

    printf("\n%.2f elevado a %d é %.2f\n", a, b, resultado);

    system("pause");

    return 0;
}

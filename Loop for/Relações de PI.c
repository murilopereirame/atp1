#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

#define LIM 1000

int main(void){
	
	setlocale(LC_ALL, """");
	
    int exp;
    double R1, R2, R3, R4, R5, somaR1, somaR2, somaR3, somaR4, somaR5, sinal, num, den;

    somaR1 = 0;
    somaR4 = 1;
    den = 1.0;
    num = 2.0;
    sinal = 1.0;
	int i = 1;
    for(; i <= LIM; i++){
        somaR1 += sinal*(1.0/(double)(2*i-1));
        somaR2 += (1.0/(double)(i*i));
        somaR3 += sinal * (1.0/(double)pow((2*i - 1), 3));
        somaR4 = somaR4 * (num/den);

        if(num > den)
            den += 2;
        else
            num += 2;

        exp = i - 1;
        somaR5 += (1.0/pow(16, exp)) * ((4.0/(8*exp + 1)) - (2.0/(8*exp + 4)) - (1.0/(8*exp + 5)) - (1.0/(8*exp + 6)));
        sinal *= -1.0;
    }

    R1 = 4.0 * somaR1;
    R2 = sqrt(6.0*(somaR2));
    R3 = cbrt(somaR3 * 32.0);
    R4 = 2.0 * somaR4;
    R5 = somaR5;

    printf("PI definido pela biblioteca MATH.H: %lf\n", M_PI);
    printf("PI definido pela relação R1: %lf\n", R1);
    printf("PI definido pela relação R2: %lf\n", R2);
    printf("PI definido pela relação R3: %lf\n", R3);
    printf("PI definido pela relação R4: %lf\n", R4);
    printf("PI definido pela relação R5: %lf\n", R5);

    system("pause");

    return 0;
}

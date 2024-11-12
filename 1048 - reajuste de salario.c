/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1048
*/
#include <stdio.h>
int main()
{
    double sal, novSal, reajus;
    scanf("%lf", &sal);
    if (sal <= 400)
    {
        novSal = sal + (sal * 0.15);
        reajus = sal * 0.15;
        printf("Novo salario: %.2lf\n", novSal);
        printf("Reajuste ganho: %.2lf\n", reajus);
        printf("Em percentual: 15 %%\n");
    }
    if (sal <= 800 && sal > 400)
    {
        novSal = sal + (sal * 0.12);
        reajus = sal * 0.12;
        printf("Novo salario: %.2lf\n", novSal);
        printf("Reajuste ganho: %.2lf\n", reajus);
        printf("Em percentual: 12 %%\n");
    }
    if (sal <= 1200 && sal > 800)
    {
        novSal = sal + (sal * 0.1);
        reajus = sal * 0.1;
        printf("Novo salario: %.2lf\n", novSal);
        printf("Reajuste ganho: %.2lf\n", reajus);
        printf("Em percentual: 10 %%\n");
    }
    if (sal <= 2000 && sal > 1200)
    {
        novSal = sal + (sal * 0.07);
        reajus = sal * 0.07;
        printf("Novo salario: %.2lf\n", novSal);
        printf("Reajuste ganho: %.2lf\n", reajus);
        printf("Em percentual: 7 %%\n");
    }
    if (sal > 2000)
    {
        novSal = sal + (sal * 0.04);
        reajus = sal * 0.04;
        printf("Novo salario: %.2lf\n", novSal);
        printf("Reajuste ganho: %.2lf\n", reajus);
        printf("Em percentual: 4 %%\n");
    }
    return 0;
}
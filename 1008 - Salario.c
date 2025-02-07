/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1008
*/

#include <stdio.h>
int main()
{
    int num, hour;
    double dol, sal;
    scanf("%d %d %lf", &num, &hour, &dol);
    sal = (double)hour * dol;
    printf("NUMBER = %d\n", num);
    printf("SALARY = U$ %.2lf\n", sal);
    return 0;
}
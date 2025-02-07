/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1010
*/

#include <stdio.h>
int main()
{
    int a1, b1, a2, b2;
    double c1, c2, sum;
    scanf("%d %d %lf", &a1, &b1, &c1);
    scanf("%d %d %lf", &a2, &b2, &c2);
    sum = ((double)b1 * c1) + ((double)b2 * c2);
    printf("VALOR A PAGAR: R$ %.2lf\n", sum);
    return 0;
}
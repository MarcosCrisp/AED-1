/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1006
*/

#include <stdio.h>
int main()
{
    double a, b, c, med;
    scanf("%lf", &a);
    scanf("%lf", &b);
    scanf("%lf", &c);

    a = a * 2;
    b = b * 3;
    c = c * 5;

    med = (a + b + c) / 10;
    printf("MEDIA = %.1lf\n", med);
    return 0;
}
/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1002
*/

#include <stdio.h>

int main()
{
    double area, raio, pi = 3.14159;
    scanf("%lf", &raio);
    area = pi * (raio * raio);
    printf("A=%.4lf\n", area);
    return 0;
}
/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1011
*/
#include <stdio.h>
#include <math.h>

int main()
{
    double raio, volume, pi = 3.14159;
    double var = (double)4 / 3;
    scanf("%lf", &raio);
    volume = var * pi * pow(raio, 3);
    printf("VOLUME = %.3lf\n", volume);
    return 0;
} 
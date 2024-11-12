/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1017
*/
#include <stdio.h>
int main()
{
    int temp, km;
    double litros, distancia;
    scanf("%d %d", &temp, &km);
    distancia = temp * km;
    litros = (double)distancia / 12;
    printf("%.3lf\n", litros);

    return 0;
}

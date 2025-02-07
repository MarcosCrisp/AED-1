/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1012
*/


#include <stdio.h>
#include <math.h>

int main()
{
    double A, B, C, pi = 3.14159;
    double retan, tria, circulo, trapezio, quadrado;
    scanf("%lf %lf %lf", &A, &B, &C);

    tria = (A * C) / 2;
    circulo = pow(C, 2) * pi;
    trapezio = ((A + B) * C) / 2;
    quadrado = pow(B, 2);
    retan = A * B;

    printf("TRIANGULO: %.3lf\n", tria);
    printf("CIRCULO: %.3lf\n", circulo);
    printf("TRAPEZIO: %.3lf\n", trapezio);
    printf("QUADRADO: %.3lf\n", quadrado);
    printf("RETANGULO: %.3lf\n", retan);
    return 0;
}
/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1015
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    double x1, y1, x2, y2, distanciaX, distanciaY, total;
    scanf("%lf %lf", &x1, &y1);
    scanf("%lf %lf", &x2, &y2);

    distanciaX = pow(x2 - x1, 2);
    distanciaY = pow(y2 - y1, 2);
    total = sqrt(distanciaX + distanciaY);
    printf("%.4lf\n", total);
    return 0;
}

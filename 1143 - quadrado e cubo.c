/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1143
*/

#include <stdio.h>
#include <math.h>

int main()
{
    int m, i, quad, cub;
    scanf("%d", &m);
    for (i = 1; i < m + 1; i++)
    {
        quad = pow(i, 2);
        cub = pow(i, 3);
        printf("%d ", i);
        printf("%d ", quad);
        printf("%d\n", cub);
    }
    return 0;
}
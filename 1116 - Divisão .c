#include <stdio.h>
int main()
{
    int testes, j = 0;
    double x, y, resultado;
    scanf("%d", &testes);
    while (j != testes)
    {
        scanf("%lf %lf", &x, &y);
        if (y == 0)
        {
            printf("divisao impossivel\n");
        }
        else if (x == 0)
        {
            printf("0.0\n");
        }
        else
        {
            resultado = x / y;
            printf("%.1lf\n", resultado);
        }
        j++;
    }
    return 0;
}
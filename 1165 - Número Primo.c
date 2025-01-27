#include <stdio.h>

int main()
{
    int testes, j = 0;
    scanf("%d", &testes);
    while (j != testes)
    {
        int num;
        scanf("%d", &num);
        int contador = 0;
        for (int i = 1; i <= num; i++)
        {
            if (num % i == 0)
            {
                contador++;
            }
        }
        if (contador == 2)
        {
            printf("%d eh primo\n", num);
        }
        else
        {
            printf("%d nao eh primo\n", num);
        }
    j++;
    }
    return 0;
}

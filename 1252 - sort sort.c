/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1252
*/
 
#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b, void *m_ptr)
{
    int m = *(int *)m_ptr;
    int x = *(int *)a;
    int y = *(int *)b;

    int mod_x = x % m;
    int mod_y = y % m;

    if (mod_x != mod_y)
    {
        return mod_x - mod_y;
    }

    int impar_x = x % 2 != 0;
    int impar_y = y % 2 != 0;

    if (impar_x && !impar_y)
    {
        return -1;
    }
    if (!impar_x && impar_y)
    {
        return 1;
    }

    if (impar_x && impar_y)
    {
        return y - x;
    }

    return x - y;
}

int main()
{
    int n, m;

    while (scanf("%d %d", &n, &m) == 2)
    {
        if (n == 0 && m == 0)
        {
            printf("0 0\n");
            break;
        }

        int numeros[n];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &numeros[i]);
        }

        qsort_r(numeros, n, sizeof(int), comparar, &m);

        printf("%d %d\n", n, m);
        for (int i = 0; i < n; i++)
        {
            printf("%d\n", numeros[i]);
        }
    }

    return 0;
}

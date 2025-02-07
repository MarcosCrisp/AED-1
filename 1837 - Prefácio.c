/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1837
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, q, r;
    scanf("%d %d", &a, &b);

    if (b == 0)
    {
        return 1;
    }

    q = a / b;
    r = a % b;

    if (r < 0)
    {
        if (b > 0)
        {
            q -= 1;
            r += b;
        }
        else
        {
            q += 1;
            r -= b;
        }
    }
    printf("%d %d\n", q, r);

    return 0;
}
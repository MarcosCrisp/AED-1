/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1074
*/
#include <stdio.h>

int main()
{
    int testes;
    scanf("%d", &testes);
    while (testes != 0)
    {
        int num;
        scanf("%d", &num);
        if (num == 0)
        {
            printf("NULL\n");
        }
        if (num > 0)
        {
            if (num % 2 == 0)
            {
                printf("EVEN POSITIVE\n");
            }
            else
            {
                printf("ODD POSITIVE\n");
            }
        }
        if (num < 0)
        {
            if (num % 2 == 0)
            {
                printf("EVEN NEGATIVE\n");
            }
            else
            {
                printf("ODD NEGATIVE\n");
            }
        }
        testes--;
    }
    return 0;
}
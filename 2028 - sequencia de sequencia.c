/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 2028
*/

#include <stdio.h>

int main()
{
    int N, caso = 0;
    while (scanf("%d", &N) != EOF)
    {
        caso++;
        int total = 1;
        for (int i = 1; i <= N; i++)
        {
            total += i;
        }

        printf("Caso %d: %d %s\n", caso, total, total == 1 ? "numero" : "numeros");

        printf("0");
        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j < i; j++)
            {
                printf(" %d", i);
            }
        }
        printf("\n\n");
    }
    return 0;
}
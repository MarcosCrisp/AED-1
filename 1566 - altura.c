/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1566
*/

#include <stdio.h>
#include <stdlib.h>

int comparar(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int num_casos;
    scanf("%d", &num_casos);

    while (num_casos--)
    {
        int num_pessoas;
        scanf("%d", &num_pessoas);

        int *alturas = (int *)malloc(num_pessoas * sizeof(int));
        if (!alturas)
            return 1;

        for (int i = 0; i < num_pessoas; i++)
        {
            scanf("%d", &alturas[i]);
        }

        qsort(alturas, num_pessoas, sizeof(int), comparar);

        for (int i = 0; i < num_pessoas; i++)
        {
            if (i > 0)
                printf(" ");
            printf("%d", alturas[i]);
        }
        printf("\n");

        free(alturas);
    }

    return 0;
}
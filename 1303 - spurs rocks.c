/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1303
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    int pontos;
    int pontos_marcados;
    int pontos_sofridos;
} Time;

int comparar(const void *a, const void *b)
{
    Time *t1 = (Time *)a;
    Time *t2 = (Time *)b;

    if (t1->pontos != t2->pontos)
        return t2->pontos - t1->pontos;

    double cesta_average1 = (t1->pontos_sofridos == 0) ? t1->pontos_marcados : (double)t1->pontos_marcados / t1->pontos_sofridos;
    double cesta_average2 = (t2->pontos_sofridos == 0) ? t2->pontos_marcados : (double)t2->pontos_marcados / t2->pontos_sofridos;

    if (cesta_average1 != cesta_average2)
        return (cesta_average1 > cesta_average2) ? -1 : 1;

    if (t1->pontos_marcados != t2->pontos_marcados)
        return t2->pontos_marcados - t1->pontos_marcados;

    return t1->id - t2->id;
}

int main()
{
    int n, instancia = 0;
    while (scanf("%d", &n) == 1 && n)
    {
        Time times[100];
        for (int i = 0; i < n; i++)
        {
            times[i].id = i + 1;
            times[i].pontos = 0;
            times[i].pontos_marcados = 0;
            times[i].pontos_sofridos = 0;
        }

        int jogos = (n * (n - 1)) / 2;
        for (int i = 0; i < jogos; i++)
        {
            int x, y, z, w;
            scanf("%d %d %d %d", &x, &y, &z, &w);

            times[x - 1].pontos_marcados += y;
            times[x - 1].pontos_sofridos += w;
            times[z - 1].pontos_marcados += w;
            times[z - 1].pontos_sofridos += y;

            if (y > w)
            {
                times[x - 1].pontos += 2;
                times[z - 1].pontos += 1;
            }
            else
            {
                times[z - 1].pontos += 2;
                times[x - 1].pontos += 1;
            }
        }

        qsort(times, n, sizeof(Time), comparar);

        if (instancia)
            printf("\n");
        printf("Instancia %d\n", ++instancia);

        for (int i = 0; i < n; i++)
        {
            if (i)
                printf(" ");
            printf("%d", times[i].id);
        }
        printf("\n");
    }
    return 0;
}

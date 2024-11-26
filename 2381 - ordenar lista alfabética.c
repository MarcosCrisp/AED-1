/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 2381
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ordenar_lista(char alunos[][21], int quantia_alunos)
{
    int i, j;
    char aux[21];
    for (i = 0; i < quantia_alunos - 1; i++)
    {
        for (j = i + 1; j < quantia_alunos; j++)
        {
            if (strcmp(alunos[i], alunos[j]) > 0)
            {
                strcpy(aux, alunos[i]);
                strcpy(alunos[i], alunos[j]);
                strcpy(alunos[j], aux);
            }
        }
    }
}

int main()
{
    int quantia_alunos, vence, i;
    char alunos[101][21]; // 100 alunos até 20 caracteres
    scanf("%d %d", &quantia_alunos, &vence);

    for (i = 0; i < quantia_alunos; i++)
    {
        scanf("%s", alunos[i]);
    }

    ordenar_lista(alunos, quantia_alunos);
    printf("%s\n", alunos[vence - 1]);
    return 0;
}
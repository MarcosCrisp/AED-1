/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1069
*/

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1001

int contar_diamantes(char *linha)
{
    int count = 0, abrir = 0;
    for (int i = 0; linha[i] != '\0'; i++)
    {
        if (linha[i] == '<')
        {
            abrir++;
        }
        else if (linha[i] == '>' && abrir > 0)
        {
            count++;
            abrir--;
        }
    }
    return count;
}

int main()
{
    int N;
    char linha[MAX_LENGTH];

    scanf("%d", &N);
    getchar();

    while (N--)
    {
        fgets(linha, MAX_LENGTH, stdin);
        printf("%d\n", contar_diamantes(linha));
    }

    return 0;
}

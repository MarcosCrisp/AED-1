/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 2160
*/

#include <stdio.h>
#include <string.h>

int main()
{
    char L[501];
    fgets(L, 501, stdin);

    // Removendo a quebra de linha, se existir
    if (L[strlen(L) - 1] == '\n')
    {
        L[strlen(L) - 1] = '\0';
    }

    if (strlen(L) <= 80)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}
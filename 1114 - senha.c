/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1114
*/
#include <stdio.h>
int main()
{
    int senha = 2002, acesso;
    while (acesso != senha)
    {
        scanf("%d", &acesso);
        if (acesso != senha)
        {
            printf("Senha Invalida\n");
        }
    }
    printf("Acesso Permitido\n");
    return 0;
}
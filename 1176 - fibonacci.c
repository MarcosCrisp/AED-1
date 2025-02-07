/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1176
*/

#include <stdio.h>

int main()
{
    int testes;
    long long int vet[61];
    vet[0] = 0;
    vet[1] = 1;
    for (int i = 2; i <= 63; i++)
    {
        vet[i] = vet[i - 1] + vet[i - 2];
    }
    scanf("%d", &testes);
    for (int j = 0; j < testes; j++)
    {
        int num;
        scanf("%d", &num);
        printf("Fib(%d) = %lld\n", num, vet[num]);
    }
    return 0;
}
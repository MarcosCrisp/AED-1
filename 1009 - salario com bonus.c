/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1009
*/

#include <stdio.h>

int main()
{
    char nome[10];
    double salario, vendas, soma;
    scanf("%s", &nome);
    scanf("%lf", &salario);
    scanf("%lf", &vendas);
    vendas = 0.15 * vendas;
    soma = salario + vendas;
    printf("TOTAL = R$ %.2lf\n", soma);

    return 0;
} 
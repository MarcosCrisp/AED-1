#include <stdio.h>
int main()
{
    double item, quantidade, preco;
    scanf("%lf %lf", &item, &quantidade);
    if (item == 1)
    {
        preco = 4 * quantidade;
        printf("Total: R$ %.2lf\n", preco);
    }
    else if (item == 2)
    {
        preco = 4.5 * quantidade;
        printf("Total: R$ %.2lf\n", preco);
    }
    else if (item == 3)
    {
        preco = 5 * quantidade;
        printf("Total: R$ %.2lf\n", preco);
    }
    else if (item == 4)
    {
        preco = 2 * quantidade;
        printf("Total: R$ %.2lf\n", preco);
    }
    else if (item == 5)
    {
        preco = 1.5 * quantidade;
        printf("Total: R$ %.2lf\n", preco);
    }
    return 0;
}
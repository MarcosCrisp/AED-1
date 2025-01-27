#include <stdio.h>

int max(int a, int b, int c)
{
    int max = (a > b) ? a : b;
    return (max > c) ? max : c;
}

int main()
{
    int x, y, z, maior;
    scanf("%d %d %d", &x, &y, &z);
    maior = max(x, y, z);
    printf("%d eh o maior\n", maior);
    return 0;
}
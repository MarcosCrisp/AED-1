/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1855
*/

#include <stdio.h>

int main()
{
    int l, a;
    char m[100][100];
    int v[100][100];

    scanf("%d %d", &l, &a);
    for (int i = 0; i < a; i++)
        scanf("%s", m[i]);

    int x = 0, y = 0;
    int dx = 0, dy = 1;

    while (1)
    {
        if (x < 0 || x >= a || y < 0 || y >= l)
        {
            printf("!\n");
            return 0;
        }

        if (v[x][y])
        {
            printf("!\n");
            return 0;
        }

        v[x][y] = 1;

        if (m[x][y] == '*')
        {
            printf("*\n");
            return 0;
        }

        switch (m[x][y])
        {
        case '>':
            dx = 0;
            dy = 1;
            break;
        case '<':
            dx = 0;
            dy = -1;
            break;
        case 'v':
            dx = 1;
            dy = 0;
            break;
        case '^':
            dx = -1;
            dy = 0;
            break;
        case '.':
            break;
        default:
            printf("!\n");
            return 0;
        }
        x += dx;
        y += dy;
    }
    return 0;
}

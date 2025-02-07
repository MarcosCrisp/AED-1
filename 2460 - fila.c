/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 2460
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fila
{
    int id;
    int tamanho;
};

void inicializar(struct fila *fila);
void adicionar(int id, struct fila *fila);
void remover(int id, struct fila *fila);
void mostrarFila(struct fila *fila);

int main()
{
    int num_pessoas, id, num_saidas;

    scanf("%d", &num_pessoas);

    struct fila fila[num_pessoas];
    inicializar(fila);

    for (int i = 0; i < num_pessoas; i++)
    {
        scanf("%d", &id);
        adicionar(id, fila);
    }

    scanf("%d", &num_saidas);

    for (int i = 0; i < num_saidas; i++)
    {
        scanf("%d", &id);
        remover(id, fila);
    }

    mostrarFila(fila);

    return 0;
}

void inicializar(struct fila *fila)
{
    fila->tamanho = 0;
}

void adicionar(int id, struct fila *fila)
{
    fila[fila->tamanho].id = id;
    (fila->tamanho)++;
}

void remover(int id, struct fila *fila)
{
    for (int i = 0; i < fila->tamanho; i++)
    {
        if (id == fila[i].id)
        {
            for (int j = i; j < fila->tamanho - 1; j++)
            {
                fila[j].id = fila[j + 1].id;
            }
            fila->tamanho--;
            return;
        }
    }
}

void mostrarFila(struct fila *fila)
{
    for (int i = 0; i < fila->tamanho; i++)
    {
        if (i < fila->tamanho - 1)
        {
            printf("%d ", fila[i].id);
        }
        else
        {
            printf("%d\n", fila[i].id);
        }
    }
}
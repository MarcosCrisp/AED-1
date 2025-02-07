/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 2065
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Dado;

struct Fila
{
    Dado *itens;
    int capacidade;
    int fim;
    int inicio;
};

typedef struct Fila *PtrFila;

PtrFila criarFila(int max);
void destruirFila(PtrFila fila);
bool filaCheia(PtrFila fila);
bool filaVazia(PtrFila fila);
bool inserirFila(PtrFila fila, Dado valor);
bool removerFila(PtrFila fila, Dado *valor);

int main()
{
    int i, numCaixas, numClientes;

    scanf("%d", &numCaixas);
    int temposCaixas[numCaixas];
    scanf("%d", &numClientes);
    int temposClientes[numClientes];

    PtrFila caixas = criarFila(numCaixas);
    PtrFila clientes = criarFila(numClientes);

    for (i = 0; i < numCaixas; i++)
    {
        scanf("%d", &temposCaixas[i]);
        inserirFila(caixas, temposCaixas[i]);
    }

    for (i = 0; i < numClientes; i++)
    {
        scanf("%d", &temposClientes[i]);
        inserirFila(clientes, temposClientes[i]);
    }

    int temposProcessamento[numCaixas];
    int t = 0;
    while (t < numClientes)
    {
        if (t < numCaixas)
        {
            int tempoCliente;
            removerFila(clientes, &tempoCliente);
            temposProcessamento[t] = tempoCliente * temposCaixas[t];
            t++;
        }
        else
        {
            int tempoCliente;
            removerFila(clientes, &tempoCliente);

            int menorTempo = temposProcessamento[0];
            int indiceMenor = 0;
            for (i = 0; i < numCaixas; i++)
                if (menorTempo > temposProcessamento[i])
                {
                    menorTempo = temposProcessamento[i];
                    indiceMenor = i;
                }
            temposProcessamento[indiceMenor] += tempoCliente * temposCaixas[indiceMenor];

            t++;
        }
    }

    int maiorTempo = temposProcessamento[0];
    for (i = 0; i < numCaixas; i++)
    {
        if (maiorTempo < temposProcessamento[i])
            maiorTempo = temposProcessamento[i];
    }

    printf("%d\n", maiorTempo);

    destruirFila(caixas);
    destruirFila(clientes);

    return 0;
}

PtrFila criarFila(int max)
{
    if (max < 1)
    {
        return NULL;
    }

    PtrFila fila = malloc(sizeof(struct Fila));
    if (fila != NULL)
    {
        fila->fim = -1;
        fila->inicio = 0;
        fila->capacidade = max;
        fila->itens = malloc(sizeof(Dado) * fila->capacidade);
        if (fila->itens == NULL)
        {
            free(fila);
            fila = NULL;
        }
    }

    return fila;
}

void destruirFila(PtrFila fila)
{
    free(fila->itens);
    free(fila);
}

bool filaCheia(PtrFila fila)
{
    if (fila != NULL)
        return fila->fim == fila->capacidade - 1;
    else
        return false;
}

bool filaVazia(PtrFila fila)
{
    if (fila != NULL)
        return fila->fim < fila->inicio;
    else
        return false;
}

bool inserirFila(PtrFila fila, Dado valor)
{
    if (fila == NULL)
        return false;
    if (filaCheia(fila))
        return false;

    fila->fim += 1;
    fila->itens[fila->fim] = valor;
    return true;
}

bool removerFila(PtrFila fila, Dado *valor)
{
    if (fila == NULL)
        return false;
    if (filaVazia(fila))
        return false;

    *valor = fila->itens[fila->inicio];
    fila->inicio += 1;
    return true;
}

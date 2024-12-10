/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: Entrega de AED
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 400000; // constante para tamanho do vetor

// Função para trocar dois elementos
void troca(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição para o QuickSort
int partition(int v[], int low, int high)
{
    int pivot = v[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (v[j] < pivot)
        {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[high]);
    return i + 1;
}

// Função principal do QuickSort
void QuickSort(int v[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(v, low, high);
        QuickSort(v, low, pi - 1);
        QuickSort(v, pi + 1, high);
    }
}

int main()
{
    clock_t t;
    int vetor[TAM];

    srand((unsigned)time(NULL));

    for (int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    t = clock();
    QuickSort(vetor, 0, TAM - 1);
    t = clock() - t;

    printf("Tempo de execucao: %lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000)));

    return 0;
}

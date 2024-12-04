#include <stdio.h>
#include <stdlib.h>
#include <time.h> //clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 20000; // constante para tamanho do vetor

void InsertionSort(int v[TAM])
{
    int i, j, x;
    for (j = 0; j < TAM; j++)
    {
        x = v[j];
        for (i = j - 1; i >= 0 && v[i] > x; i--)
        {
            v[i + 1] = v[i];
        }
        v[i + 1] = x;
    }
}

int main()
{
    clock_t t; // variável para armazenar tempo
    int vetor[TAM];

    // semente de aleatoriedade
    srand((unsigned)time(NULL));

    // geração aleatório dos valores do vetor
    for (int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    // Verificando tempo de execução do bubble sort=> t2
    t = clock(); // armazena tempo
    InsertionSort(vetor);
    t = clock() - t; // tempo final - tempo

    // imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000))); // conversão para double

    return 0;
}
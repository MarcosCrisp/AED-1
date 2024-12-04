/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: Entrega de AED
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // clock(), CLOCKS_PER_SEC e clock_t

int const TAM = 400000; // constante para tamanho do vetor

// Função para mesclar dois subvetores ordenados
void Intercala(int v[], int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    int* esquerda = (int*)malloc(n1 * sizeof(int));
    int* direita = (int*)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        esquerda[i] = v[inicio + i];
    for (int j = 0; j < n2; j++)
        direita[j] = v[meio + 1 + j];

    int i = 0, j = 0, k = inicio;

    while (i < n1 && j < n2) {
        if (esquerda[i] <= direita[j]) {
            v[k] = esquerda[i];
            i++;
        } else {
            v[k] = direita[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        v[k] = esquerda[i];
        i++;
        k++;
    }

    while (j < n2) {
        v[k] = direita[j];
        j++;
        k++;
    }
    free(esquerda);
    free(direita);
}

// Função recursiva para dividir e ordenar o vetor
void mergeSort(int v[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;

        mergeSort(v, inicio, meio);
        mergeSort(v, meio + 1, fim);
        Intercala(v, inicio, meio, fim);
    }
}

int main() {
    clock_t t; // variável para armazenar tempo
    int vetor[TAM];

    // semente de aleatoriedade
    srand((unsigned)time(NULL));

    // geração aleatória dos valores do vetor
    for (int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    // Verificando tempo de execução do Merge Sort
    t = clock(); // armazena tempo
    mergeSort(vetor, 0, TAM - 1);
    t = clock() - t; // tempo final - inicial

    // imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000))); // conversão para double

    return 0;
}

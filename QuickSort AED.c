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
void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição para o QuickSort
int partition(int v[], int low, int high) {
    int pivot = v[high]; // pivô é o último elemento
    int i = low - 1;     // índice do menor elemento

    for (int j = low; j < high; j++) {
        if (v[j] < pivot) {
            i++;
            troca(&v[i], &v[j]);
        }
    }
    troca(&v[i + 1], &v[high]);
    return i + 1;
}

// Função principal do QuickSort
void QuickSort(int v[], int low, int high) {
    if (low < high) {
        int pi = partition(v, low, high); // índice do pivô
        QuickSort(v, low, pi - 1);        // ordena elementos antes do pivô
        QuickSort(v, pi + 1, high);       // ordena elementos depois do pivô
    }
}

int main() {
    clock_t t; // variável para armazenar tempo
    int vetor[TAM];

    // semente de aleatoriedade
    srand((unsigned)time(NULL));

    // geração aleatório dos valores do vetor
    for (int a = 0; a < TAM; a++)
        vetor[a] = rand() % TAM;

    // Verificando tempo de execução do QuickSort
    t = clock(); // armazena tempo
    QuickSort(vetor, 0, TAM - 1);
    t = clock() - t; // tempo final - tempo inicial

    // imprime o tempo na tela
    printf("Tempo de execucao: %lf ms\n", ((double)t) / ((CLOCKS_PER_SEC / 1000))); // conversão para double

    return 0;
}

/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1383 alocação dinâmica
*/

#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

int linha(int** matriz, int linha) {
    int numeros[SIZE + 1] = {0};
    
    for (int j = 0; j < SIZE; j++) {
        int num = matriz[linha][j];
        if (num < 1 || num > 9 || numeros[num] == 1) {
            return 0;
        }
        numeros[num] = 1;
    }
    return 1;
}

int coluna(int** matriz, int coluna) {
    int numeros[SIZE + 1] = {0};
    
    for (int i = 0; i < SIZE; i++) {
        int num = matriz[i][coluna];
        if (num < 1 || num > 9 || numeros[num] == 1) {
            return 0;
        }
        numeros[num] = 1;
    }
    return 1;
}

int Regiao(int** matriz, int inicioLinha, int inicioColuna) {
    int numeros[SIZE + 1] = {0};
    
    for (int i = inicioLinha; i < inicioLinha + 3; i++) {
        for (int j = inicioColuna; j < inicioColuna + 3; j++) {
            int num = matriz[i][j];
            if (num < 1 || num > 9 || numeros[num] == 1) {
                return 0;
            }
            numeros[num] = 1;
        }
    }
    return 1;
}

int verificarSudoku(int** matriz) {
    for (int i = 0; i < SIZE; i++) {
        if (!linha(matriz, i)) {
            return 0;
        }
    }
    
    for (int j = 0; j < SIZE; j++) {
        if (!coluna(matriz, j)) {
            return 0;
        }
    }
    
    for (int i = 0; i < SIZE; i += 3) {
        for (int j = 0; j < SIZE; j += 3) {
            if (!Regiao(matriz, i, j)) {
                return 0;
            }
        }
    }
    
    return 1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int instancia = 1; instancia <= n; instancia++) {
        int** matriz = (int**)malloc(SIZE * sizeof(int*));
        for (int i = 0; i < SIZE; i++) {
            matriz[i] = (int*)malloc(SIZE * sizeof(int));
        }
        
        // Ler a matriz
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                scanf("%d", &matriz[i][j]);
            }
        }
        
        printf("Instancia %d\n", instancia);
        if (verificarSudoku(matriz)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
        
        for (int i = 0; i < SIZE; i++) {
            free(matriz[i]);
        }
        free(matriz);
    }
    
    return 0;
} 
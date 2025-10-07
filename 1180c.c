/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1165
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int *x = (int*)malloc(n * sizeof(int));
    
    if (x == NULL) {
        printf("Erro de alocacao de memoria!\n");
        return 1;
    }
    
    int *ptr = x;
    for (int i = 0; i < n; i++) {
        scanf("%d", ptr);
        ptr++;
    }
    
    int menor = *x;
    int posicao = 0;
    
    ptr = x;
    for (int i = 0; i < n; i++) {
        if (*ptr < menor) {
            menor = *ptr;
            posicao = i;
        }
        ptr++;
    }
    
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);
    
    free(x);
    
    return 0;
} 
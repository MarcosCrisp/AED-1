/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1165
*/

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    int menor, posicao, valor;
    
    scanf("%d", &valor);
    menor = valor;
    posicao = 0;
    
    for (int i = 1; i < n; i++) {
        scanf("%d", &valor);
        
        if (valor < menor) {
            menor = valor;
            posicao = i;
        }
    }
    
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", posicao);
    
    return 0;
}
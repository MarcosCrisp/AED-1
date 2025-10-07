/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1068
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char expr[1010];
    int *pilha;
    int top, i, n, erro;

    while (fgets(expr, 1010, stdin) != NULL) {
        n = strlen(expr);
        pilha = (int*) malloc(n * sizeof(int)); 
        top = 0;
        erro = 0;

        for (i = 0; i < n; i++) {
            if (expr[i] == '(') {
                pilha[top] = '('; 
                top++;
            }
            else if (expr[i] == ')') {
                if (top == 0) {
                    erro = 1; 
                } else {
                    top--; 
                }
            }
        }

        if (erro == 0 && top == 0) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }

        free(pilha); 
    }

    return 0;
}
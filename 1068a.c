/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1068
*/

#include <stdio.h>
#include <string.h>

#define MAX 1010

int main() {
    char expr[MAX];
    int pilha[MAX];
    int top, i, n, erro;

    while (fgets(expr, MAX, stdin) != NULL) {
        top = 0;     
        erro = 0;     
        n = strlen(expr);

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
    }

    return 0;
}
/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1197
*/

#include <stdio.h>

int main(){
    int vel, tempo;
    while(scanf("%d %d", &vel, &tempo) != EOF)
        printf("%d\n", vel*tempo*2);
}
/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1014
*/

#include <stdio.h>
int main() {
    int km;
    double cons, result;
    scanf("%d %lf", &km, &cons);
    result = (double) km / cons;
    printf("%.3lf km/l\n", result);
    return 0;
}


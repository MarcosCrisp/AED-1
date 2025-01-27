/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1005
*/

#include <stdio.h>

int main() {
    double A, B, media;
    scanf("%lf %lf", &A, &B);
    A = A*0.35;
    B = B*0.75;

    media = (((A+B)/11))*10;
    printf("MEDIA = %.5lf\n", media);
    return 0;
}
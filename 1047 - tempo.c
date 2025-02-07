/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1047
*/

#include <stdio.h>

int main()
{
    int horaInicial, minutoInicial, horaFinal, minutoFinal;
    int duracaoHoras, duracaoMinutos, totalMinutosInicial, totalMinutosFinal, duracaoTotal;

    scanf("%d %d %d %d", &horaInicial, &minutoInicial, &horaFinal, &minutoFinal);

    totalMinutosInicial = horaInicial * 60 + minutoInicial;
    totalMinutosFinal = horaFinal * 60 + minutoFinal;

    if (totalMinutosFinal <= totalMinutosInicial)
    {
        duracaoTotal = (24 * 60 - totalMinutosInicial) + totalMinutosFinal;
    }
    else
    {
        duracaoTotal = totalMinutosFinal - totalMinutosInicial;
    }

    duracaoHoras = duracaoTotal / 60;
    duracaoMinutos = duracaoTotal % 60;

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duracaoHoras, duracaoMinutos);

    return 0;
}
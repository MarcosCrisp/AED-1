#include <stdio.h>
int main()
{
    int dias, ano, mes, dias_rest;
    scanf("%i", &dias);
    ano = dias/365;
    mes = (dias%365)/30;
    dias_rest = ((dias%365)%30);
    printf("%i ano(s)\n%i mes(es)\n%i dia(s)", ano,mes,dias_rest);
    return 0;
}

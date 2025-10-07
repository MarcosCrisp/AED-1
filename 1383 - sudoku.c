/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1383
*/
  
#include <stdio.h>
#define LINHAS 9
#define COLUNAS 9

int linhas_repete(int linha[COLUNAS])
{
    int contador[10] = {0};
    for (int i = 0; i < COLUNAS; i++)
    {
        int numero = linha[i];
        if (numero < 1 || numero > 9)
            return 1; // Verifica se o número está fora do intervalo
        contador[numero]++;
        if (contador[numero] > 1)
            return 1;
    }
    return 0;
}

int colunas_repete(int sudoku[LINHAS][COLUNAS], int coluna)
{
    int contador[10] = {0};
    for (int i = 0; i < LINHAS; i++)
    {
        int numero = sudoku[i][coluna];
        if (numero < 1 || numero > 9)
            return 1;
        contador[numero]++;
        if (contador[numero] > 1)
            return 1;
    }
    return 0;
}

int subgrade_repete(int sudoku[LINHAS][COLUNAS], int inicioLinha, int inicioColuna)
{
    int contador[10] = {0};
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            int numero = sudoku[inicioLinha + i][inicioColuna + j];
            if (numero < 1 || numero > 9)
                return 1;
            contador[numero]++;
            if (contador[numero] > 1)
                return 1;
        }
    }
    return 0;
}

int main()
{
    int inst;
    scanf("%d", &inst);
    for (int jogos = 1; jogos <= inst; jogos++)
    {
        int sudoku[LINHAS][COLUNAS];
        for (int i = 0; i < LINHAS; i++)
        {
            for (int j = 0; j < COLUNAS; j++)
            {
                scanf("%d", &sudoku[i][j]);
            }
        }

        int contagem = 0;

        // Verificar as linhas
        for (int i = 0; i < LINHAS; i++)
        {
            if (linhas_repete(sudoku[i]))
                contagem++;
        }

        // Verificar as colunas
        for (int j = 0; j < COLUNAS; j++)
        {
            if (colunas_repete(sudoku, j))
                contagem++;
        }

        // Verificar as subgrades 3x3
        for (int i = 0; i < LINHAS; i += 3)
        {
            for (int j = 0; j < COLUNAS; j += 3)
            {
                if (subgrade_repete(sudoku, i, j))
                    contagem++;
            }
        }

        printf("Instancia %d\n", jogos);
        if (contagem > 0)
        {
            printf("NAO\n\n");
        }
        else
        {
            printf("SIM\n\n");
        }
    }
    return 0;
}
  
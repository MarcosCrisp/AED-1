#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um nó da árvore
typedef struct no
{
    char valor;
    struct no *esquerda;
    struct no *direita;
} No;

// Função para criar um novo nó
No *criar_no(char valor)
{
    No *novo = (No *)malloc(sizeof(No));
    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;
    return novo;
}

// Função para inserir um valor na árvore
No *inserir(No *raiz, char valor)
{
    if (raiz == NULL)
    {
        return criar_no(valor);
    }
    if (valor < raiz->valor)
    {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    }
    else if (valor > raiz->valor)
    {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

// Função para percurso infixo (esquerda, raiz, direita)
void infixa(No *raiz)
{
    if (raiz != NULL)
    {
        infixa(raiz->esquerda);
        printf("%c ", raiz->valor);
        infixa(raiz->direita);
    }
}

// Função para percurso prefixo (raiz, esquerda, direita)
void prefixa(No *raiz)
{
    if (raiz != NULL)
    {
        printf("%c ", raiz->valor);
        prefixa(raiz->esquerda);
        prefixa(raiz->direita);
    }
}

// Função para percurso posfixo (esquerda, direita, raiz)
void posfixa(No *raiz)
{
    if (raiz != NULL)
    {
        posfixa(raiz->esquerda);
        posfixa(raiz->direita);
        printf("%c ", raiz->valor);
    }
}

// Função para buscar um valor na árvore
int buscar(No *raiz, char valor)
{
    if (raiz == NULL)
    {
        return 0;
    }
    if (raiz->valor == valor)
    {
        return 1;
    }
    if (valor < raiz->valor)
    {
        return buscar(raiz->esquerda, valor);
    }
    else
    {
        return buscar(raiz->direita, valor);
    }
}

int main()
{
    No *raiz = NULL;
    char comando[10];
    char valor;

    while (scanf("%s", comando) != EOF)
    {
        if (strcmp(comando, "I") == 0)
        {
            scanf(" %c", &valor);
            raiz = inserir(raiz, valor);
        }
        else if (strcmp(comando, "INFIXA") == 0)
        {
            infixa(raiz);
            printf("\n");
        }
        else if (strcmp(comando, "PREFIXA") == 0)
        {
            prefixa(raiz);
            printf("\n");
        }
        else if (strcmp(comando, "POSFIXA") == 0)
        {
            posfixa(raiz);
            printf("\n");
        }
        else if (strcmp(comando, "P") == 0)
        {
            scanf(" %c", &valor);
            if (buscar(raiz, valor))
            {
                printf("%c existe\n", valor);
            }
            else
            {
                printf("%c nao existe\n", valor);
            }
        }
    }

    return 0;
}
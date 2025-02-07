/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1077
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct NoPilha
{
    char dado;
    struct NoPilha *abaixo;
};

struct Pilha
{
    int qtd;
    struct NoPilha *topo;
};

void empilhar(struct Pilha *p, char dado)
{
    p->qtd += 1;
    struct NoPilha *novoTopo = (struct NoPilha *)malloc(sizeof(struct NoPilha));

    novoTopo->dado = dado;
    novoTopo->abaixo = p->topo;
    p->topo = novoTopo;
}

void desempilhar(struct Pilha *p)
{
    if (p->qtd > 0)
    {
        p->qtd -= 1;
        struct NoPilha *antigoTopo = p->topo;
        p->topo = p->topo->abaixo;
        free(antigoTopo);
    }
}

char topo(struct Pilha *p)
{
    return p->topo->dado;
}

int tamanho(struct Pilha *p)
{
    return p->qtd;
}

int vazia(struct Pilha *p)
{
    return p->qtd == 0;
}

void inicializar(struct Pilha *p)
{
    p->qtd = 0;
    p->topo = NULL;
}

void destruir(struct Pilha *p)
{
    while (!vazia(p))
    {
        desempilhar(p);
    }
}

int prioridade(char operador)
{
    switch (operador)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

int main()
{
    int casos, tam;
    struct Pilha p;
    char expressao[301];

    scanf("%d\n", &casos);

    for (int k = 0; k < casos; ++k)
    {
        scanf("%s\n", expressao);

        inicializar(&p);

        tam = strlen(expressao);
        for (int i = 0; i < tam; ++i)
        {
            if (isalpha(expressao[i]) || isdigit(expressao[i]))
            {
                printf("%c", expressao[i]);
            }
            else if (expressao[i] == '(')
            {
                empilhar(&p, expressao[i]);
            }
            else if (expressao[i] == ')')
            {
                while (!vazia(&p) && topo(&p) != '(')
                {
                    printf("%c", topo(&p));
                    desempilhar(&p);
                }
                if (!vazia(&p))
                    desempilhar(&p);
            }
            else
            {
                while (!vazia(&p) && prioridade(expressao[i]) <= prioridade(topo(&p)))
                {
                    printf("%c", topo(&p));
                    desempilhar(&p);
                }
                empilhar(&p, expressao[i]);
            }
        }

        while (!vazia(&p))
        {
            printf("%c", topo(&p));
            desempilhar(&p);
        }
        printf("\n");
    }

    return 0;
}

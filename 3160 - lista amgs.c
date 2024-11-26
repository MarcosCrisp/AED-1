/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 3160
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct no
{
    char nome[20];
    struct no *prox;
};

struct no *criarno(char nome[])
{
    struct no *novo = (struct no *)malloc(sizeof(struct no));
    strcpy(novo->nome, nome);
    novo->prox = NULL;
    return novo;
}

void adicionarNoFinal(struct no **cabeca, char nome[])
{
    struct no *novo = criarno(nome);
    if (*cabeca == NULL)
    {
        *cabeca = novo;
    }
    else
    {
        struct no *temp = *cabeca;
        while (temp->prox != NULL)
        {
            temp = temp->prox;
        }
        temp->prox = novo;
    }
}

void buscar_inserir(struct no **cabeca, struct no *cabeca2, char amg[])
{
    struct no *anterior = NULL;
    struct no *p = *cabeca;

    while (p != NULL && strcmp(p->nome, amg) != 0)
    {
        anterior = p;
        p = p->prox;
    }
    if (p != NULL && cabeca2 != NULL)
    {
        if (anterior == NULL)
        {
            struct no *temp = cabeca2;
            while (temp->prox != NULL)
            {
                temp = temp->prox;
            }
            temp->prox = p;
            *cabeca = cabeca2;
        }
        else
        {
            struct no *temp = cabeca2;
            while (temp->prox != NULL)
            {
                temp = temp->prox;
            }
            temp->prox = p;
            anterior->prox = cabeca2;
        }
    }
}

void inserir_no_fim(struct no **cabeca, struct no *cabeca2)
{
    struct no *p = *cabeca;
    while (p->prox != NULL)
    {
        p = p->prox;
    }
    p->prox = cabeca2;
}

void exibirLista(struct no *cabeca)
{
    struct no *p = cabeca;
    while (p != NULL)
    {
        printf("%s", p->nome);
        if (p->prox != NULL)
        {
            printf(" ");
        }
        p = p->prox;
    }
    printf("\n");
}

int main()
{
    char lista[100];
    char amg[10];
    struct no *listaAmigos = NULL;
    struct no *listaNOVOSAmigos = NULL;

    fgets(lista, sizeof(lista), stdin);
    lista[strcspn(lista, "\n")] = '\0';
    char *nome = strtok(lista, " ");
    while (nome != NULL)
    {
        adicionarNoFinal(&listaAmigos, nome);
        nome = strtok(NULL, " ");
    }
    // utilizo novamente a variável lista, assim, aproveito a estrutua NO e o *criarno
    memset(lista, 0, sizeof(lista));
    fgets(lista, sizeof(lista), stdin);
    lista[strcspn(lista, "\n")] = '\0';
    char *novosnome = strtok(lista, " ");
    while (novosnome != NULL)
    {
        adicionarNoFinal(&listaNOVOSAmigos, novosnome);
        novosnome = strtok(NULL, " ");
    }

    // receber o nome do amigo indicado
    scanf("%s", amg);
    if (strcmp(amg, "nao") != 0)
    {
        buscar_inserir(&listaAmigos, listaNOVOSAmigos, amg);
    }
    else
    {
        inserir_no_fim(&listaAmigos, listaNOVOSAmigos);
    }
    exibirLista(listaAmigos);
    return 0;
}
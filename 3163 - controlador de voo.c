/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 3163
*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef char* TipoElemento;

struct EstruturaFila {
    TipoElemento* itens;
    int capacidade;
    int fim;
};

typedef struct EstruturaFila* TipoFila;

TipoFila criarFila(int capacidadeMax);
void destruirFila(TipoFila fila);
bool filaCheia(TipoFila fila);
bool filaVazia(TipoFila fila);
bool inserirNaFila(TipoFila fila, TipoElemento elemento);
bool removerDaFila(TipoFila fila, TipoElemento* elemento);

int main() {
    TipoFila direcaoLeste, direcaoOeste, direcaoSul, direcaoNorte, filaAvioes;
    TipoElemento aviao;
    
    direcaoLeste = criarFila(1000);
    direcaoOeste = criarFila(1000);
    direcaoSul = criarFila(1000);
    direcaoNorte = criarFila(1000);
    filaAvioes = criarFila(4000);
    
    int direcao;
    char identificacaoAviao[100];
    
    while (scanf("%d", &direcao) != EOF) {
        if (direcao == 0) {
            break;
        }
        
        scanf("%s", identificacaoAviao);
        aviao = identificacaoAviao;
        
        switch (direcao) {
            case -4:
                inserirNaFila(direcaoLeste, aviao);
                break;
            case -3:
                inserirNaFila(direcaoNorte, aviao);
                break;
            case -2:
                inserirNaFila(direcaoSul, aviao);
                break;
            case -1:
                inserirNaFila(direcaoOeste, aviao);
                break;
            default:
                break;
        }
    }
    
    while (!filaVazia(direcaoLeste) || !filaVazia(direcaoNorte) || !filaVazia(direcaoSul) || !filaVazia(direcaoOeste)) {
        if (!filaVazia(direcaoOeste)) {
            removerDaFila(direcaoOeste, &aviao);
            inserirNaFila(filaAvioes, aviao);
        }
        if (!filaVazia(direcaoNorte)) {
            removerDaFila(direcaoNorte, &aviao);
            inserirNaFila(filaAvioes, aviao);
        }
        if (!filaVazia(direcaoSul)) {
            removerDaFila(direcaoSul, &aviao);
            inserirNaFila(filaAvioes, aviao);
        }
        if (!filaVazia(direcaoLeste)) {
            removerDaFila(direcaoLeste, &aviao);
            inserirNaFila(filaAvioes, aviao);
        }
    }

    while (!filaVazia(filaAvioes)) {
        removerDaFila(filaAvioes, &aviao);
        printf("%s", aviao);
        if (!filaVazia(filaAvioes)) {
            printf(" ");
        } else {
            printf("\n");
        }
    }

    destruirFila(direcaoLeste);
    destruirFila(direcaoOeste);
    destruirFila(direcaoSul);
    destruirFila(direcaoNorte);
    destruirFila(filaAvioes);
    
    return 0;
}

TipoFila criarFila(int capacidadeMax) {
    if (capacidadeMax < 1) {
        return NULL;
    }

    TipoFila fila = malloc(sizeof(struct EstruturaFila));
    if (fila != NULL) {
        fila->fim = -1;
        fila->capacidade = capacidadeMax;
        fila->itens = malloc(sizeof(TipoElemento) * fila->capacidade);
        if (fila->itens == NULL) {
            free(fila);
            fila = NULL;
        }
    }

    return fila;
}

void destruirFila(TipoFila fila) {
    for (int i = 0; i <= fila->fim; i++) {
        free(fila->itens[i]);
    }
    free(fila->itens);
    free(fila);
}

bool filaCheia(TipoFila fila) {
    return fila != NULL && fila->fim == fila->capacidade - 1;
}

bool filaVazia(TipoFila fila) {
    return fila != NULL && fila->fim == -1;
}

bool inserirNaFila(TipoFila fila, TipoElemento elemento) {
    if (fila == NULL || filaCheia(fila)) {
        return false;
    }

    fila->fim += 1;
    fila->itens[fila->fim] = malloc(strlen(elemento) + 1);
    if (fila->itens[fila->fim] == NULL) {
        return false;
    }
    strcpy(fila->itens[fila->fim], elemento);
    return true;
}

bool removerDaFila(TipoFila fila, TipoElemento* elemento) {
    if (fila == NULL || filaVazia(fila)) {
        return false;
    }

    *elemento = fila->itens[0];

    for (int i = 0; i < fila->fim; i++) {
        fila->itens[i] = fila->itens[i + 1];
    }
    fila->fim -= 1;

    return true;
}

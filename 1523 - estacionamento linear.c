/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1523
*/

#include <stdio.h>
#include <stdlib.h>
#define TAM_MAX 10000

typedef struct stack {
    int topo;
    int entrada[TAM_MAX];
    int saida[TAM_MAX];
} Stack;

Stack* criar_stack();
void liberar_stack(Stack* s);
int stack_vazia(Stack* s);
int stack_cheia(Stack* s, int capacidade);
int push(Stack* s, int entrada, int saida, int capacidade);
int pop(Stack* s);

int main(){
    int capacidade, num_elementos, entrada, saida;
    int i;
    while(1){
        scanf("%d %d", &num_elementos, &capacidade);
        if(capacidade == 0 && num_elementos == 0) break;
        Stack* s = criar_stack();
        int valido = 1;
        for(i = 0; i < num_elementos; i++){
            scanf("%d %d", &entrada, &saida);
            if(valido){
                if(stack_vazia(s)){
                    push(s, entrada, saida, capacidade);
                    valido = 1;
                } else {
                    while(entrada >= s->saida[s->topo-1]){
                        pop(s);
                        if(stack_vazia(s)) break;
                    }
                    if(stack_cheia(s, capacidade)){
                        valido = 0;
                    } else {
                        push(s, entrada, saida, capacidade);
                        if(s->topo > 1){
                            if(s->entrada[s->topo-1] > s->entrada[s->topo-2] && s->saida[s->topo-1] < s->saida[s->topo-2]){
                                valido = 1;
                            }else{
                                valido = 0;
                            }
                        } else {
                            valido = 1;
                        }
                    }
                }
            }
        }
        if(valido) printf("Sim\n");
        else printf("Nao\n");
        liberar_stack(s);
    }
}

Stack* criar_stack(){
    Stack* s = (Stack*) malloc(sizeof(Stack));
    s->topo = 0;
    return s;
}

void liberar_stack(Stack* s){
    free(s);
}

int stack_vazia(Stack* s){
    if (s->topo == 0) return 1;
    else return 0;
}

int stack_cheia(Stack* s, int capacidade){
    if (s->topo == capacidade) return 1;
    else return 0;
}

int push(Stack* s, int entrada, int saida, int capacidade){
    if (!stack_cheia(s, capacidade)){
        s->entrada[s->topo] = entrada;
        s->saida[s->topo] = saida;
        s->topo++;
        return 1;
    } else {
        return 0;
    }
}

int pop(Stack* s){
    if(!stack_vazia(s)){
        s->topo--;
        return 1;
    } else {
        return 0;
    }
}
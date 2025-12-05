/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1548
*/

#include <stdio.h>
#include <stdlib.h>

int comparacao(const void *a, const void *b){
    return *(int *)b - *(int *)a;
}

int main(){
    int caso, M, Resp;
    int original[1000], organizado[1000];

    scanf("%d", &caso);

    for(int k = 0; k < caso; k++){ 
        scanf("%d", &M);

        for(int i = 0; i < M; i++){
            scanf("%d", &original[i]);
            organizado[i] = original[i];
        }

        qsort(organizado, M, sizeof(int), comparacao);
        Resp = 0;
        for(int i = 0; i < M; i++){
            if(original[i] == organizado[i])
                Resp++;
        }

        printf("%d\n", Resp);
    } 

    return 0;
}
/*
Autor: Marcos Paulo Crisp Modesto
RA: 178.190
exercício: 1076
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define true 1  
#define false 0 
#define MAXSIZE 110 

int lido[MAXSIZE]; 
char adj[MAXSIZE][MAXSIZE]; 

int x, ans; 

void dfs(int);

int main(int argc, char **argv) {
    int n, y;
    int q, u, v, i;

    scanf("%d", &n);

    while (n--) {
        scanf("%d", &q);
        scanf("%d %d", &x, &y);

        memset(lido, 0, sizeof(lido)); 
        memset(adj, 0, sizeof(adj));

        for (i = 0; i < y; ++i) {
            scanf("%d %d", &u, &v);
            adj[u][v] = adj[v][u] = true; 
        }

        ans = 0;

        dfs(q);

        printf("%d\n", ans << 1); 
    }

    return 0;
}


void dfs(int u) {
    int i;
    lido[u] = true; 

    for (i = 0; i < x; ++i) {
        if (adj[u][i]) { 
            if (!lido[i]) { 
                dfs(i); 
                ans++;
            }
        }
    }
}
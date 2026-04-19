#include <stdio.h>
#define MAX 10

int visited[MAX];

void dfs(int graph[MAX][MAX], int n, int node) {
    printf("%d ", node);
    visited[node] = 1;

    for (int i = 0; i < n; i++) {
        if (graph[node][i] && !visited[i]) {
            dfs(graph, n, i);
        }
    }
}

int main() {
    int n = 4;
    int graph[MAX][MAX] = {
        {0,1,1,0},
        {1,0,0,1},
        {1,0,0,1},
        {0,1,1,0}
    };

    printf("DFS Traversal: ");
    dfs(graph, n, 0);

    return 0;
}
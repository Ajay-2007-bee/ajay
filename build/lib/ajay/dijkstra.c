#include <stdio.h>
#define MAX 10
#define INF 9999

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int dist[MAX], visited[MAX] = {0};

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
    }

    dist[start] = 0;

    for (int count = 0; count < n - 1; count++) {
        int min = INF, u;

        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] <= min) {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("Vertex\tDistance\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

int main() {
    int n = 4;
    int graph[MAX][MAX] = {
        {0, 1, 4, 0},
        {1, 0, 2, 5},
        {4, 2, 0, 1},
        {0, 5, 1, 0}
    };

    dijkstra(graph, n, 0);
    return 0;
}
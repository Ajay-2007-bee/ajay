#include <stdio.h>
#define MAX 10
#define INF 9999

void prim(int graph[MAX][MAX], int n) {
    int selected[MAX] = {0};
    selected[0] = 1;

    int edges = 0;

    printf("Edge\tWeight\n");

    while (edges < n - 1) {
        int min = INF, x = 0, y = 0;

        for (int i = 0; i < n; i++) {
            if (selected[i]) {
                for (int j = 0; j < n; j++) {
                    if (!selected[j] && graph[i][j]) {
                        if (graph[i][j] < min) {
                            min = graph[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d\t%d\n", x, y, graph[x][y]);
        selected[y] = 1;
        edges++;
    }
}

int main() {
    int n = 4;
    int graph[MAX][MAX] = {
        {0, 2, 3, 0},
        {2, 0, 1, 4},
        {3, 1, 0, 5},
        {0, 4, 5, 0}
    };

    prim(graph, n);
    return 0;
}
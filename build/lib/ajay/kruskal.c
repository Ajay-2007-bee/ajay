#include <stdio.h>
#define MAX 10

int parent[MAX];

int find(int i) {
    while (parent[i] != i)
        i = parent[i];
    return i;
}

void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int edges[][3], int n, int e) {
    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("Edge\tWeight\n");

    for (int i = 0; i < e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];

        if (find(u) != find(v)) {
            printf("%d - %d\t%d\n", u, v, w);
            union_set(u, v);
        }
    }
}

int main() {
    int edges[][3] = {
        {0, 1, 2},
        {1, 2, 1},
        {0, 2, 3},
        {1, 3, 4}
    };

    kruskal(edges, 4, 4);
    return 0;
}
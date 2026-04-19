def prim(graph):
    start = list(graph.keys())[0]
    visited = [start]
    edges = []

    while len(visited) < len(graph):
        min_edge = (None, None, float('inf'))

        for u in visited:
            for v, w in graph[u].items():
                if v not in visited and w < min_edge[2]:
                    min_edge = (u, v, w)

        edges.append(min_edge)
        visited.append(min_edge[1])

    return edges


# Example
if __name__ == "__main__":
    graph = {
        'A': {'B': 2, 'C': 3},
        'B': {'A': 2, 'C': 1, 'D': 4},
        'C': {'A': 3, 'B': 1, 'D': 5},
        'D': {'B': 4, 'C': 5}
    }

    print(prim(graph))
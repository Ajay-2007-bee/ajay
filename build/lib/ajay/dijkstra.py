def dijkstra(graph, start):
    dist = {node: float('inf') for node in graph}
    dist[start] = 0
    visited = set()

    while len(visited) < len(graph):
        # get minimum distance node
        u = min((node for node in graph if node not in visited),
                key=lambda node: dist[node])

        visited.add(u)

        for v, w in graph[u].items():
            if dist[u] + w < dist[v]:
                dist[v] = dist[u] + w

    return dist


# Example usage
if __name__ == "__main__":
    graph = {
        'A': {'B': 1, 'C': 4},
        'B': {'C': 2, 'D': 5},
        'C': {'D': 1},
        'D': {}
    }

    print(dijkstra(graph, 'A'))
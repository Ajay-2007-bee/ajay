def kruskal(vertices, edges):
    parent = {v: v for v in vertices}

    def find(v):
        while parent[v] != v:
            v = parent[v]
        return v

    mst = []
    edges.sort(key=lambda x: x[2])

    for u, v, w in edges:
        pu, pv = find(u), find(v)
        if pu != pv:
            mst.append((u, v, w))
            parent[pu] = pv

    return mst


# Example
if __name__ == "__main__":
    vertices = ['A', 'B', 'C', 'D']
    edges = [
        ('A', 'B', 2),
        ('A', 'C', 3),
        ('B', 'C', 1),
        ('B', 'D', 4),
        ('C', 'D', 5)
    ]

    print(kruskal(vertices, edges))
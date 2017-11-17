from sys import maxsize
from scipy.sparse import dok_matrix, find, spmatrix
import heapq, numpy as np

def edges(e):
    return zip(*e.nonzero())

def dijkstras(e, s, t = None):
    queue, prev, dist = [], {s: None}, {}
    heapq.heappush(queue, (0, s))

    found = False
    while len(queue) and not found:
        d, i = heapq.heappop(queue)
        for j in e[i].nonzero()[0]:
            if j not in prev:
                prev[j] = i
                dist[j] = e[i][j] + d
                if t is not None and j == t:
                    found = True; break

                heapq.heappush(queue, (e[i][j] + d, j))

    return prev, dist

def dijkstras_dist(e, s):
    prev, dist = dijkstras(e, s)
    return dist

def dijkstras_path(e, s, t):
    prev, dist = dijkstras(e, s, t)
    if t not in prev:
        return None
    else:
        path = []
        while prev[t] is not None:
            path.append((prev[t], t))
            t = prev[t]

        return list(reversed(path))

def reachable(e, s):
    queue, visited = [s], set()
    while len(queue):
        i = queue.pop()
        visited.add(i)
        queue.extend(j for i, j in edges(e) if j not in visited)

    return visited

def hellman_ford(c, s, t):
    for i, j in edges(c):
        if c[j, i] > 0:
            raise Exception("No double edges currently")

    f = np.zeros(c.shape)
    a = np.zeros(c.shape)

    while True:
        for i, j in edges(e):
            if f[i, j] > 0:
                a[j, i] = c[i, j]
            if f[i, j] < c[i, j]:
                a[i, j] = c[i, j]

        path = dijkstras_path(a, s, t)

        if path is None:
            return np.sum(f, axis = 0), reachable(f, s)
        else:
            alpha = min(max(f[j, i], c[i, j] - f[i, j]) for i, j in path)

            for i, j in path:
                if f[j, i]: f[j, i] -= alpha
                else:       f[i, j] += alpha

        a.fill(0)

def fromAdjacencyList(adj_list, directed = True):
    x = zip(*adj_list)
    vertices = list(set(next(x)) | set(next(x)))

    edges = np.zeros((len(vertices), len(vertices)))

    for (s, d), w in adj_list:
        s = vertices.index(s)
        d = vertices.index(d)

        edges[s, d] = w
        if not directed:
            edges[d, s] = w

    return vertices, edges

# CPP Program of Prim's algorithm for MST


inf = 65000


# To add an edge

def addEdge(adj, u, v, wt):
    adj[u].append([v, wt])
    adj[v].append([u, wt])


def primMST(adj, V):
    # Create a priority queue to store vertices that
    # are being preinMST.
    pq = []

    src = 0  # Taking vertex 0 as source

    # Create a vector for keys and initialize all keys as infinite (INF)
    key = [inf for i in range(V)]

    # To store parent array which in turn store MST
    parent = [-1 for i in range(V)]

    # To keep track of vertices included in MST
    inMST = [False for i in range(V)]

    # Insert source itself in priority queue and initialize its key as 0.
    pq.append([0, src])
    key[src] = 0

    # Looping till priority queue becomes empty
    while len(pq) != 0:
        # The first vertex in pair is the minimum key
        # vertex, extract it from priority queue.
        # vertex label is stored in second of pair (it
        # has to be done this way to keep the vertices
        # sorted key (key must be first item
        # in pair)

        u = pq[0][1]
        del pq[0]

        # Different key values for same vertex may exist in the priority queue.
        # The one with the least key value is always processed first.
        # Therefore, ignore the rest.
        if inMST[u] == True:
            continue

        inMST[u] = True  # Include vertex in MST

        # Traverse all adjacent of u
        for x in adj[u]:
            # Get vertex label and weight of current adjacent of u.
            v = x[0]
            weight = x[1]

            # If v is not in MST and weight of (u,v) is smaller
            # than current key of v
            if inMST[v] == False and key[v] > weight:
                # Updating key of v
                key[v] = weight
                pq.append([key[v], v])
                pq.sort()
                parent[v] = u

    for i in range(1, V):
        print(parent[i], "-", i)


# Driver code
V = 9
adj = [[] for i in range(V)]
addEdge(adj, 0, 1, 4)
addEdge(adj, 0, 7, 8)
addEdge(adj, 1, 2, 8)
addEdge(adj, 1, 7, 11)
addEdge(adj, 2, 3, 7)
addEdge(adj, 2, 8, 2)
addEdge(adj, 2, 5, 4)
addEdge(adj, 3, 4, 9)
addEdge(adj, 3, 5, 14)
addEdge(adj, 4, 5, 10)
addEdge(adj, 5, 6, 2)
addEdge(adj, 6, 7, 1)
addEdge(adj, 6, 8, 6)
addEdge(adj, 7, 8, 7)

print("Edges of MST are")
primMST(adj, V)

# Output:
# Edges of MST are
# 0 - 1
# 1 - 2
# 2 - 3
# 3 - 4
# 2 - 5
# 5 - 6
# 6 - 7
# 2 - 8

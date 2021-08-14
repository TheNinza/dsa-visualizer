# C++ program for Kruskal's algorithm to find Minimum
# Spanning Tree of a given connected, undirected and
# weighted graph


# Utility for Disjoint set

# Find the parent of a node 'u'
# Path Compression
def ds_find(u):
    # Make the parent of the nodes in the path
    # from u--> parent[u] point to parent[u]
    if u != parent[u]:
        parent[u] = ds_find(parent[u])
    return parent[u]


# Union by rank

def ds_merge(x, y):
    x = ds_find(x)
    y = ds_find(y)

    # Make tree with smaller height
    # a subtree of the other tree
    if rnk[x] > rnk[y]:
        parent[y] = x
    else:
        parent[x] = y

    if rnk[x] == rnk[y]:
        rnk[y] += 1


def addEdge(edges, u, v, wt):
    edges.append([wt, u, v])


def kruskalMST():
    mst_wt = 0  # initialize result

    global edges
    # sort the edges in increasing order of cost
    edges.sort()

    # interate through all sorted edges
    for i in range(len(edges)):
        u = edges[i][1]
        v = edges[i][2]

        set_u = ds_find(u)
        set_v = ds_find(v)

        # Check if the selected edge is creating
        # a cycle or not (Cycle is created if u
        # and v belong to same set)
        if set_u != set_v:
            # Current edge will be in the MST
            # so print it
            print(u, "-", v)

            # Update MST weight
            mst_wt += edges[i][0]

            # Merge two sets
            ds_merge(set_u, set_v)
    return mst_wt


# Driver code
V = 9


# Initially, all vertices are in
# different sets and have rank 0.
rnk = [0 for i in range(V+1)]
parent = [i for i in range(V+1)]  # as every element is a parent of itself

edges = []
addEdge(edges, 0, 1, 4)
addEdge(edges, 0, 7, 8)
addEdge(edges, 1, 2, 8)
addEdge(edges, 1, 7, 11)
addEdge(edges, 2, 3, 7)
addEdge(edges, 2, 8, 2)
addEdge(edges, 2, 5, 4)
addEdge(edges, 3, 4, 9)
addEdge(edges, 3, 5, 14)
addEdge(edges, 4, 5, 10)
addEdge(edges, 5, 6, 2)
addEdge(edges, 6, 7, 1)
addEdge(edges, 6, 8, 6)
addEdge(edges, 7, 8, 7)

print("Edges of MST are ")
mst_wt = kruskalMST()
print("Weight of MST is ", mst_wt)

# Output:
# Edges of MST are
# 6 - 7
# 2 - 8
# 5 - 6
# 0 - 1
# 2 - 5
# 2 - 3
# 0 - 7
# 3 - 4
# Weight of MST is  37

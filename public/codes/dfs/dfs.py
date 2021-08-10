# Python3 program to implement DFS

# This function adds an edge to the graph.
# It is an undirected graph. So edges
# are added for both the nodes.

def addEdge(g, u, v):
    g[u].append(v)
    g[v].append(u)

# This function does the Depth First Search


def DFS_Visit(g, s):

    # Colour is gray as it is visited partially now
    colour[s] = "gray"
    global time
    time += 1
    d[s] = time
    print(s, end=" ")

    # This loop traverses all the child nodes of u
    i = 0
    while i < len(g[s]):

        # If the colour is white then
        # the said node is not traversed.
        if (colour[g[s][i]] == "white"):

            p[g[s][i]] = s

            # Exploring deeper
            DFS_Visit(g, g[s][i])
        i += 1

    time += 1
    f[s] = time
    # Now the node u is completely traversed
    # and colour is changed to black.
    colour[s] = "black"


def DFS(g, n):

    # Initially all nodes are not traversed.
    # Therefore, the colour is white.

    # global because the variables in the parent scope needs to be used here
    global colour, p, d, f, time
    colour = ["white"] * n
    p = [-1] * n
    d = [0] * n
    f = [0] * n
    time = 0
    # Calling DFS_Visit() for all
    # white vertices
    print("DFS Order is : ", end="")
    for i in range(n):
        if (colour[i] == "white"):
            DFS_Visit(g, i)

# Driver Code


# Graph with 11 nodes and 11 edges.
n = 11

# Declaring the vectors to store color,predecessor,
# and time stamps d and f
colour = [None] * n
p = [None] * n
d = [None] * n
f = [None] * n
time = 0

# The Graph vector
g = [[] for i in range(n)]

addEdge(g, 0, 1)
addEdge(g, 1, 2)
addEdge(g, 2, 3)
addEdge(g, 1, 4)
addEdge(g, 4, 5)
addEdge(g, 4, 6)
addEdge(g, 4, 7)
addEdge(g, 6, 9)
addEdge(g, 7, 8)
addEdge(g, 7, 9)
addEdge(g, 8, 10)

DFS(g, n)

# Output:
# DFS Order is : 0 1 2 3 4 5 6 9 7 8 10

# Python3 program to implement BFS
import queue

# This function adds an edge to the graph.
# It is an undirected graph. So edges
# are added for both the nodes.


def addEdge(g, u, v):
    g[u].append(v)
    g[v].append(u)


# This function does the Breadth
# First Search
def BFSSingleSource(g, s):

    # The Queue used for the BFS operation
    q = queue.Queue()

    # Pushing the root node inside
    # the queue
    q.put(s)

    # Distance of root node is 0 & colour is
    # gray as it is visited partially now
    d[s] = 0
    colour[s] = "gray"

    # Loop to traverse the graph. Traversal
    # will happen traverse until the queue
    # is not empty.
    while (not q.empty()):

        # Extracting the front element(node)
        # and poping it out of queue.
        u = q.get()

        print(u, end=" ")

        # This loop traverses all the child
        # nodes of u
        i = 0
        while i < len(g[u]):

            # If the colour is white then
            # the said node is not traversed.
            if (colour[g[u][i]] == "white"):
                colour[g[u][i]] = "gray"
                d[g[u][i]] = d[u] + 1
                p[g[u][i]] = u

                # Pushing the node inside queue
                # to traverse its children.
                q.put(g[u][i])
            i += 1

        # Now the node u is completely traversed
        # and colour is changed to black.
        colour[u] = "black"


def BFSFull(g, n):

    # Initially all nodes are not traversed.
    # Therefore, the colour is white.

    # global because the variables in the parent scope needs to be used here
    global colour, d, p
    colour = ["white"] * n
    d = [0] * n
    p = [-1] * n

    # Calling BFSSingleSource() for all
    # white vertices
    print("BFS Order is : ", end="")
    for i in range(n):
        if (colour[i] == "white"):
            BFSSingleSource(g, i)

# Driver Code


# Graph with 11 nodes and 11 edges.
n = 11

# Declaring the vectors to store color,
# distance and parent
colour = [None] * n
d = [None] * n
p = [None] * n

# The Graph vector
g = [[] for i in range(n)]  # initialises list g with n empty lists

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

BFSFull(g, n)

# Output:
# BFS Order is : 0 1 2 4 3 5 6 7 9 8 10

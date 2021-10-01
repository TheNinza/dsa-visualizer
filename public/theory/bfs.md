# What is Breadth First Search?

Breadth first search is one of the basic and essential searching
algorithms on graphs.
As a result of how the algorithm works, the path found by breadth
first search to any node is the shortest path to that node, i.e the
path that contains the smallest number of edges in unweighted graphs.
Breadth-first search explores the nodes of a graph in increasing
distance away from some starting vertex s.
It decomposes the component into layers Li such that the shortest path
from s to each of nodes in Li is of length i.

1. L0 is the set {s}.
2. Given layers L0, L1, . . . , Lj
   , then Lj+1 is the set of nodes that
   are not in a previous layer and that have an edge to some
   node in layer Lj

   Lets assume,there is a given graph G=(V,E) and a source vector S, BFS
   explore the edges of G to discover every vertex that is reachable from
   s.
   Now, it is called BFS because it discovers all vertices at distance k
   from s before discovering any vertices at distance (k+1)
   It produces a breadth-first tree rooted at s.The path is thbreadthfirst tree from s to v corresponds to a shortest path from s tv in
   G.

## Description of the algorithm

The algorithm maintains following data structures :

- color[u]-stores color of each vertex is u∈V.
- π[u]-stores predecessor of u
- d[u]-stores distance of vertex u from source s
- Q-a queue to manage the set of gray vertices

,

```python
BFS(G,s)
while Q≠ϕ
  u<-head[Q]
  for each v∈adj[u]
    if color[v]=white
      color[v]<-gray
      d[v]<-d[u]+1
      π[u]<-u
 Enqueue(Q,v)
 Dequeue(Q)
 color[u]<-black
```

## Time complexity

The time complexity of BFS is O(V + E).
If graph is represented as adjacency list
V=vertices
E= edges
The time complexity of BFS is O(V²).if graph is represented as
adjacency matrix

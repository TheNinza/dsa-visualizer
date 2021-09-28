# What is Depth First Search?

In depth-first search the idea is to travel as deep as possible from neighbor to neighbor before backtracking.

What determines how deep is possible is that you must follow edges, and you don't visit any vertex twice.

In DFS, the search is deeper in the graph whenever possible,i.e., edges are explored out of the most recently discovered vertex v that still has unexplored edges leaving it. When all of v's edges have been explored, the search backtracks to explore edges leaving the vertex from which v was discovered.

If any undirected vertices remain then one of them is selected as a new source and the search is repeated from that source. It is repeated all vertices are discovered. It means,DFS forms depth first forest composed of several depth-first trees(The trees are disjoint).

The discovery and finishing times have parenthesis structure .For any 2 vertices u and v of G the following holds:

(i) the intervals [d[u],f[u]] and [d[v],f[v]] are entirely disjoint.

(ii)the interval [d[u],f[u]]is contained entirely within the interval [d[v],f[v]] and u is descendant of v.

(iii)the interval [d[v,f[v]] is contained entirely within the interval [d[u],f[u]], and v is descendant of u.

In a depth first forest of graph G=(V,E),vertex v is a descendant of vertex u if and only if at the time d[u] that the search discovers u,vertex v can be reached from is along a path consisting entirely of white vertices.

DFS can be used to classify the edges of the input graph G=(V,E):

(i) Tree edges-edges in the depth-first forest(Gn)

(ii)Back edges-edges(u,v) connecting a vertex is to an ancestor v in a depth-first tree.Self-loops are considered as back edges.

(iii)Forward edges-nontree edges (u,v) connecting a vertex is to a descendant v

(iv)Cross edges-all other edges.

Forward and cross edges never occur in a DFS of an undirected graph .Every edge sis either a tree edge or a back edge.

## Description of the algorithm

Initially,each vertex is white. It is grayed when it is discovered in the search and is blackened when it is finished, that is when its adjacency list is completely examined.

The algorithm also timestamps each vertex.Each vertex v has 2 timestamps:

     d[v]-when v is discovered(grayed) and f[v]-when search finishes examining its adjacency list (v is blackened).

These time stamps are integers between 1 and 2|v| and for every vertex u,

        d[u]<f[u]

```python
DFS(G)
    for each vertex u∈V[G]
            color[u]<-white
            π[u]<-NIL
        time<-0
     for each vertex u∈V[G]
        if color[u]=white
            then DFS_Visit(u)

DFS_Visit(u)
    color[u]<-gray
    d[u]<-time<-time+1
    for each vertex v∈adj[u]
        if color[v]=white
            π[v]<-u
            DFS_Visit(v)
        color[u]<-black
        f[u]<-time<-time+1
```

## Time complexity

The time complexity of DFS is O(V + E).if graph is represented as adjacency list
V=vertices
E= edges

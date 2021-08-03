# Depth First Search
In depth-first search the idea is to travel as deep as possible from neighbour to neighbour before backtracking. 

What determines how deep is possible is that you must follow edges, and you don't visit any vertex twice.

In DFS, the search is deeper in the graph whenever possible,i.e., edges are explored out of the most recently discovered vertex v that still has unexplored edges leaving it. When all of v's edges have been explored, the search backtracks to explore edges leaving the vertex from which v was discovered.

If any undirected vertices remain then one of them is selected as a new source and the search is repeated from that source. It is repeated all vertices are discovered. It means,DFS forms depth first forest composed of several depth-first trees(The trees are disjoint).

The discovery and finishing times have parenthesis structure .For any 2 vertices u and v of G the following holds:
(i) the intervals [d[u],f[u]] and [d[v],f[v]] are entirely disjoint.
(ii)the interval [d[u],f[u]]is contained entirely within the interval [d[v],f[v]] and u is descendant of v.
(iii)the interval [d[v,f[v]] is contained entirely within the interval [d[u],f[u]], and v is decendant of u.

In a depth first forest of graph G=(V,E),vertex v is a descendant of vertex u if and only if at the time d[u] that the search discovers u,vertex v can be reached from is along a path consisting entirely of white vertices.

DFS can be used to classify the edges of the input graph G=(V,E):
(i) Tree edges-edges in the depth-first forest(Gn)
(ii)Back edges-edges(u,v) connecting a vertex is to an ancestor v in a depth-first tree.Self-loops are considered as back edges.
(iii)Forward edges-nontree edges (u,v) connecting a vertex is to a descendant v
(iv)Cross edges-all other edges.

Forward and cross edges never occur in a DFS of an undirected graph .Every edge sis either a tree edge or a back edge.

### Description of the algorithm
Initially,each vertex is white. It is grayed when it is discovered in the search and is blackened when it is finished, that is when its adjacency list is completely examined.

The algorithm also timestamps each vertex.Each vertex v has 2 timestamps:
&emsp; d[v]-when v is discovered(grayed) and f[v]-when search finishes examining its adjacency list (v is blackened).
These time stamps are intergers between 1 and 2|v| and for every vertex u,
&emsp;&emsp;d[u]<f[u]

> DFS(G)
&emsp; for each vertex u∈V[G]
&emsp;&emsp;  &emsp; color[u]<-white
&emsp;&emsp;  &emsp;  π[u]<-NIL
&emsp;&emsp;  time<-0
&emsp;  for each vertex u∈V[G]
&emsp;&emsp; if color[u]=white
&emsp;&emsp;   &emsp;then DFS_Visit(u)

>	DFS_Visit(u)
&emsp;color[u]<-gray
&emsp;d[u]<-time<-time+1
&emsp;for each vertex v∈adj[u]
&emsp;&emsp;if color[v]=white
&emsp;&emsp;&emsp;π[v]<-u
&emsp;&emsp;&emsp;DFS_Visit(v)
&emsp;&emsp;color[u]<-black
&emsp;&emsp;f[u]<-time<-time+1

### Time complexity
The time complexity of DFS is O(V + E).if graph is represented as adjacency list
V=vertices
E= edges	




# What is Prim’s Algorithm

Prim’s Algorithm is a famous greedy algorithm.
It is used for finding the Minimum Spanning Tree (MST) of a given graph.
To apply Prim’s algorithm, the given graph must be weighted, connected and undirected.
Prim's algorithm is a classic greedy algorithm for finding the MST of a graph.
The general algorithm is :-

- Create an empty tree M, which will act as a MST.

- Choose a random vertex v, from the graph.

- Add the edges that are connected to v into some data structure E.

- Find the edge in E with the minimum weight, and add this edge to M.

- Now,make v equal to the other vertex in the edge and repeat from step 3.

## Description of the algorithm

- Step-01: Randomly choose any vertex.

  The vertex connecting to the edge having least weight is usually selected.

- Step-02:Find all the edges that connect the tree to new vertices.

  Find the least weight edge among those edges and include it in the existing tree.

  If including that edge creates a cycle, then reject that edge and look for the next least weight edge.

- Step-03:Keep repeating step-02 until all the vertices are included and Minimum Spanning Tree (MST) is obtained.

```python
The pseudocode for prim's algorithm shows how we create two sets of vertices U and V-U.
U contains the list of vertices that have been visited and V-U the list of vertices that haven't.
One by one, we move vertices from set V-U to set U by connecting the least weight edge.
T = ∅;
U = { 1 };
while (U ≠ V)
    let (u, v) be the lowest cost edge such that u ∈ U and v ∈ V - U;
    T = T ∪ {(u, v)}
    U = U ∪ {v}

```

## Time complexity:

Time complexity of prism algorithm

= O(E + V) x O(logV)

= O((E + V)logV)

= O(ElogV)

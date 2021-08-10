# What is Krushkal Algorithm:?

Kruskal’s algorithm is the concept that is introduced in the graph theory of discrete mathematics. It is used to discover the shortest path between two points in a connected weighted graph. This algorithm converts a given graph into the forest, considering each node as a separate tree. These trees can only link to each other if the edge connecting them has a low value and doesn’t generate a cycle in MST structure.

Creating Minimum Spanning Tree using Kruskal Algorithm

You will first look into the steps involved in Kruskal’s Algorithm to generate a minimum spanning tree:

Step 1: Sort all edges in increasing order of their edge weights.

Step 2: Pick the smallest edge.

Step 3: Check if the new edge creates a cycle or loop in a spanning tree.

Step 4: If it doesn’t form the cycle, then include that edge in MST. Otherwise, discard it.

Step 5: Repeat from step 2 until it includes |V| - 1 edges in MST.

## Description of the algorithm

Any MST algorithm revolves around determining whether adding an edge would result in a loop or not. Union Find is the most popular algorithm for determining this. The Union-Find algorithm separates vertices into clusters, allowing you to determine whether two vertices belong to the same cluster and hence if adding an edge will produce a cycle.

The strategy to implement the Kruskal algorithm using Union-Find is given below:

Construct a structure to keep track of the source and destination nodes, as well as their weight.

Sort all the edges of a graph according to their edge-weight values.

Create three distinct sets to maintain nodes of a graph, their hierarchy in a tree, and corresponding ranks for every node.

Primarily, initialize all rank values to 0 and parent values to -1 (representing each node as its own tree itself).

For each insertion of an edge in MST, you will update the rank and parent of each node.

Do not insert the edge connecting two nodes if they have the same parent node, as this will cause a cycle in the tree structure.

```python
algorithm Kruskal(G) is
    F:= ∅
    for each v ∈ G.V do
        MAKE-SET(v)
    for each (u, v) in G.E ordered by weight(u, v), increasing do
        if FIND-SET(u) ≠ FIND-SET(v) then
            F:= F ∪ {(u, v)} ∪ {(v, u)}
            UNION(FIND-SET(u), FIND-SET(v))
    return F
```

## Time Complexity

Time complexity of kruskal complexity : O(ElogE)

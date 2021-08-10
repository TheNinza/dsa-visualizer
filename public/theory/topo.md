# What is Topological Sort?

The topological sort algorithm takes a directed graph and returns an array of the nodes where each node appears before all the nodes it points to.

## Description of the algorithm

We'll use the strategy we outlined above:

- Identify a node with no incoming edges.

- Add that node to the ordering.

- Remove it from the graph.

- Repeat.

  We'll keep looping until there aren't any more nodes with indegree zero. This could happen for two reasons:

  There are no nodes left. We've taken all of them out of the graph and added them to the topological ordering.

  There are some nodes left, but they all have incoming edges. This means the graph has a cycle, and no topological ordering exists.

  One small tweak. Instead of actually removing the nodes from the graph (and destroying our input!), we'll use a hash map to track each node's indegree. When we add a node to the topological ordering, we'll decrement the indegree of that node's neighbors, representing that those nodes have one fewer incoming edges.

```python
T = []
visited = []

topological_sort( cur_vert, N, adj[][] ){
visited[cur_vert] = true
for i = 0 to N
if adj[cur_vert][i] is true and visited[i] is false
topological_sort(i)
T.insert_in_beginning(cur_vert)
}

```

## Time Complexity:

O(V+E).

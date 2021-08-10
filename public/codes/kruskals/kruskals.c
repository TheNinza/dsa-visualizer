// C program for Kruskal's algorithm to find Minimum
// Spanning Tree of a given connected, undirected and
// weighted graph
#include <stdio.h>

// Utility for Disjoint set
int n;

int parent[10000], rnk[10000];

// Initially, all vertices are in
// different sets and have rank 0.
void ds_initiate()
{
    for (int i = 0; i <= n; i++)
    {
        rnk[i] = 0;

        // every element is a parent of itself
        parent[i] = i;
    }
}
// Find the parent of a node 'u'
// Path Compression
int ds_find(int u)
{

    /* Make the parent of the nodes in the path
	from u--> parent[u] point to parent[u] */
    if (u != parent[u])
        parent[u] = ds_find(parent[u]);
    return parent[u];
}

// Union by rank
void ds_merge(int x, int y)
{
    x = ds_find(x), y = ds_find(y);

    /* Make tree with smaller height
	a subtree of the other tree */
    if (rnk[x] > rnk[y])
        parent[y] = x;
    else
        parent[x] = y;

    if (rnk[x] == rnk[y])
        rnk[y]++;
}

// Declaring the edges of graph matrix,
// 2rd dimension to store the source, destination node as well as the weight
int edges[10000][3] = {0};
int E = 0;

// adds an edge to the edges array
void addEdge(int u, int v, int wt)
{
    edges[E][0] = wt;
    edges[E][1] = u;
    edges[E][2] = v;
    E++;
}

//Used for sorting in kruskalMST function
void swap_edges(int i, int j)
{
    int temp_wt = edges[j][0];
    int temp_u = edges[j][1];
    int temp_v = edges[j][2];
    edges[j][0] = edges[i][0];
    edges[j][1] = edges[i][1];
    edges[j][2] = edges[i][2];
    edges[i][0] = temp_wt;
    edges[i][1] = temp_u;
    edges[i][2] = temp_v;
}

/* Functions returns weight of the MST*/
int kruskalMST()
{
    int mst_wt = 0; // Intialize result

    // Sort edges in increasing order on basis of cost, then souce and then destination
    int i, j;
    for (i = 0; i < E - 1; i++)
    {
        for (j = 0; j < E - i - 1; j++)
        {
            if (edges[j][0] > edges[j + 1][0])
                swap_edges(j, j + 1);
            if (edges[j][0] == edges[j + 1][0])
            {
                if (edges[j][1] > edges[j + 1][1])
                    swap_edges(j, j + 1);
                if (edges[j][1] == edges[j + 1][1])
                {
                    if (edges[j][2] > edges[j + 1][2])
                        swap_edges(j, j + 1);
                }
            }
        }
    }
    // Iterate through all sorted edges
    for (int i = 0; i < E; i++)
    {
        int u = edges[i][1];
        int v = edges[i][2];

        int set_u = ds_find(u);
        int set_v = ds_find(v);

        // Check if the selected edge is creating
        // a cycle or not (Cycle is created if u
        // and v belong to same set)
        if (set_u != set_v)
        {
            // Current edge will be in the MST
            // so print it
            printf("%d - %d\n", u, v);

            // Update MST weight
            mst_wt += edges[i][0];

            // Merge two sets
            ds_merge(set_u, set_v);
        }
    }

    return mst_wt;
}

// Driver program to test above functions
int main()
{
    int V = 9; // E would be update as we add edges

    addEdge(0, 1, 4);
    addEdge(0, 7, 8);
    addEdge(1, 2, 8);
    addEdge(1, 7, 11);
    addEdge(2, 3, 7);
    addEdge(2, 8, 2);
    addEdge(2, 5, 4);
    addEdge(3, 4, 9);
    addEdge(3, 5, 14);
    addEdge(4, 5, 10);
    addEdge(5, 6, 2);
    addEdge(6, 7, 1);
    addEdge(6, 8, 6);
    addEdge(7, 8, 7);

    n = V; // setting size for disjoint sets
    ds_initiate();

    printf("Edges of MST are \n");
    int mst_wt = kruskalMST();
    printf("\nWeight of MST is %d", mst_wt);

    return 0;
}

// Output:
// Edges of MST are
// 6 - 7
// 2 - 8
// 5 - 6
// 0 - 1
// 2 - 5
// 2 - 3
// 0 - 7
// 3 - 4

// Weight of MST is 37

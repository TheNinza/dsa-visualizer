// C Program of Prim's algorithm for MST

#include <stdio.h>
#define INF 65000
//Utility for priority queue
int pq[10000][2], pq_front = -1, pq_back = -1;
void pq_swap(int i, int j)
{
    int temp = pq[i][0];
    pq[i][0] = pq[j][0];
    pq[j][0] = temp;
    temp = pq[i][1];
    pq[i][1] = pq[j][1];
    pq[j][1] = temp;
}
void pq_sort(int start)
{
    int i, j;
    for (i = start; i < pq_back; i++)
        for (j = start; j < pq_back - i + start; j++)
        {
            if (pq[j][0] > pq[j + 1][0])
                pq_swap(j, j + 1);
            if (pq[j][0] == pq[j + 1][0])
            {
                if (pq[j][1] > pq[j + 1][1])
                    pq_swap(j, j + 1);
            }
        }
}
// funtion for enqueue or push
void pq_push(int wt, int v)
{
    if (pq_front == pq_back)
    {
        pq_back = 0;
        pq_front = -1;
        pq[0][0] = wt;
        pq[0][1] = v;
    }
    else
    {
        pq_back++;
        pq[pq_back][0] = wt;
        pq[pq_back][1] = v;
        pq_sort(pq_front + 1);
    }
}
// function for dequeue or pop
void pq_pop()
{
    if (pq_front == pq_back)
    {
        return;
    }
    pq_front++;
}
// function for checking if the queue is empty
int pq_empty()
{
    if (pq_front == pq_back)
        return 1;
    return 0;
}
// Declaring the adj graph matrix,
// 3rd dimension to store the destination node as well as the weight
int adj[10000][10000][2] = {0};
int gn[10000] = {0};

// adds an edge like a mocked linked list representation
void addEdge(int u, int v, int wt)
{
    adj[u][gn[u]][0] = v;
    adj[u][gn[u]][1] = wt;
    gn[u]++;
    adj[v][gn[v]][0] = u;
    adj[v][gn[v]][1] = wt;
    gn[v]++;
}

// Prints shortest path from src to all other vertices
void primMST(int V)
{
    int src = 0; // Taking vertex 0 as source

    int key[V]; // Array for keys, all initialized to INF
    for (int i = 0; i < V; i++)
        key[i] = INF;

    int parent[V]; // Array to store parent array which in turn store MST
    for (int i = 0; i < V; i++)
        parent[i] = -1;

    int inMST[V]; // To keep track of vertices included in MST
    for (int i = 0; i < V; i++)
        inMST[i] = 0;

    // Insert source itself in priority queue and initialize
    // its key as 0.
    pq_push(0, src);
    key[src] = 0;

    // Loopinp till priority queue becomes empty
    while (!pq_empty())
    {
        // The first vertex in pair is the minimum key
        // vertex, extract it from priority queue.
        // vertex label is stored in second of pair (it
        // has to be done this way to keep the vertices
        // sorted key (key must be first item
        // in pair)
        int u = pq[pq_front + 1][1];
        pq_pop();

        //Different key values for same vertex may exist in the priority queue.
        //The one with the least key value is always processed first.
        //Therefore, ignore the rest.
        if (inMST[u] == 1)
            continue;

        inMST[u] = 1; // include the vertex u in MST

        // Traverse all adjacent of u
        for (int i = 0; i < gn[u]; i++)
        {
            // Get vertex label and weight of current adjacent
            // of u.
            int v = adj[u][i][0];
            int wt = adj[u][i][1];

            // If v is not in MST and weight of (u,v) is smaller
            // than current key of v
            if (inMST[v] == 0 && key[v] > wt)
            {
                // Updating key of v
                key[v] = wt;
                pq_push(key[v], v);
                parent[v] = u;
            }
        }
    }

    // Print edges of MST using parent array
    for (int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}

// Driver program
int main()
{
    int V = 9;

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

    printf("Edges of MST are \n");
    primMST(V);

    return 0;
}

// Output:
// Edges of MST are
// 0 - 1
// 1 - 2
// 2 - 3
// 3 - 4
// 2 - 5
// 5 - 6
// 6 - 7
// 2 - 8

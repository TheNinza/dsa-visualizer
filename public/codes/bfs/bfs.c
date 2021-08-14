// C program to implement BFS
#include <stdio.h>

/*Utility functions for queue operations*/
int queue[100000] = {0}, q_front = -1, q_back = -1;
//function for enqueue or push
void q_push(int value)
{
    if (q_front == q_back)
    {
        q_back = 0;
        q_front = -1;
        queue[0] = value;
    }
    else
    {
        q_back++;
        queue[q_back] = value;
    }
}
//function for dequeue or pop
int q_pop()
{
    int value;
    if (q_front == q_back)
    {
        return 0;
    }
    q_front++;
    value = queue[q_front];

    return value;
}
//function for checking if the queue is empty
int q_empty()
{
    if (q_front == q_back)
        return 1;
    return 0;
}

// Declaring the arrays to store colour, distance
// and predecessor
char colour[10000];
int d[10000];
int p[10000];

int g[10000][10000] = {0}; //graph array
int gn[10000] = {0};       //stores number of edges starting from each node

/* This function adds an edge to the graph by mocking a linked list representation using an array.
It is an undirected graph. So edges are
added for both the nodes. We can modify this function to make the code
work with directed graph as well*/
void addEdge(int u, int v)
{
    g[u][gn[u]] = v;
    gn[u]++;
    g[v][gn[v]] = u;
    gn[v]++;
}

/* This function does the Breadth First Search*/
void BFSSingleSource(int s)
{
    // Pushing the root node inside the queue
    q_push(s);

    /* Distance of root node is 0 & colour
    is gray as it is visited partially now */
    d[s] = 0;
    colour[s] = 'g'; //using character g for grey and similarly w for white and b for black

    /* Loop to traverse the graph. Traversal
    will happen traverse until the queue is
    not empty.*/
    while (q_empty() == 0)
    {
        /* Extracting the front element(node)
        by poping it out of queue. */
        int u = q_pop();

        printf("%d ", u);

        /* This loop traverses all the child nodes of u */
        for (int i = 0; i < gn[u]; i++)
        {
            /* If the colour is white then the said node
            is not traversed. */
            if (colour[g[u][i]] == 'w')
            {
                colour[g[u][i]] = 'g';
                d[g[u][i]] = d[u] + 1;
                p[g[u][i]] = u;

                /* Pushing the node inside queue
                to traverse its children. */
                q_push(g[u][i]);
            }
        }

        /* Now the node u is completely traversed
        and colour is changed to black. */
        colour[u] = 'b';
    }
}

void BFSFull(int n)
{
    /* Initially all nodes are not traversed.
    Therefore, the colour is white. */
    for (int i = 0; i < n; i++)
        colour[i] = 'w';
    for (int i = 0; i < n; i++)
        d[i] = 0;
    for (int i = 0; i < n; i++)
        p[i] = -1;

    // Calling BFSSingleSource() for all white
    // vertices.
    printf("BFS Order is : ");
    for (int i = 0; i < n; i++)
        if (colour[i] == 'w')
            BFSSingleSource(i);
}

// Driver Function
int main()
{
    // Graph with 11 nodes and 11 edges.
    int n = 11;

    addEdge(0, 1);
    addEdge(1, 2);
    addEdge(2, 3);
    addEdge(1, 4);
    addEdge(4, 5);
    addEdge(4, 6);
    addEdge(4, 7);
    addEdge(6, 9);
    addEdge(7, 8);
    addEdge(7, 9);
    addEdge(8, 10);

    BFSFull(n);
    return 0;
}

// Output:
// BFS Order is : 0 1 2 4 3 5 6 7 9 8 10

// C Program to Implement DFS
#include <stdio.h>

// Declaring the arrays to store colour, predecessor,
// and time stamps d and f
char colour[10000];
int p[10000];
int d[10000];
int f[10000];

//Declaring the time variable
int time;

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

/* This function does the Depth First Search*/
void DFS_Visit(int s)
{
    //Color is gray as it is visited partially now
    colour[s] = 'g'; //using character g for grey and similarly w for white and b for black
    time++;
    d[s] = time;
    printf("%d ", s);

    /* This loop traverses all the child nodes of u */
    for (int i = 0; i < gn[s]; i++)
    {
        /* If the colour is white then the said node
        is not traversed. */
        if (colour[g[s][i]] == 'w')
        {
            p[g[s][i]] = s;

            //Exploring deeper
            DFS_Visit(g[s][i]);
        }
    }
    time++;
    f[s] = time;
    /* Now the node u is completely traversed
    and colour is changed to black. */
    colour[s] = 'b';
}

void DFS(int n)
{
    /* Initially all nodes are not traversed.
    Therefore, the colour is white. */
    for (int i = 0; i < n; i++)
        colour[i] = 'w';
    for (int i = 0; i < n; i++)
        p[i] = -1;
    for (int i = 0; i < n; i++)
        d[i] = 0;
    for (int i = 0; i < n; i++)
        f[i] = 0;

    time = 0;
    // Calling DFS_Visit() for all white
    // vertices.
    printf("DFS Order is : ");
    for (int i = 0; i < n; i++)
        if (colour[i] == 'w')
            DFS_Visit(i);
}

// Driver Function
int main()
{
    // Graph with 7 nodes and 6 edges.
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

    DFS(n);
    return 0;
}

// Output:
// DFS Order is : 0 1 2 3 4 5 6 9 7 8 10

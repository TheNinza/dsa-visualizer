// C program to implement Topological Sort of an Directed Acyclic Graph
#include <stdio.h>

/*Utility for Simple Stack Operations*/
int stack[10000], stack_index = 0;

int stack_empty()
{
    if (stack_index == 0)
        return 1;
    return 0;
}
void stack_push(int value)
{
    stack[stack_index] = value;
    stack_index++;
}

int stack_pop()
{
    if (!stack_empty())
    {
        stack_index--;
        return stack[stack_index];
    }
    return -1;
}

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
It is a directed graph. So edges are
added for only one of the nodes(to the node the edge emerges from). We have modified this function to make the code
work with directed graph*/

void addEdge(int u, int v)
{
    g[u][gn[u]] = v;
    gn[u]++;
    //g[v][gn[v]]=u;
    //gn[v]++;
}

/* This function does the Depth First Search*/
void DFS_Visit(int s)
{
    //Color is gray as it is visited partially now
    colour[s] = 'g'; //using character g for grey and similarly w for white and b for black
    time++;
    d[s] = time;
    //printf("%d ",s);

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

    stack_push(s); //pushing element in stack as it's set to black

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
    //printf("DFS Order is : ");
    for (int i = 0; i < n; i++)
        if (colour[i] == 'w')
            DFS_Visit(i);
}

void TS(int n)
{
    DFS(n);
    printf("Topological Order is : ");
    while (!stack_empty())
    {
        printf("%d ", stack_pop());
    }
}

// Driver Function
int main()
{
    // Graph with 11 nodes and 11 edges.
    int n = 11;

    //do not input cyclic graph
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

    TS(n);
    return 0;
}

// Output:
// Topological Order is : 0 1 4 7 8 10 6 9 5 2 3

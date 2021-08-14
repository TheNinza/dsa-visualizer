// CPP program to implement Topological Sort of an Directed Acyclic Graph
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Declaring the vectors to store color, predecessor,
// and time stamps d and f
vector<string> colour;
vector<int> p;
vector<int> d;
vector<int> f;

stack<int> st;

// Declaring time variable
int time;


/* This function adds an edge to the graph by mocking a linked list representation using an array.
It is a directed graph. So edges are
added for only one of the nodes(to the node the edge emerges from). We have modified this function to make the code
work with directed graph */
void addEdge(vector <int> g[], int u, int v)
{
    g[u].push_back(v);
    //g[v].push_back(u);
}

/* This function does the Depth First Search*/
void DFS_Visit(vector <int> g[], int s)
{
    //Color is gray as it is visited partially now
    colour[s] = "gray";
    time++;
    d[s]=time;
    //cout << s << " ";

    /* This loop traverses the child nodes of u */
    for (auto i = g[s].begin(); i != g[s].end(); i++)
    {
        /* If the colour is white then the said node
        is not traversed. */
        if (colour[*i] == "white")
        {
            p[*i] = s;

            //Exploring deeper
            DFS_Visit(g,*i);
        }
    }
    time++;
    f[s]=time;

    st.push(s); // pushing element in stack as it's set to black

    /* Now the node u is completely traversed
    and colour is changed to black. */
    colour[s] = "black";

}

void DFS(vector <int> g[], int n)
{
    /* Initially all nodes are not traversed.
    Therefore, the colour is white. */
    colour.assign(n, "white");
    p.assign(n, -1);
    d.assign(n, 0);
    f.assign(n, 0);
    time = 0;
    // Calling DFS_Visit() for all white
    // vertices.
    //cout << "DFS Order is : ";
    for (int i = 0; i < n; i++)
        if (colour[i] == "white")
            DFS_Visit(g, i);
}

void TS(vector <int> g[], int n){
    DFS(g,n);
    cout<<"Topological Order is : ";
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

}

// Driver Function
int main()
{
    // Graph with 11 nodes and 11 edges.
    int n = 11;

    // The Graph vector
    vector <int> g[n];

    //do not input cyclic graph
    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    addEdge(g, 2, 3);
    addEdge(g, 1, 4);
    addEdge(g, 4, 5);
    addEdge(g, 4, 6);
    addEdge(g, 4, 7);
    addEdge(g, 6, 9);
    addEdge(g, 7, 8);
    addEdge(g, 7, 9);
    addEdge(g, 8, 10);

    TS(g, n);

    return 0;
}

// Output:
// Topological Order is : 0 1 4 7 8 10 6 9 5 2 3

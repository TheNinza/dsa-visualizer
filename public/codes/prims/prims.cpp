// CPP Program of Prim's algorithm for MST
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
# define INF 65000

// iPair ==> Integer Pair
typedef pair<int, int> iPair;

// To add an edge
void addEdge(vector <pair<int, int> > adj[], int u,
									int v, int wt)
{
	adj[u].push_back(make_pair(v, wt));
	adj[v].push_back(make_pair(u, wt));
}

// Prints shortest paths from src to all other vertices
void primMST(vector<pair<int,int> > adj[], int V)
{
	// Create a priority queue to store vertices that
	// are being preinMST.
	priority_queue< iPair, vector <iPair> , greater<iPair> > pq;

	int src = 0; // Taking vertex 0 as source

	// Create a vector for keys and initialize all
	// keys as infinite (INF)
	vector<int> key(V, INF);

	// To store parent array which in turn store MST
	vector<int> parent(V, -1);

	// To keep track of vertices included in MST
	vector<bool> inMST(V, false);

	// Insert source itself in priority queue and initialize
	// its key as 0.
	pq.push(make_pair(0, src));
	key[src] = 0;

	/* Looping till priority queue becomes empty */
	while (!pq.empty())
	{
		// The first vertex in pair is the minimum key
		// vertex, extract it from priority queue.
		// vertex label is stored in second of pair (it
		// has to be done this way to keep the vertices
		// sorted key (key must be first item
		// in pair)
		int u = pq.top().second;
		pq.pop();

		// Different key values for same vertex may exist in the priority queue.
		// The one with the least key value is always processed first.
		// Therefore, ignore the rest.
		if(inMST[u] == true){
			continue;
		}
	
		inMST[u] = true; // Include vertex in MST

		// Traverse all adjacent of u
		for (auto x : adj[u])
		{
			// Get vertex label and weight of current adjacent
			// of u.
			int v = x.first;
			int weight = x.second;

			// If v is not in MST and weight of (u,v) is smaller
			// than current key of v
			if (inMST[v] == false && key[v] > weight)
			{
				// Updating key of v
				key[v] = weight;
				pq.push(make_pair(key[v], v));
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
	vector<iPair > adj[V];

	addEdge(adj, 0, 1, 4);
	addEdge(adj, 0, 7, 8);
	addEdge(adj, 1, 2, 8);
	addEdge(adj, 1, 7, 11);
	addEdge(adj, 2, 3, 7);
	addEdge(adj, 2, 8, 2);
	addEdge(adj, 2, 5, 4);
	addEdge(adj, 3, 4, 9);
	addEdge(adj, 3, 5, 14);
	addEdge(adj, 4, 5, 10);
	addEdge(adj, 5, 6, 2);
	addEdge(adj, 6, 7, 1);
	addEdge(adj, 6, 8, 6);
	addEdge(adj, 7, 8, 7);

	cout<<"Edges of MST are" << endl;
	primMST(adj, V);

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

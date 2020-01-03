// C++ program to print connected components in 
// an undirected graph 
#include<iostream> 
#include <list> 
using namespace std;algorithm to check whether minimum spanning tree is unique

// Graph class represents a undirected graph 
// using adjacency list representation 
class Graph 
{ 
	int V; // No. of vertices 

	// Pointer to an array containing adjacency lists 
	list<int> *adj; 

	// A function used by DFS 
	void DFSUtil(int v, bool visited[]); 
public: 
	Graph(int V); // Constructor 
	void addEdge(int v, int w); 
	void connectedComponents(); 
}; 
/*
First find a minimum spanning tree with standard techniques.

Go back to your original tree, and replace all weights with pairs of numbers, the original weight, and then 0 or 1 based on whether or not it is in the MST you found. These pairs of numbers can be added together pairwise, and compared pairwise as well - just like normal numbers.

Now use the standard techniques to find a minimum spanning tree with these funny weights. The MST that you find will be the MST which shares the least edges with your original tree. Thus if there are multiple MSTs, you are guaranteed to find a different one.
*/

// Method to print connected components in an 
// undirected graph 
void Graph::connectedComponents() 
{ 
	// Mark all the vertices as not visited 
	bool *visited = new bool[V]; 
	for(int v = 0; v < V; v++) 
		visited[v] = false; 

	for (int v=0; v<V; v++) 
	{ 
		if (visited[v] == false) 
		{ 
			// print all reachable vertices 
			// from v 
			DFSUtil(v, visited); 

			cout << "\n"; 
		} 
	} 
} 

void Graph::DFSUtil(int v, bool visited[]) 
{ 
	// Mark the current node as visited and print it 
	visited[v] = true; 
	cout << v << " "; 

	// Recur for all the vertices 
	// adjacent to this vertex 
	list<int>::iterator i; 
	for(i = adj[v].begin(); i != adj[v].end(); ++i) 
		if(!visited[*i]) 
			DFSUtil(*i, visited); 
} 

Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<int>[V]; 
} 

// method to add an undirected edge 
void Graph::addEdge(int v, int w) 
{ 
	adj[v].push_back(w); 
	adj[w].push_back(v); 
} 

// Drive program to test above 
int main() 
{ 
	// Create a graph given in the above diagram 
	Graph g(5); // 5 vertices numbered from 0 to 4 
	g.addEdge(1, 0); 
	g.addEdge(2, 3); 
	g.addEdge(3, 4); 

	cout << "Following are connected components \n"; 
	g.connectedComponents(); 

	return 0; 
} 

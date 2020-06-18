#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V; // No. of vertices
	list<int> *adj;
	public:
	Graph(int V);
	void addEdge(int u, int v);
	void BFS(int s);	
};
Graph::Graph(int V)
{
	this->V = V;
	adj = new list<int> [V];
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
}

void Graph::BFS(int s)
{
	bool *visited = new bool[V];// Mark every vertex as unvisited
	for(int i = 0; i < V; i++)
		visited[i] = false;
	// Mark source as visited and add to queue
	visited[s] = true;

	list<int>queue;
	queue.push_back(s);

	while(!queue.empty())
	{
		// Pop the first element and add its unvisited children
		s = queue.front();
		cout<<s<<" ";
		queue.pop_front();
		for(int v : adj[s])
		{
			if(visited[v] == false)
			{
				visited[v] = true;
				queue.push_back(v);
			}
		}
	}
}


int main() 
{ 
    // Create a graph given in the above diagram 
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
  
    cout << "Following is Breadth First Traversal "
         << "(starting from vertex 2) \n"; 
    g.BFS(2); 
  
    return 0; 
} 
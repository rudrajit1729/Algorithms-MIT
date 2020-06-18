// DFS Implementation using Adjacency list
// Author - rudrajit1729

#include<bits/stdc++.h>
using namespace std;

class Graph
{
	list<int> *graph;
	int V;
public:
	Graph(int V);
	void addEdge(int u, int v);
	void DFS_Visit(int s, bool *visited);
	void DFS();
};

Graph::Graph(int V)
{
	this->V = V;
	graph = new list<int> [V];
}

void Graph::addEdge(int u, int v)
{
	graph[u].push_back(v);
}

void Graph::DFS_Visit(int s, bool *visited)
{
	cout<<s<<"\t";
	visited[s] = true;
	for(int v : graph[s])
	{
		if (!visited[v])
			{
				DFS_Visit(v, visited);
			}
	}	
}

void Graph::DFS()
{
	bool *visited = new bool[V];
	for(int i = 0; i< V; i++) visited[i] = false;
	for(int s = 0; s < V; s++)
	{
		if (!visited[s])
		{
			DFS_Visit(s, visited);
		}
	}
}

int main() 
{ 
    // Create a graph given in the above diagram 
    // Graph g(4); 
    // g.addEdge(0, 1); 
    // g.addEdge(0, 2); 
    // g.addEdge(1, 2); 
    // g.addEdge(2, 0); 
    // g.addEdge(2, 3); 
    // g.addEdge(3, 3); 
  	Graph g(6);
	g.addEdge(5, 0);
	g.addEdge(5, 2);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(2, 3);
	g.addEdge(3, 1);
    cout << "Following is Depth First Traversal \n"; 
    g.DFS(); 
  	cout<<endl;
    return 0; 
} 
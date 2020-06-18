#include<bits/stdc++.h>
using namespace std;

// Class to represent graph as adjacency list
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
	map<int, int> level;
	level[s] = 0;
	map<int, int> parent;
	parent[s] = -1;
	int i = 1;
	list<int> frontier;
	frontier.push_back(s); // Level i-1
	cout<<s<<"\t";
	while(!frontier.empty())
	{
		list<int> next; // Level i
		for(int u : frontier)
		{
			for(int v : adj[u])
			{
				if(level.find(v) == level.end())
				{
					cout<<v<<"\t";
					level[v] = i;
					parent[v] = u;
					next.push_back(v);
				}
			}
		}
		frontier = next;
		i += 1;
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
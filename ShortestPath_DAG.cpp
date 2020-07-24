// Shortest path in DAG(Direct Acyclic Graph)
// Author - rudrajit1729
// Approach - Topologically sort the graph -> Once sorted start from 
// the required vertex and go right relaxing the edges
// Finally you get to the shortest path for every node reachable from that node

#include<bits/stdc++.h>
#define INF 99999999
using namespace std;

// Class representing graph as adjacency list
class Graph
{
	list<pair<int, int>> *graph;
	int V; // Number of vertices
public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void DFS_Visit(int s, bool *visited, stack<int> &Stack);
	void shortestPath(int s);
};

Graph::Graph(int V) 
{
	this->V = V;
	graph = new list<pair<int, int>> [V];
}

void Graph::addEdge(int u, int v, int w) // Adds an edge to the graph 
{
	pair<int, int> node (v, w);
	graph[u].push_back(node);
}

void Graph::DFS_Visit(int s, bool *visited, stack<int> &Stack) // DFS for a node
{
	visited[s] = true;
	list<pair<int, int>> ::iterator it;
	for(it = graph[s].begin(); it != graph[s].end(); ++it)
	{
		pair<int, int> node = *it;
		int v = node.first;
		if(!visited[v])
		{
			DFS_Visit(v, visited, Stack);
		}
	}
	Stack.push(s);
}

void Graph::shortestPath(int s) // Shortest path to nodes from a given node
{
	bool *visited = new bool[V];
	stack<int> Stack; // Stack for storing order
	for(int i = 0; i < V; ++i) visited[i] = false;
	for (int v = 0; v < V; v++)
	{
		if(!visited[v]) DFS_Visit(v, visited, Stack);
	}
	// Now stack has the topological sorted order
	int dist[V];
	for(int i = 0; i< V ; i++) dist[i] = INF; // Other distances INF
	dist[s] = 0;// Distance to source 0
	
	while(!Stack.empty())
	{
		int u = Stack.top();
		Stack.pop();
		// Relax the vertices - Update distances of all adjacent vertices
		list<pair<int, int>> ::iterator it;
		for(it = graph[u].begin(); it != graph[u].end(); ++it)
		{
			pair<int, int> node = *it;
			int v = node.first, w = node.second;
			if(dist[v] > dist[u] + w)
				dist[v] = dist[u] + w;
		}
	}

	// Print the calculated shortest path
	for(int v = 0; v < V; v++)
	{
		if (dist[v] == INF)
			cout<<"INF\t";
		else
			cout<<dist[v]<<"\t";
	}
	cout<<endl;
}

int main() 
{ 
    Graph g(6); 
    g.addEdge(0, 1, 5); 
    g.addEdge(0, 2, 3); 
    g.addEdge(1, 3, 6); 
    g.addEdge(1, 2, 2); 
    g.addEdge(2, 4, 4); 
    g.addEdge(2, 5, 2); 
    g.addEdge(2, 3, 7); 
    g.addEdge(3, 4, -1); 
    g.addEdge(4, 5, -2); 
  
    int s = 1; 
    cout << "Following are shortest distances from source " << s <<"\n"; 
    g.shortestPath(s); 
    return 0; 
} 


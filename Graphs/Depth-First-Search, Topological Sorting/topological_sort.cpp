// Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that
// for every directed edge uv, vertex u comes before v in the ordering. 
// Topological Sorting for a graph is not possible if the graph is not a DAG.
// Author - rudrajit1729

// Approach - Run DFS on the graph -> Output reverse order of finishing times of vertices

#include<bits/stdc++.h>
using namespace std;

class Graph
{
	list<int> *graph;
	int V;
public:
	Graph(int V);
	void addEdge(int u, int v);
	void DFS_Visit(int s, bool *visited, stack<int> &Stack);
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

void Graph::DFS_Visit(int s, bool *visited, stack<int> &Stack)
{
	visited[s] = true;
	for(int v : graph[s])
	{
		if (!visited[v])
			{
				DFS_Visit(v, visited, Stack);
			}
	}
	Stack.push(s);
}

void Graph::DFS()
{
	bool *visited = new bool[V];
	stack<int> Stack;

	for(int i = 0; i< V; i++) visited[i] = false;
	for(int s = 0; s < V; s++)
	{
		if (!visited[s])
		{
			DFS_Visit(s, visited, Stack);
		}
	}
	// Printing job sequence - finishing times in reverse order
	while(!Stack.empty())
	{
		cout<<Stack.top()<<" ";
		Stack.pop();
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
    cout << "Job Scheduling \n"; 
    g.DFS(); 
  	cout<<endl;
    return 0; 
} 
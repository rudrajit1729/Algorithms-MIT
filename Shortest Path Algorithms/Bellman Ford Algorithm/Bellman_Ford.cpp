// Bellman Ford Algorithm 
// Author - rudrajit1729

#include<bits/stdc++.h>
#define INF 99999999
using namespace std;

// Class for Edge
class Edge
{
	int u, v, w;
public:
	Edge(int u, int v, int w) {this->u = u; this->v = v; this->w = w;}
	int getu() {return u;}
	int getv() {return v;}
	int getw() {return w;}
};

// Class representation of graph
class Graph
{
	vector<Edge> graph;
	int V, E = 0;
public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void showpath(int dist[]);
	void BellmanFord(int s);
};

Graph::Graph(int V)
{
	this->V = V;
}

void Graph::addEdge(int u, int v, int w) // Adds an edge
{
	Edge e(u, v, w);
	graph.push_back(e);
	E++;
}

void Graph::showpath(int dist[]) // Shortest paths to vertices 
{
	cout<<"Vertex Distance From Source\n";
	for(int i = 0; i < V; i++)
		cout<<i<<"\t\t"<<dist[i]<<endl;
}


void Graph::BellmanFord(int s)
{
	// Initialize
	int dist[V];
	for(int i = 0; i < V; i++) dist[V] = INF;
	dist[s] = 0;
	
	// Relax all edges |V|-1 times
	// Simple shortest path from s to v can have atmost |V|-1 edges
	for(int i = 0; i < V - 1; i++)
	{
		for(int j = 0; j < E; j++)
		{
			int u = graph[j].getu(), v = graph[j].getv(), w = graph[j].getw();
			if(dist[u] != INF && dist[u] + w < dist[v])
				dist[v] = dist[u] + w;
		}
	}

	// Check for -ve weight cycles
	// Above we have computed the shortest path possible 
	// If here we can shorten the path that implies there is a -ve weight cycle
	for(int j = 0; j < E; j++)
	{
		int u = graph[j].getu(), v = graph[j].getv(), w = graph[j].getw();
		if(dist[u] != INF && dist[u] + w < dist[v])
		{
			cout<<"Graph has negative weight cycle - Shortest path can't be computed\n";
			return;
		}
	}
	showpath(dist);
}

int main()
{
	Graph g(5);
	g.addEdge(0, 1, -1);  
	g.addEdge(0, 2, 4);  
	g.addEdge(1, 2, 3);  
	g.addEdge(1, 3, 2);  
	g.addEdge(1, 4, 2);  
	g.addEdge(3, 2, 5);  
	g.addEdge(3, 1, 1);  
	g.addEdge(4, 3, -3); 
	  
	// Print the solution  
	g.BellmanFord(0);  

}





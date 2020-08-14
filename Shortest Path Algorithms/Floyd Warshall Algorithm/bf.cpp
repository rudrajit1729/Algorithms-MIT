// Floyd Warshall Algorithm - DP approach using ajcacency matrix
// Author - rudrajit1729

#include<bits/stdc++.h>
using namespace std;

class Graph
{
	int V;
public:
	vector<vector<int>> graph;
	Graph(int v);
	void floydWarshall();
};

Graph::Graph(int v)
{
	this->V = v;
}

void Graph::floydWarshall()
{
	int V = this->V;
	int INF = 999;
	for(int k = 0; k < V; k++)
	{
		for(int i = 0; i < V; i++)
		{
			for(int j = 0; j < V; j++)
			{
				if (graph[i][j] > graph[i][k] + graph[k][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
	cout<<"\nDistances\n";
	for(int i = 0; i < V; i++)
	{
		for(int j = 0; j < V; j++)
		{	
			if (graph[i][j] == INF)
				cout<<"INF ";
			else
			cout<<graph[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int n, x;
	cout << "Enter number of vertices: ";
	cin>>n;
	Graph g(n);
	for (int i = 0; i < n; i++)
	{
		vector<int> row;
		for(int j = 0; j < n; j++)
		{
			cin>>x;
			row.push_back(x);
		}
		g.graph.push_back(row);
	}
	g.floydWarshall();

}
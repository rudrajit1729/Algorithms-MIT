// Dijkstra's Algorithm - Single source All pair Shortest Path 
// Adjacency List representation of Graph & Priority Queue Utility
// Author - rudrajit1729

#include<bits/stdc++.h>
#define INF 99999999
#define NONE -9999999
using namespace std;

// Class for representing priority Queue implemented via min Heap
class Queue
{
public:
	vector<pair<int, int>> heap;
	vector<int> ind;
	int heapSize = 0;
	int parent(int i) {return (i-1)/2;} // Parent index of node i
	bool isEmpty() {return (heapSize == 0)?true:false;} // Queue empty check
	void nodeSwapper(int x, int y); 
	bool isInQueue(int v) {return (ind[v] < heapSize)?true:false;} // Checks presence of vertex in queue
	void minHeapify(int i);
	int extractMin();
	void decreaseKey(int v, int d);
	void push(int v, int d);
};

// Utility Function - Swaps two nodes in Queue
void Queue::nodeSwapper(int x, int y)
{
	pair<int, int> temp = heap[x];
	heap[x] = heap[y];
	heap[y] = temp;
}

// MinHeapify - Maintains min heap property of Priority Queue
void Queue::minHeapify(int i)
{
	int smallest = i;
	int left = 2 * i + 1, right = 2 * i + 2; // Children of i

	// If left child exists and is less than root in dist value
	if (left < heapSize and heap[left].second < heap[smallest].second)
		smallest = left;

	// If right child exists and is less than smallest in dist value
	if (right < heapSize and heap[right].second < heap[smallest].second)
		smallest = right;

	// If root isn't the smallest update the heap
	if (smallest != i)
	{
		// Swap positions and nodes
		ind[heap[smallest].first] = i;
		ind[heap[i].first] = smallest;

		nodeSwapper(smallest, i);

		// Heapify node 
		minHeapify(smallest);
	}	
}

// Extract Min - Removes and returns the node in queue with least dist value
int Queue::extractMin()
{
	// Store the min node
	pair<int, int> minNode = heap[0];

	// Replace minNode with maxNode
	pair<int, int> maxNode = heap[heapSize - 1];
	heap[0] = maxNode;

	// Update index of maxNode
	ind[maxNode.first] = 0;
	ind[minNode.first] = heapSize - 1;

	// Reduce heapsize and heapify root
	heapSize--;
	minHeapify(0);

	return minNode.first;
}

// Decrease Key - Decreases dist value of a vertex
void Queue::decreaseKey(int v, int dist)
{
	// Get position of vertex in Queue and update it's dist value
	int i = ind[v];
	heap[i].second = dist;

	// Fix min heap property if violated
	int p = parent(i);
	while(i > 0 && heap[i].second < heap[p].second)
	{
		ind[heap[i].first] = p;
		ind[heap[p].first] = i;
		nodeSwapper(i, p);

		// Update node and parent index
		i = p;
		p = parent(i);
		//cout<<i<<" "<<p<<endl;
	}
}

// Insert Key - Inserts v, dist[v] in Queue
void Queue::push(int v, int d)
{
	pair<int, int> node(v, d);
	heap.push_back(node);
	ind.push_back(v);
}


// Class representing Graph as a Adjacency List
class Graph
{
	list<pair<int, int>> *graph;
	int V;
public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void dijkstra(int s);
	void showDistances(int dist[]);
};

Graph::Graph(int V)
{
	this->V = V;
	graph = new list <pair<int, int>> [V];
}

// Adds an edge to the graph
void Graph::addEdge(int u, int v, int w)
{
	pair<int, int> nodef(v, w);
	graph[u].push_back(nodef);
	// Comment this out in case of directed graph
	pair<int, int> nodeb(u, w);
	graph[v].push_back(nodeb);
}

// Dijkstra's Shortest Path Algorithm - O(ElogV)
void Graph::dijkstra(int s)
{
	int dist[V]; // Storing min dist
	int parent[V]; // Tracing out path
	Queue Q;

	// Initialize
	for(int v = 0; v < V; v++)
	{
		dist[v] = INF;
		parent[v] = NONE;
		Q.push(v, dist[v]);
	}
	// Set distance of source 0 such that it gets extracted from Queue
	Q.ind[s] = s; dist[s] = 0; parent[s] = s;
	Q.decreaseKey(s, dist[s]);
	Q.heapSize = V; // Length of Queue

	// Traverse through the graph
	// Greedy Approach to figure out shortest distance
	while(Q.isEmpty() == false)
	{
		//  Extract vertex with min dist value
		//  If we are interested only in shortest distance from source to a single target,
		//  we can break the for loop when the picked minimum distance vertex is equal to target.
		int u = Q.extractMin();
		// Traverse adjacent vertices of u and relax them if necessary
		list<pair<int, int>>::iterator it;
		for(it = graph[u].begin(); it != graph[u].end(); ++it)
		{
			pair<int, int> node = *it;
			int v = node.first, w = node.second;
			
			if (Q.isInQueue(v) && dist[u] != INF && dist[v] > dist[u] + w)
			{
				// Relax the vertex
				dist[v] = dist[u] + w;
				parent[v] = u;
				// Update dist value in Queue
				Q.decreaseKey(v, dist[v]);
			}
		}
	}

	// Display the shortest distances
	showDistances(dist);
}

// Utility Function - Displays shortest distances
void Graph::showDistances(int dist[])
{
	cout<<"Vertex\t\tDistance from Source\n";
	for (int v = 0; v < V; v++)
	{	if (dist[v] == INF)
			cout<<v<<"\t\tINF\n";
		else 
		cout<<v<<"\t\t"<<dist[v]<<endl;
	}
}

int main()
{
	Graph g(9);
	g.addEdge(0, 1, 4);
	g.addEdge(0, 7, 8);
	g.addEdge(1, 2, 8);
	g.addEdge(1, 7, 11); 
	g.addEdge(2, 3, 7);
	g.addEdge(2, 8, 2);
	g.addEdge(2, 5, 4);
	g.addEdge(3, 4, 9);
	g.addEdge(3, 5, 14); 
	g.addEdge(4, 5, 10); 
	g.addEdge(5, 6, 2);
	g.addEdge(6, 7, 1);
	g.addEdge(6, 8, 6);
	g.addEdge(7, 8, 7);

	int s = 0;
	cout<<"Dijkstra's Algorithm\nChosen Source : "<<s<<endl;
	g.dijkstra(s);
}
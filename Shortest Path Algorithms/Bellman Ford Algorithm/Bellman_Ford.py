# Bellman Ford Implementation Adjacency List
# Author - rudrajit1729

# Class to reperesent graph
class Graph:
	def __init__(self, V):
		self.V = V
		self.graph = []

	# Adds edge to graph
	def addEdge(self, u, v, w):
		self.graph.append([u, v, w])

	# Prints distances from source
	def showpath(self, dist):
		print("Vertex distance from Source")
		for i in range(self.V):
			print("{}\t\t{}".format(i, dist[i]))

	# Finds shortest path from src to every vertex using Bellman Ford 
	# Also detects presence of -ve weight cycles
	def BellmanFord(self, s):
		# Initialize
		dist = [float("Inf")] * self.V
		dist[s] = 0
		parent = [None] * self.V

		# Relax all edges |V| - 1 times
		# Simple shortest path from s to v can have atmost |V|-1 edges
		for i in range(self.V - 1):
			for u,v,w in self.graph:
				if dist[u] != float("Inf") and dist[u] + w < dist[v]:
					dist[v] = dist[u] + w
					parent[v] = u

		# Check for -ve weight cycles.
		# Above we have computed the shortest path possible 
		# If here we can shorten the path that implies there is a -ve weight cycle
		for u, v, w in self.graph:
			if dist[u] != float("Inf") and dist[u] + w < dist[v]:
				print("Graph has negative weight cycle - Shortest path can't be computed")
				return

		# Display the shortest path
		self.showpath(dist)

def main():
	g = Graph(5)
	g.addEdge(0, 1, -1)  
	g.addEdge(0, 2, 4)  
	g.addEdge(1, 2, 3)  
	g.addEdge(1, 3, 2)  
	g.addEdge(1, 4, 2)  
	g.addEdge(3, 2, 5)  
	g.addEdge(3, 1, 1)  
	g.addEdge(4, 3, -3)  
	  
	# Print the solution  
	g.BellmanFord(0)  

if __name__ == "__main__":
	main()



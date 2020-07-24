# Shortest Path in a Direct Acyclic Graph(DAG)
# Author - rudrajit1729
# Approach - Topologically sort the graph -> Once sorted start from 
# the required vertex and go right relaxing the edges
# Finally you get shortest path for every node reachable from that node

from collections import defaultdict

# Class representing graph as adjacency list
class Graph:
	def __init__ (self, V):
		self.graph = defaultdict(list)
		self.V = V # Number of vertices

	def addEdge(self, u, v, w): # Adds an edge in the graph
		self.graph[u].append((v, w))

	def DFS_Visit(self, s, visited, stack): # DFS for a node
		visited[s] = True
		if s in self.graph.keys():
			for v, w in self.graph[s]:
				if not visited[v]:
					self.DFS_Visit(v, visited, stack)
		stack.append(s)

	def shortestPath(self, s): # Shortest path to nodes from given node
		visited = [False] * self.V
		stack = [] # Stack for storing order

		for v in range(self.V):
			if not visited[v]:
				self.DFS_Visit(v, visited, stack)
		# Now stack has the topological sorted order
		# Distance to source is 0
		dist = [float("Inf")] * self.V
		dist[s] = 0

		# Process the vertices in topological order
		while stack:
			u = stack.pop()
			# Relax the vertices
			# Update distances of all adjacent vertices
			for v, w in self.graph[u]:
				if dist[v] > dist[u] + w:
					dist[v] = dist[u] + w

		# Print the calculated shortest distances
		for v in range(self.V):
			if dist[v] == float("Inf"):
				print("INF", end = "\t")
			else:
				print(dist[v], end = "\t")

def main():
	g = Graph(6) 
	g.addEdge(0, 1, 5) 
	g.addEdge(0, 2, 3) 
	g.addEdge(1, 3, 6) 
	g.addEdge(1, 2, 2) 
	g.addEdge(2, 4, 4) 
	g.addEdge(2, 5, 2) 
	g.addEdge(2, 3, 7) 
	g.addEdge(3, 4, -1) 
	g.addEdge(4, 5, -2) 
	  
	# source = 1 
	s = 1
	print("Following are shortest distances from source ", s)
	g.shortestPath(s)

if __name__ == '__main__':
	main()

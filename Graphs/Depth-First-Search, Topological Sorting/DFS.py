# DFS Implementation using Adjacency list
# Author - rudrajit1729

from collections import defaultdict

# Class representing graph as adjacency list
class Graph:
	def __init__ (self, V):
		self.graph = defaultdict(list)
		self.V = V # Number of vertices

	def addEdge(self, u, v): # Adds an edge in the graph
		self.graph[u].append(v)

	def DFS_Visit(self, s, visited): # DFS for a node
		visited[s] = True
		print(s, end = " ")

		for v in self.graph[s]:
			if not visited[v]:
				self.DFS_Visit(v, visited)

	def DFS(self): # DFS traversal of graph
		visited = [False] * self.V

		for s in range(self.V):
			if not visited[s]:
				self.DFS_Visit(s, visited)


def main():
	g = Graph(6)
	g.addEdge(5, 0)
	g.addEdge(5, 2)
	g.addEdge(4, 0)
	g.addEdge(4, 1)
	g.addEdge(2, 3)
	g.addEdge(3, 1)
	print("DFS traversal of the graph G: ")
	g.DFS()

	f = Graph(4)
	f.addEdge(0, 1) 
	f.addEdge(0, 2) 
	f.addEdge(1, 2) 
	f.addEdge(2, 0) 
	f.addEdge(2, 3) 
	f.addEdge(3, 3) 
	print("\nDFS traversal of the graph F: ")
	f.DFS()

if __name__ == '__main__':
	main()

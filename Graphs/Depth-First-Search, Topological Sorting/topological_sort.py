# Topological sorting for Directed Acyclic Graph (DAG) is a linear ordering of vertices such that
# for every directed edge uv, vertex u comes before v in the ordering. 
# Topological Sorting for a graph is not possible if the graph is not a DAG.
# Author - rudrajit1729

# Approach - Run DFS on the graph -> Output reverse order of finishing times of vertices

from collections import defaultdict

# Class representing graph as adjacency list
class Graph:
	def __init__ (self, V):
		self.graph = defaultdict(list)
		self.V = V # Number of vertices

	def addEdge(self, u, v): # Adds an edge in the graph
		self.graph[u].append(v)

	def DFS_Visit(self, s, visited, stack): # DFS for a node
		visited[s] = True

		for v in self.graph[s]:
			if not visited[v]:
				self.DFS_Visit(v, visited, stack)
		stack.insert(0, s)

	def DFS(self): # DFS traversal of graph
		visited = [False] * self.V
		stack = [] # Stack for storing order
		for s in range(self.V):
			if not visited[s]:
				self.DFS_Visit(s, visited, stack)
		print(stack)


def main():
	g = Graph(6)
	g.addEdge(5, 0)
	g.addEdge(5, 2)
	g.addEdge(4, 0)
	g.addEdge(4, 1)
	g.addEdge(2, 3)
	g.addEdge(3, 1)
	print("Job Scheduling of G : ")
	g.DFS()

	f = Graph(4)
	f.addEdge(0, 1) 
	f.addEdge(0, 2) 
	f.addEdge(1, 2) 
	f.addEdge(2, 0) 
	f.addEdge(2, 3) 
	f.addEdge(3, 3) 
	print("\nJob Scheduling of F : ")
	f.DFS()

if __name__ == '__main__':
	main()

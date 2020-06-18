# BFS Implementation
# Author - rudrajit1729
from collections import defaultdict

# Adjacency list representation
class Graph:

	def __init__(self):
		self.graph = defaultdict(list)

	def addEdge(self, u, v):# Adds edge to the graph
		self.graph[u].append(v)

	def BFS(self, s):
		level = {s:0} # Stores vertices with associated levels(moves to reach it from vertex)		
		parent = {s:None} # Stores parent of vertices -> traverse in reverse order from destination to parent to get shortest path(and level gives the length of shortest path)
		i = 1
		frontier = [s] # Level i-1
		print(s, end = "\t")
		while frontier:
			next = [] # Level i
			for u in frontier:
				for v in self.graph[u]:
					if v not in level:
						print(v, end = "\t")
						level[v] = i
						parent[v] = u
						next.append(v)
			frontier = next
			i += 1
		print()


def main():
	g = Graph()
	# g.addEdge(0, 1)
	# g.addEdge(0, 2)
	# g.addEdge(1, 2)
	# g.addEdge(2, 0)
	# g.addEdge(2, 3)
	# g.addEdge(3, 3)
	# g.BFS(2)
	while(True):
		u, v = map(int, input("Enter Edge(u, v) : ").split())
		g.addEdge(u, v)
		f = input("Press y/n to continue/ done").lower()
		if not f.startswith("y"):
			break
	s = int(input("Enter the start Vertex : "))
	print("BFS Traversal from source : ", s)
	g.BFS(s)


if __name__=="__main__":
	main()

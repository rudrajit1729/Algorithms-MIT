# Bellman Ford Algorithm And Floyd Warshall Algorithm - DP approach using ajcacency matrix
# Author - rudrajit1729

class Graph:
	def __init__(self, V):
		self.graph = []
		self.INF = 99999999
		self.V = V

	def inComing(self, v):
		for i in range(len(v)):
			if v[i]!=self.INF and v[i]!=0:
				return True
		return False

	def bellman(self, s):

		dist = []
		V = self.V
		for i in range(V):
			dist.append(self.graph[s][i])

		for k in range(1, V - 1):
			for v in range(V):
				if s != v and self.inComing(self.graph[:v]):
					for i in range(V):
						if dist[v] > dist[i] + self.graph[i][v]:
							dist[v] = dist[i] + self.graph[i][v]
							

		for v in range(V):
			if s != v and self.inComing(self.graph[:v]):
					for i in range(V):
						if dist[v] > dist[i] + self.graph[i][v]:
							print("-ve cycle")
							return

		print("Vertex\tDistance From Source")
		for i in range(V):
			print("{}\t\t{}".format(i, dist[i]))

	def floydWarshall(self):
		V = self.V
		for k in range(0, V):
			for i in range(0, V):
				for j in range(0, V):
					if (self.graph[i][j] > self.graph[i][k] + self.graph[k][j]):
						self.graph[i][j] = self.graph[i][k] + self.graph[k][j]

		print("Distances")
		for i in range(V):
			for j in range(V):
				print(self.graph[i][j], end = " ")
			print()

def main():
	n = int(input("Enter number of vertices : "))
	g = Graph(n)
	for i in range(n):
		l = []
		s = input().split()
		for j in s:
			if j == "INF":
				l.append(g.INF)
			else:
				l.append(int(j))
		g.graph.append(l)
	# graph = [[0, -1, 4, INF, INF],
	# 		[INF, 0, 3, 2, 2],
	# 		[INF, INF, 0, INF, INF],
	# 		[INF, 1, 5, 0, INF],
	# 		[INF, INF, INF, -3, 0]
	# 		]
	#s = int(input("Enter source : "))

	#g.bellman(s)

	# graph2 =[[0, 5, INF, INF], 
	# 		 [50, 0, 15, 5],
	# 		 [30, INF, 0, 15],
	# 		 [15, INF, 5, 0]]
	g.floydWarshall() 

if __name__ == '__main__':
	main()

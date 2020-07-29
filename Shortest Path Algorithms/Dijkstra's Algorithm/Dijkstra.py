# Dijkstra's Algorithm - Single source All pair Shortest Path 
# Adjacency List representation of Graph & Priority Queue Utility
# Author - rudrajit1729

from collections import defaultdict

class Queue:

	def __init__(self):
		self.heap = [] # Priority Queue
		self.ind = []  # Index of Vertices
		self.heapSize = 0 # Size of Queue

	# Utility Function - returns index of parent node
	def parent(self, i):
		return (i-1)//2

	# Utility Function - Checks whether queue is empty or not
	def isEmpty(self):
		return True if self.heapSize == 0 else False

	# Utility Function - Swaps two nodes in Queue
	def nodeSwapper(self, x, y):
		temp = self.heap[x]
		self.heap[x] = self.heap[y]
		self.heap[y] = temp

	# Utility Function - Checks for a vertex in the Queue
	def isInQueue(self, v):
		return True if self.ind[v] < self.heapSize else False

	# MinHeapify - Maintains min heap property of Priority Queue
	def minHeapify(self, i):
		smallest = i
		left, right = 2 * i + 1, 2 * i + 2 # Children index of i

		# If left child exists and is less than root in dist value
		if left < self.heapSize and self.heap[left][1] < self.heap[smallest][1]:
			smallest = left

		# If right child exists and is less than smallest in dist value
		if right < self.heapSize and self.heap[right][1] < self.heap[smallest][1]:
			smallest = right

		# If root isn't the smallest update the heap
		if smallest != i:
			# Swap positions and nodes
			self.ind[self.heap[smallest][0]] = i
			self.ind[self.heap[i][0]] = smallest

			self.nodeSwapper(smallest, i)

			# Heapify node 
			self.minHeapify(smallest)

	# Extract Min - Removes and returns the node in queue with least dist value
	def extractMin(self):
		if self.isEmpty():
			return

		# Store the min node
		minNode = self.heap[0]

		# Replace minNode with maxNode
		maxNode = self.heap[self.heapSize - 1]
		self.heap[0] = maxNode

		# Update index of maxNode
		self.ind[maxNode[0]] = 0
		self.ind[minNode[0]] = self.heapSize - 1

		# Reduce heapsize and heapify root of heap
		self.heapSize -= 1
		self.minHeapify(0)

		return minNode[0]

	# Decrease Key - Decreases dist value of a vertex
	def decreaseKey(self, v, d):
		# Get the position of vertex in Queue and update it's dist value
		i = self.ind[v]
		self.heap[i][1] = d

		# Fix min heap property if violated
		p = self.parent(i)
		while i > 0 and self.heap[i][1] < self.heap[p][1]:
			# Swap node and its parent
			self.ind[self.heap[i][0]] = p
			self.ind[self.heap[p][0]] = i
			self.nodeSwapper(i, p)

			# Update node and parent index
			i = p
			p = self.parent(i)

	# Insert Key - Inserts v, dist[v] in Queue
	def push(self, v, d):
		self.heap.append([v, d])
		self.ind.append(v)


# Class representing Graph as a Adjacency list
class Graph:
	def __init__(self, V):
		self.V = V
		self.graph = defaultdict(list)

	# Adds an Edge to graph
	def addEdge(self, u, v, w):
		self.graph[u].append([v, w])
		# Uncomment on undirected graph
		self.graph[v].append([u, w])

	# Dijkstra's Shortest Path Algorithm - O(ElogV)
	def dijkstra(self, s):
		dist = [float("inf")] * self.V # Storing min dist
		parent = [None] * self.V # Tracing out path
		Q = Queue()

		# Initialize
		for v in range(self.V):
			Q.push(v, dist[v])
		Q.ind[s] = s
		# Set distance of source 0 such that it gets extracted from Queue
		dist[s] = 0
		parent[s] = s
		Q.decreaseKey(s, dist[s])
		Q.heapSize = self.V # Length of Queue

		# Traverse through the graph - 
		# Greedy Approach to figure out shortest distance
		while not Q.isEmpty():
			# Extract vertex with min dist value
			# If we are interested only in shortest distance from source to a single target,
			# we can break the for loop when the picked minimum distance vertex is equal to target.
			u = Q.extractMin()

			# Traverse adjacent vertices of u and relax them if necessary
			for v, w in self.graph[u]:
				if Q.isInQueue(v) and dist[u] != float("inf") and dist[v] > dist[u] + w:
					# Relax the vertex
					dist[v] = dist[u] + w
					parent[v] = u
					#Update dist value in Queue
					Q.decreaseKey(v, dist[v])

		# Display the shortest distances
		self.showDistances(dist)

	# Utility Function - Displays shortest distances
	def showDistances(self, dist):
		print("Vertex\t\tDistance from Source")
		for v in range(self.V):
			print("{}\t\t{}".format(v, dist[v]))

def main():
	g = Graph(9) 
	g.addEdge(0, 1, 4) 
	g.addEdge(0, 7, 8) 
	g.addEdge(1, 2, 8) 
	g.addEdge(1, 7, 11) 
	g.addEdge(2, 3, 7) 
	g.addEdge(2, 8, 2) 
	g.addEdge(2, 5, 4) 
	g.addEdge(3, 4, 9) 
	g.addEdge(3, 5, 14) 
	g.addEdge(4, 5, 10) 
	g.addEdge(5, 6, 2) 
	g.addEdge(6, 7, 1) 
	g.addEdge(6, 8, 6) 
	g.addEdge(7, 8, 7)

	s = 0
	print("Dijkstra's Algorithm")
	print("Chosen source", s) 
	g.dijkstra(s) 

if __name__ == '__main__':
	main()













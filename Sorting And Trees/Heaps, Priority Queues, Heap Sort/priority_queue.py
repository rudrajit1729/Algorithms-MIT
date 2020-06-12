# Priority Queue - Min Heap implementation
# Author - rudrajit1729

# Python has inbuilt library for these operations
from heapq import heappush, heappop, heapify

'''
heappop - pop and return smallest element from heap
heappush - push the value item onto the heap, maintaining heap invarient
heapify - transform list into heap, in place - linear time
'''

# Class for representing priority queue
class MinHeap:
	def __init__(self):
		self.heap = []

	# Parent of node i
	def parent(self, i):
		return (i-1)//2

	# Insert
	def insertKey(self, k):
		heappush(self.heap, k)

	# Decrease key - Decrease value of key at index i to new val
	def decreaseKey(self, i, v):
		self.heap[i] = v
		while(i!=0 and self.heap[self.parent(i)] > self.heap[i]):
			# Swap heap[i] with its parent
			self.heap[i], self.heap[self.parent(i)] = self.heap[self.parent(i)], self.heap[i]

	# Extract min - removes minimum element from heap and returns to caller function
	def extractMin(self):
		return heappop(self.heap)

	# Delete key - Deletes key at index i 
	def deleteKey(self, i):
		self.decreaseKey(i, float("-inf"))
		self.extractMin()

	# Get min - returns the minimum element in heap
	def getMin(self):
		return self.heap[0]

def main():
	heap = MinHeap()
	heap.insertKey(3)
	heap.insertKey(2)
	heap.deleteKey(1)
	heap.insertKey(15)
	heap.insertKey(5)
	heap.insertKey(4)
	heap.insertKey(45)

	print(heap.extractMin())
	print(heap.getMin())
	heap.decreaseKey(2, 1)
	print(heap.getMin())

if __name__ == '__main__':
	main()






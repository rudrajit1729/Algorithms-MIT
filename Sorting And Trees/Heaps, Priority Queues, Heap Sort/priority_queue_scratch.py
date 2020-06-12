# Priority Queue - Min Heap implementation
# Author - rudrajit1729

# Class for representing priority queue
class Heap:
	def __init__(self):
		self.heap = []

	# Parent of node i
	def parent(self, i):
		return (i-1)//2

	# Insert - Inserts key in heap
	def insertKey(self, k):
		self.heap.append(k)
		i = len(self.heap) - 1
		# Fix min heap property if violated
		while(i!=0 and self.heap[self.parent(i)] > self.heap[i]):
			# Swap heap[i] with its parent
			self.heap[i], self.heap[self.parent(i)] = self.heap[self.parent(i)], self.heap[i]

	# Decrease key - Decrease value of key at index i to new val
	def decreaseKey(self, i, v):
		self.heap[i] = v
		while(i!=0 and self.heap[self.parent(i)] > self.heap[i]):
			# Swap heap[i] with its parent
			self.heap[i], self.heap[self.parent(i)] = self.heap[self.parent(i)], self.heap[i]

	# Min Heapify - Function to preserve min heap structure
	def minHeapify(self, i):
		smallest = i
		left = 2 * i + 1
		right = 2 * i + 2

		if left < len(self.heap) and self.heap[left] < self.heap[smallest]:
			smallest = left

		if right < len(self.heap) and self.heap[right] < self.heap[smallest]:
			smallest = right

		if smallest != i:
			self.heap[smallest], self.heap[i] = self.heap[i], self.heap[smallest]
			self.minHeapify(smallest)

	# Extract min - Removes and returns minimum element from heap
	def extractMin(self):
		if len(self.heap) == 0:
			return None

		root = self.heap[0] # Store root

		# Replace root with maximum element
		maxChild = self.heap[-1]
		self.heap[0] = maxChild 

		# Reduce heap size and heapify
		self.heap.pop()
		self.minHeapify(0)

		return root

	# Delete key - Deletes key at index i 
	def deleteKey(self, i):
		self.decreaseKey(i, float("-inf"))
		self.extractMin()

	# Get min - returns the minimum element in heap
	def getMin(self):
		return self.heap[0]

def main():
	heap = Heap()
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





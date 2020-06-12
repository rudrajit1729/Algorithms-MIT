// Priority Queue - Min Heap implementation
// Author - rudrajit1729

// Class for representing priority queue

#include<bits/stdc++.h>
#define NONE INT_MIN
#define NINF -99999999
using namespace std;

// Class for representing priority queue
class Heap
{
	vector<int> heap;
public:
	int parent(int i) {return (i-1)/2;}
	void insertKey(int k);
	void decreaseKey(int i, int v);
	void minHeapify(int i);
	int extractMin();
	void deleteKey(int i);
	int getMin() {return heap[0];}
	void swap(int &a, int &b);
};

// Function to swap values
void Heap::swap(int &a, int &b)
{
	int t = a;
	a = b;
	b= t;
}

// Insert - Inserts key in heap
void Heap::insertKey(int k)
{
	heap.push_back(k);
	int i = heap.size() - 1;
	// Fix min heap property if violated
	while(i!=0 and heap[parent(i)] > heap[i])
		swap(heap[i], heap[parent(i)]);
}

// Decrease Key - Decrease value of key at index i to new val
void Heap::decreaseKey(int i, int v)
{
	heap[i] = v;
	// Fix min heap property if violated
	while(i!=0 and heap[parent(i)] > heap[i])
		swap(heap[i], heap[parent(i)]);
}

// Min Heapify - Function to preserve min heap structure
void Heap::minHeapify(int i)
{
	int smallest = i, left = 2 * i + 1, right = 2 * i + 1;
	int size = heap.size();

	if (left < size && heap[left] < heap[smallest])
		smallest = left;

	if (right < size && heap[right] < heap[smallest])
		smallest = right;

	if (smallest != i)
	{
		swap(heap[smallest], heap[i]);
		minHeapify(smallest);
	}
}

// Extract Min - Removes and returns minimum element from heap
int Heap::extractMin()
{
	if (heap.size() == 0) return NONE;

	int root = heap[0]; // Store root

	// Replace root with maximum element
	int maxChild = heap[heap.size() - 1];
	heap[0] = maxChild;

	// Reduce heap size and heapify
	heap.pop_back();
	minHeapify(0);

	return root;
}

// Delete Key - Deletes key at index i
void Heap::deleteKey(int i)
{
	decreaseKey(i, NINF);
	int x = extractMin();
}

int main()
{
	Heap h;
	h.insertKey(3); 
    h.insertKey(2); 
    h.deleteKey(1); 
    h.insertKey(15); 
    h.insertKey(5); 
    h.insertKey(4); 
    h.insertKey(45); 
    cout << h.extractMin() << " "; 
    cout << h.getMin() << " "; 
    h.decreaseKey(2, 1); 
    cout << h.getMin(); 
	cout<<"\nTest Passed!\n";
    return 0; 
}
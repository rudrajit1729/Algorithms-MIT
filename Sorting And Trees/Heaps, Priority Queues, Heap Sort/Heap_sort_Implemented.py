from random import randint
import heapq

def generate(n = 10, max = 50):
    l = []
    while(n>0):
        l.append(randint(0, max))
        n -= 1
    return l

def max_heapify(A, n, i):
    largest = i # root assigned as largest
    l = 2 * i + 1 # left child
    r = 2 * i + 2 # right child

    if l < n and A[largest] < A[l]: # If left node exists and is greater than root node
        largest = l # Assign left as largest so far

    if r < n and A[largest] < A[r]: # If right node exists and is greater than the largest node so far
        largest = r
    
    if largest != i: # If root is not the largest
        A[largest], A[i] = A[i], A[largest] # Make root largest by swapping value with largest node
        max_heapify(A, n, largest) # Heapify the largest node after swapping its value with root

def heapsort(A):
    n = len(A)

    # Build Max heap
    for i in range(n//2 - 1, -1, -1): #Leaves are already max/min heaps
        max_heapify(A, n, i) # Heapify non leaf nodes
    
    # Heap Sort
    for i in range(n-1, 0, -1):
        A[i], A[0] = A[0], A[i] # Swap rightmost leaf with root
        max_heapify(A, i, 0) # Heapify root after swapping
    return A

def main():
    A = generate()
    print("Original Array:\n{}".format(A))
    A = heapsort(A)
    print("Sorted Array:\n{}".format(A))

if __name__ == "__main__":
    main()


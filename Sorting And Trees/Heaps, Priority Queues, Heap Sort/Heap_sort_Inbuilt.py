from random import randint
import heapq

def generate(n = 10, max = 50):
    l = []
    while(n>0):
        l.append(randint(0, max))
        n -= 1
    return l

def heapsort(A):
    # In built functions
    # Implementation of min heap
    h = []
    for value in A:
        heapq.heappush(h, value)# Push values in heap
    return [heapq.heappop(h) for i in range(len(h))]# Pops the minimum element one after other till exhausted

def main():
    A = generate()
    print("Original Array:\n{}".format(A))
    A = heapsort(A)
    print("Sorted Array:\n{}".format(A))

if __name__ == "__main__":
    main()


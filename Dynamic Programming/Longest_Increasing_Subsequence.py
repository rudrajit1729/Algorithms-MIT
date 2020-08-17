# Longest Increasing Subsequence - DP Approach
# Author - rudrajit1729

from random import randint

def generate(n, max = 20):
    ''' Generates a list of random numbers'''
    l = []
    for _ in range(n):
        l.append(randint(1, max))
    return l

def solve(A):
    ''' returns the length of the longest subsequence'''
    n = len(A)
    DP = [] * n # Memo table to store length of the subsequences for the indices
    # Building table bottom up
    for i in range(n-1, -1, -1):
        choices = [1] # Single element always a subsequence - len = 1
        for j in range(i+1, n):
            # Iterating through the elements to the right if we find a element bigger than given element
            # We include that element to list of choices along with the length of subsequence at that position
            if A[j]>A[i]:
                choices.append(DP[j] + 1)
        DP[i] = max(choices)
    return max(DP)

def answer(A):
    n = len(A)
    # DP[i] - Longest increasing subsequence starting with A[i]
    DP = [[] for i in range (n)]

    # Iterate from index n-1
    for i in range(n-1, -1, -1):
        # Traverse through j greater than i
        for j in range(i+1, n):
            # DP[i] = max(DP[j]) + A[i]
            # j < i and A[j] < A[i]
            if A[i] < A[j] and (len(DP[i]) < len(DP[j]) + 1):
                DP[i] = DP[j].copy()
        # DP[i] starts with A[i]
        DP[i].insert(0, A[i])
        

    # DP[i] now stores increasing subsequence 
    maxx = DP[0]
    for seq in DP:
        if len(seq) > len(maxx):
            maxx = seq

    print("Subsequence : ", end = "")
    print(maxx) 
    return len(maxx) 

def main():
    A = list(map(int, input("Enter elements : ").split()))
    #A = generate(7, 10)
    print(A)
    print("Longest Common Subsequence : ")
    #print(solve(A))
    print("Length = ", answer(A))

if __name__ == "__main__":
    main()

   



def solve(A, n):
    ans = [A[0], A[0]]
    max_current = A[0]
    for i in range(1, n):
        # Subarray - Kadane
        max_current = max(A[i], max_current + A[i])
        if max_current > ans[0]:
            ans[0] = max_current
    # Subsequence
    A.sort(reverse = True)
    ans[1] = A[0]
    for i in range(1, n):
        if ans[1] + A[i] > ans[1]:
            ans[1] += A[i]
        
    return ans


#A = list(map(int, input().split()))
A = [-2, -3, -1, -4, -6]

print(solve(A, len(A)))
A = [2, -1, 2, 3, 4, -5]
print(solve(A, len(A)))

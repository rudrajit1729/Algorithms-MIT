#  Parenthesization - Matrix muliplication - DP Approach
#  Author - rudrajit1729

'''
  Input:  p[] = {40, 20, 30, 10, 30}  
  Output: Optimal parenthesization is  ((A(BC))D)
          Optimal cost of parenthesization is 26000
  There are 4 matrices of dimensions 40x20, 20x30, 30x10 and 10x30.
  Let the input 4 matrices be A, B, C and D.  The minimum number of 
  multiplications are obtained by putting parenthesis in following way
  (A(BC))D --> 20*30*10 + 40*20*10 + 40*10*30

  Input: p[] = {10, 20, 30, 40, 30} 
  Output: Optimal parenthesization is (((AB)C)D)
          Optimal cost of parenthesization is 30000
  There are 4 matrices of dimensions 10x20, 20x30, 30x40 and 40x30. 
  Let the input 4 matrices be A, B, C and D.  The minimum number of 
  multiplications are obtained by putting parenthesis in following way
  ((AB)C)D --> 10*20*30 + 10*30*40 + 10*40*30

  Input: p[] = {10, 20, 30}  
  Output: Optimal parenthesization is (AB)
          Optimal cost of parenthesization is 6000
  There are only two matrices of dimensions 10x20 and 20x30. So there 
  is only one way to multiply the matrices, cost of which is 10*20*30
'''

def printSolution(i, j, n, DP, name):
	# Base Case - Single matrix left in segment
	if i == j:
		name += i - 1
		print(chr(name), end = "")
		return

	print("(", end = "")

	# Recursively put brackets around subexpression
	# Subexpression - i to k (i.e. DP[i][j])
	printSolution(i, DP[i][j], n, DP, name)
	# Recursively put brackets around subexpression
	# Subexpression - k+1(DP[i][j] + 1) to j
	printSolution(DP[i][j] + 1, j, n, DP, name)
	
	print(")", end = "")


def solve(p):
	n = len(p)
	# Table to store cost of multiplying matrices
	# m[i][j] = cost of multiplying matrices A[i]A[i+1]...A[j]
	# Dimension of each matrix A[i] = P[i-1] x P[i]

	# Initialize
	m = [[0 for x in range(n)] for y in range(n)]
	DP = [[0 for x in range(n)] for y in range(n)] # Stores the breakpoints


	# Solving parenthesization - O(n^3)

	# Trying every substring structure
	# Starting chain length(S) = 2 
	# We already know cost for multiplying 1 matrix
	# Here after 1 iteration we would know optimal costs to multiply S matrices
	for S in range(2, n):
		# Finding out optimal ways to multiply matrices A[i...n-S+1]
		for i in range(1, n - S + 1):
			j = i + S - 1
			m[i][j] = float("inf")
			# Finding breakpoint such that cost is minimum
			for k in range(i, j):
				# Dimension of matrix A[i...k] = p[i-1] * p[k]
				# and of matrix A[k+1...j] = p[k] * p[j]
				# Cost of multiplying two matrices of order m x n, p x q= mpq
				cost = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j]
				if cost < m[i][j]:
					# Each entry DP[i, j] = k shows where to split
					# so as to get min cost for A[i...j]
					m[i][j] = cost
					DP[i][j] = k

	name = 65 # ASCII('A') - First matrix is A, next B and so on
	print("Optimal Parenthesization : ", end = "")
	printSolution(1, n - 1, n, DP, name)
	# Rightmost element on 1st row gives the cost
	# for multiplying matrices A[1...n-1] -> ans
	print()
	print(DP)
	return m[1][n-1]

def main():
	p = [40, 20, 30, 10, 30]
	# print("Enter Dimension Chain array")
	# p = list(map(int, input().split()))
	print("Optimal Cost : ", str(solve(p)))

if __name__ == '__main__':
	main()
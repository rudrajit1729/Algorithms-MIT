# Longest Common Subsequence - DP Approach
# Using Edit Distance
# Author - rudrajit1729

# Description 
'''
 Given two sequences, find the length of longest subsequence present in both of them.
 A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
 For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.

> Insert - Cost(1)
> Remove - Cost(1)
> Replace - Cost(INF)
'''

def getmaximum(a, b):
	# a = DP[i][j-1], b = DP[i-1][j]
	if a > b:
		return (a, 0)
	else:
		return (b, 1)

def solve(x, y):
	m, n = len(x), len(y)

	# Create a table to store topological order
	DP = [[0 for x in range(n+1)] for y in range(m+1)]

	# Bottom up - Left to right approach
	# Solving using prefixes
	for i in range(m + 1):
		for j in range(n + 1):

			# Base Cases 
			# If either string is empty, len of sequence is 0
			if i == 0 or j == 0:
				DP[i][j] = 0

			# If characters are same, add 1 to length of sequence
			elif x[i-1] == y[j-1]:
				DP[i][j] = DP[i-1][j-1] + 1

			# If last character is different, consider all possibilities
			# and find maximum length
			else:
				DP[i][j] = max(DP[i][j-1], DP[i-1][j])

	# return DP[m][n]

	# Now that we have the table we need to find the sequence
	sol = "" # Stores solution
	i, j = m, n # Index for traversal
	val = DP[i][j]

	while val != 0: # Traverse till one of strings get exhausted
		# Get maximum of left and top cell
		v, flag = getmaximum(DP[i][j-1], DP[i-1][j])
		if val == v: # If value at [i, j] = v -> move to that position
			if flag == 0: # move left
				j -= 1
			else: # Move up
				i -= 1
		else: # Not one of the values -> The character is in string
			# Append that character and move diagonally up
			sol = x[i - 1] + sol
			i, j = i-1, j-1
		
		val = DP[i][j]

	return sol 



def main():
	x, y = input("Enter String 1 : "), input("Enter String 2 : ")
	#x, y = "CAT", "MAT"
	ans = solve(x, y)
	print("Longest subsequence : {}\nLength of Subsequence : {}".format(ans, len(ans)))

if __name__ == '__main__':
	main()
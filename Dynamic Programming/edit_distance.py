# Edit Distance - DP Approach
# Author - rudrajit1729

# Description 
'''
Given two strings x and y and below operations that can performed on x.
Find minimum number of edits (operations) required to convert x into y.

> Insert
> Remove
> Replace
All of the above operations are of equal cost.
Here we take cost as 1
'''

def solve(x, y):
	m, n = len(x), len(y)

	# Create a table to store topological order
	DP = [[0 for x in range(n+1)] for y in range(m+1)]

	# Bottom up - Left to right approach
	# Solving using prefixes
	for i in range(m + 1):
		for j in range(n + 1):

			# Base Cases 
			# If first string is empty, only option is to
			# insert all characters of second string
			if i == 0:
				DP[i][j] = j	# Min. no. of operations = j
			# If second string is empty only option is to
			# remove all characters of second string
			elif j == 0:
				DP[i][j] = i 	# Min. no. of operations = i

			# If characters are same, ignore them and recurse for remaining
			elif x[i-1] == y[j-1]:
				DP[i][j] = DP[i-1][j-1]

			# If last character is different, consider all possibilities
			# and find minimum
			else:
				# Cost of insert, delete, replace are same = 1
				DP[i][j] = 1 + min(DP[i-1][j-1], DP[i][j-1], DP[i-1][j])

	return DP[m][n]

def main():
	x, y = input("Enter String 1 : "), input("Enter String 2 : ")
	#x, y = "CAT", "MAT"
	print("Minimum operations : ", str(solve(x, y)))

if __name__ == '__main__':
	main()
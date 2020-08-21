# Unique Coin Change Ways - DP Approach
# Author - rudrajit1729

# Given an amount and collection of coins
# find the total number of unique ways for change
# amt = 5, coins = [1, 2, 5]
# Unique ways - 4 - [1, 1, 1, 1, 1], [1, 1, 1, 2], [1, 2, 2], [5]
# 1+1+1+1+1 = 5, 2+2+1 = 5, 5 = 5, 2+1+1+1 = 5

# Explanation - https://www.youtube.com/watch?v=DJ4a7cmjZY0

def solve(coins, n, amt):
	'''
	coins - collection of coins
	n - number of available coin choices
	amt - amt required
	'''

	DP = [[0 for x in range(amt+1)] for x in range(n+1)]
	DP[0][0] = 1

	for row in range(1, n+1):
		for col in range(amt+1):
			# Base Case - Always possible to break coin when amt = 0
			if col == 0:
				DP[row][col] = 1

			else:
				if col >= coins[row-1]:
					DP[row][col] = DP[row-1][col] + DP[row][col-coins[row-1]]
				else:
					DP[row][col] = DP[row-1][col]

	return DP[n][amt]

coins = [1, 2, 5]
amt = 5
print(solve(coins, len(coins), amt))




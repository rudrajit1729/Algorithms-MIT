# Knapsack (0 - 1) - DP Approach
# Author - rudrajit1729

def knapSack(S, n, values, weights):
	# DP Table to maintain maximum values for given capacity
	DP = [[0 for x in range(S + 1)] for x in range(n + 1)]

	# Build up table in bottomn up manner
	for i in range(n + 1):
		# X <= S -> Remaining Capacity
		for X in range(S + 1):
			# If remaining items or sack size is 0 
			if i == 0 or X == 0:
				DP[i][X] = 0
			elif weights[i-1] <= X:
				DP[i][X] = max(values[i-1] + DP[i-1][X - weights[i-1]], # Included the item
							DP[i-1][X]	# Not included item
							)
			else:
				DP[i][X] = DP[i-1][X]

	# Store the result of the knapsack
	res = DP[n][S]
	print("Maximum value : ", res)

	X = S
	result = []
	for i in range(n, 0, -1):
		# If res 0 i.e. if nothing could be packed
		if res <= 0:
			break

		# Now if res is non zero it has come from either
		# Upper block DP[i-1][X] or from DP[i-1][X - weights[i-1]] + values[i]
		# If it comes from later one it implies we have taken that item
		# Add that item and reduce Size

		if res == DP[i-1][X]:
			continue
		else:
			#Item included
			result.append((weights[i-1], values[i-1]))
			# As weight is included its value is deducted
			res = res - values[i-1]
			X = X - weights[i-1]

	return result

def main():
	values = list(map(int, input("Enter values : ").split()))
	weights = list(map(int, input("Enter weights : ").split()))
	S = int(input("Enter Size of Sack :"))
	#values = [60, 100, 120]
	#weights = [10, 20, 30]
	#S = 50
	n = len(values)
	print()
	result = knapSack(S, n, values, weights)
	print("\nList of items : \nWeights\t\tValues")
	for w, v in result:
		print("{}\t\t{}".format(w, v))


if __name__ == '__main__':
	main()


# Interval Scheduling - Greedy Approach
# Author - rudrajit1729

def solve(S):
	# Sort based on earliest finishing time
	S.sort(key = lambda x:x[1])
	n = len(S) # Length of the schedule
	i = 0
	print(S[i]) # First activity is always selected
	# Iterating through the rest of the activities
	for j in range(n):
		# If start time >= Finish time of the ith selected activity - Select the activity
		# Move i to the position
		if S[j][0] >= S[i][1]:
			print(S[j])
			i = j
	
def main():
	#S = [(1, 3), (2, 5), (4, 6)]
	#S = [(10, 20), (12, 25), (20, 30)]
	S = [(1, 2), (3, 4), (0, 6), (5, 7), (8, 9), (5, 9)]
	solve(S)

if __name__ == '__main__':
	main()
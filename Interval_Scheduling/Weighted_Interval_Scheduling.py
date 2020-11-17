# Weighted Interval Scheduling - DP Approach
# Author - rudrajit1729

def latestNonConflict(intervals, index):
	# Binary Search Based Function to find the latest interval
	# (before current interval) that doesn't conflict with current interval
	# index is position of current selected interval
	# intervals - array of interval having [start, finish, weight]
	# returns -1 if all intervals conflict
	lb, ub = 0, index - 1
	while(lb <= ub):
		mid = (lb + ub) // 2
		if intervals[mid][1] <= intervals[index][0]:
			if intervals[mid+1][1] <= intervals[index][0]:
				lb = mid + 1
			else:
				return mid
		else:
			ub = mid - 1
	return -1


def OptInterval(A, n):
	# Finds subset of intervals associated with max weight such that
	# no two intervals overlap
	# A - list of intervals where each interval has [start, finish, weight]

	# Sort intervals acc to earliest finish time
	A.sort(key = lambda x:x[1])

	# List of [maxweight, list of intervals ending at A[i] i.e. A[0....i]]
	# Stores solutions of subproblems
	# DP[i] stored intervals involved and their total weight till A[i](included)
	DP = [[0, []] for i in range(n)]

	# Initialize DP[0] to A[0]
	DP[0][0] = A[0][2]
	DP[0][1].append(A[0])

	# Fill entries in DP[] using recursive property
	for i in range(1, n):
		# Find weight including the current interval
		inclWeight = A[i][2]
		l = latestNonConflict(A, i)
		if l != -1:
			inclWeight += DP[l][0]

		# Store maximum of including and excluding
		if inclWeight > DP[i-1][0]:
			DP[i][0] = inclWeight
			# Including prev and current intervals
			DP[i][1] = DP[l][1].copy()
			DP[i][1].append(A[i])
		
		else:
			# Excluding the current interval
			DP[i] = DP[i-1].copy()

	# DP[n-1] stores the result
	print("Optimum Intervals for maximum weights")
	for interval in (DP[n-1][1]):
		print(interval)
	print("Total Optimum weight : ", DP[n-1][0])

def main():
	Intervals = [[3, 5, 20], [1, 2, 50], [6, 19, 100], [2, 100, 200]]
	n = len(Intervals)
	OptInterval(Intervals, n)

if __name__ == '__main__':
	main()



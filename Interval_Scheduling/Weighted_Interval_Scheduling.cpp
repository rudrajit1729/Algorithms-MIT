// Weighted Interval Scheduling - DP Approach
// Author - rudrajit1729

#include<bits/stdc++.h>
using namespace std;

// An Interval has start time, finish time, and weight
struct Interval
{
	int start, finish, weight;
};

// Storing subset of current intervals
struct weightedInterval
{
	// vector of intervals
	vector<Interval> interval;
	// find weight associated with included intervals
	int value;
};

// Utility function to sort events according to finish time
bool Comparator(Interval i1, Interval i2)
{
	return (i1.finish < i2.finish);
}

// A Binary Search based function to find the latest interval 
// (before current interval) that doesn't conflict with current interval
// index is the position of the current selected activity
// returns -1 if all intervals conflict
int latestNonConflict(Interval intervals[], int index)
{
	int lb = 0, ub = index - 1;

	while(lb <= ub)
	{
		int mid = (lb + ub) / 2;
		if(intervals[mid].finish <= intervals[index].start)
		{
			if(intervals[mid+1].finish <= intervals[index].start)
				lb = mid + 1;
		
			else 
				return mid;
		}
		else
			ub = mid - 1;
	}
	return -1;
}

// Finds subset of intervals associated with max weight such that 
// no two intervals overlap
int findOptInterval(Interval ar[], int n)
{
	// Sort intervals acc to earliest finish time
	sort(ar, ar+n, Comparator);

	// Create an array to store solutions of subproblems
	// DP[i] stored intervals involved and their total weight
	// till ar[i](included)
	weightedInterval DP[n];

	// Initialize DP[0] to ar[0]
	DP[0].value = ar[0].weight;
	DP[0].interval.push_back(ar[0]);

	// Fill entries in DP[] using recursive property
	for(int i = 1; i < n; i++)
	{
		// Find weight including the current interval
		int inclWeight = ar[i].weight;
		int l = latestNonConflict(ar, i);
		if(l != -1)
			inclWeight += DP[l].value;

		// Store maximum of including and excluding 
		if(inclWeight > DP[i-1].value)
		{
			DP[i].value = inclWeight;

			// Including prev and current intervals
			DP[i].interval = DP[l].interval;
			DP[i].interval.push_back(ar[i]);
		}
		else 
			// Excluding the current interval
			DP[i] = DP[i-1];
	}
	// DP[n-1] stores the result
	cout<<"Optimal Jobs for maximum profits are\n";
	for(int i = 0; i < DP[n-1].interval.size(); i++)
	{
		Interval interval = DP[n-1].interval[i];
		cout<<"("<<interval.start<<", "<<interval.finish<<", "
			<<", "<<interval.weight<<")\n";
	}
	cout<<"\nTotal Optimum weight : "<<DP[n-1].value<<endl;
}

int main()
{
	Interval ar[] = {{3, 5, 20}, {1, 2, 50}, {6, 19, 100}, 
		{2, 100, 200} }; 
	int n = sizeof(ar)/sizeof(ar[0]);
	findOptInterval(ar, n);
}
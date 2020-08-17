// Longest Common Subsequence - DP Approach
// Using Edit Distance
// Author - rudrajit1729

// Description 
/*
 Given two sequences, find the length of longest subsequence present in both of them.
 A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.
 For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.

> Insert - Cost(1)
> Remove - Cost(1)
> Replace - Cost(INF)
*/

#include<bits/stdc++.h>
using namespace std;

string solve(string x, string y)
{
	int m = x.size(), n = y.size();
	// Create a table to store topological order
	int DP[m+1][n+1];
	for(int i = 0; i <= m; i++)
	{
		for(int j = 0; j <= n; j++)
		{
			// Base Cases
			// If either string is empty size of subsequence = 0
			if(i == 0 || j == 0)
				DP[i][j] = 0;
			// If characters are same, add 1 to length of subsequence
			else if (x[i-1] == y[i-1])
				DP[i][j] = DP[i-1][j-1] + 1;
			// If last character is different, consider all possibilities
			// and find maximum length
			else
				DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
		}
	}

	// Now that we have the table we need to find the sequence
	int val = DP[m][n], i = m, j = n;
	string sol = "";

	while(val != 0)
	{
		// Get maximum of left and top cell
		int v = DP[i][j-1], flag = 0;
		if (DP[i-1][j] > v)
		{
			v = DP[i-1][j];
			flag = 1;
		}
		// If value at [i, j] = v -> move to that position
		if (val == v)
		{
			if (flag == 0) // Move left
				j -= 1;
			else	// Move up
				i -=1;
		}
		// Not one of the values -> The character is in string
		// Append that character and move diagonally up
		else
		{
			sol = x[i-1] + sol;
			i = i - 1, j = j - 1;
		}
		val = DP[i][j];
	}
	return sol;

}

int main()
{
	string x; 
	string y; 
	cout<<"Enter string 1 : ";
	cin>>x;
	cout<<"Enter string 2 : ";
	cin>>y;
	string res = solve(x, y);
	cout << "Longest Subsequence : "<<res<<endl;
	cout << "Length of Subsequence : "<<res.size()<<endl; 
}
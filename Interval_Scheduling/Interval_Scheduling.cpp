// Interval Scheduling - Greedy Approach
// Author - rudrajit1729

#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

// Driver function to sort the vector elements by second element of pairs 
bool sortbysec(const pair<int,int> &a, 
              const pair<int,int> &b) 
{ 
    return (a.second < b.second); 
} 

void solve(vector<pair<int, int>> S)
{
	int n = S.size(), i = 0;
	
    // Using sort() function to sort by 2nd element of pair 
    // Sort based on earliest finishing time
	sort(S.begin(), S.end(), sortbysec);

	cout<<"("<<S[i].first<<" "<<S[i].second<<")"<<endl; // First activity is always selected
	// Iterating through the rest of the activities
	for(int j = 0; j < n; j++)
	{
		// If start time >= Finish time of the ith selected activity - Select the activity
		// Move i to the position
		if (S[j].first >= S[i].second)
		{
			cout<<"("<<S[j].first<<" "<<S[j].second<<")"<<endl;
			i = j;
		}
	}
}

int main()
{
	// vector<pair<int, int>>S = {{1, 3}, {2, 5}, {4, 6}};
	// vector<pair<int, int>>S = {{10, 20}, {12, 25}, {20, 30}};
	vector<pair<int, int>>S = {{1, 2}, {3, 4},  {5, 7}, {0, 6}, {8, 9}, {5, 9}};
	solve(S);
}


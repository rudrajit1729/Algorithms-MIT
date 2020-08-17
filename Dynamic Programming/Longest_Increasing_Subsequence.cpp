// Longest Increasing Subsequence - DP Approach
// Author - rudrajit1729

#include<bits/stdc++.h>
using namespace std;

void generate(int A[], int n, int max = 20)
{
    // Generates a list of random numbers
    for(int i = 0; i < n; i++)
    {
        A[i] = rand()%max + 1;
    }
}

int solve(int A[], int n)
{
    // returns the length of the longest subsequence
    int DP[n]; // Memo table to store length of the subsequences for the indices
    // Building table bottom up
    for(int i = n-1; i>=0; i--)
    {
        vector<int>choices;
        choices.push_back(1); // Single element always a subsequence - len = 1
        for(int j = i+1; j < n; j++)
        {
            // Iterating through the elements to the right if we find a element bigger than given element
            // We include that element to list of choices along with the length of subsequence at that position
            if (A[j] > A[i]) choices.push_back(DP[j] + 1);
        }
        DP[i] = *max_element(choices.begin(), choices.end());
    }
    return *max_element(DP, DP + n);
}

void printsol(vector<int> ans, int n)
{
    // Utility to print the solution
    cout<<" (";
    for(int i = n-1; i > 0; i--)
    cout<<ans[i]<<", ";
    cout<<ans[0]<<")\n";
}

int answer(int A[], int n)
{
    // DP[i] - Longest increasing subsequence ending with A[i]
    vector<vector<int>> DP(n);
    // Iterate from index n-1
    for(int i = n-1; i >=0; i--)
    {
        // Traverse through j greater than i
        for(int j = i + 1; j < n; j++)
        {
            //  DP[i] = max(DP[j]) + A[i]
            //  j < i and A[j] < A[i]
            if(A[i] < A[j] && (DP[i].size() < DP[j].size() + 1))
                DP[i] = DP[j];
        }
        // DP[i] starts with A[i]
        DP[i].push_back(A[i]);
    }
    // Maximum subsequence now printed. DP[i] now stores increasing subsequence 
    vector<int> max = DP[0];
    for(vector<int> x:DP)
    {
        if (x.size() > max.size())
            max = x;
    }
    cout<<"Subsequence :";
    printsol(max, max.size());
    return max.size();
}

int main()
{
    srand(time(NULL));
    int n;
    cout << "Enter number of elements : ";
    cin >> n;
    int A[n];
    // generate(A, n);
    cout<<"Enter elements : ";
    for(int i = 0; i < n; i++)
        cin >> A[i];

    // cout<<"Longest Common Subsequence"<< solve(A, n);
    cout<<"Longest Common Subsequence : "<<endl;
    cout<<"Length of Subsequence : "<<answer(A, n);
}



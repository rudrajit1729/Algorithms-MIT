#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

void generate(vector<vector<int>> &A, int n = 10, int m = 10, int max = 1000)
{
    for(int i = 0;i < n; i++)
    {
        vector<int> B;
        for(int j = 0; j< m; j++)
            B.push_back(rand()%(max+1));
        A.push_back(B);
    }   
}

void solve(vector<vector<int>> & A, int n, int m)
{
    int lb = 0, ub = m - 1;
    int pos, max, j;
    while(lb <= ub)
    {
        // Finding global max at column - O(n)
        j = (lb + ub) / 2;
        max = A[0][j];
        pos = 0;
        for (int i = 1; i < n; i++)
        {
            if (A[i][j] > max)
            {
                max = A[i][j];
                pos = i;
            }
        }
        // global at (pos, j)
        if (A[pos][j]<A[pos][j-1])
            ub = j - 1;
        else if (A[pos][j]<A[pos][j+1])
            lb = j + 1;
        else
        {
            break;
        }      
    }
    cout<<"-----------------------Result------------------------\n";
    cout<<"Value : "<<A[pos][j]<<" row : "<<pos+1<<" col : "<<j+1<<endl;
    cout<<"-----------------------------------------------------\n";
}

void print_matrix(vector<vector<int>> & A)
{
    for(int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < A[0].size(); j++)
            cout<<A[i][j]<<"\t";
        cout<<endl;
    }
}

int main()
{
    srand(time(NULL));
    int n = 10,m = 10, max = 1000;
    //cin>>n>>m>>max;
    vector<vector<int>> A;
    generate(A);
    cout<<"matrix:\n";
    print_matrix(A);
    int result[3] = {0, 0, 0};
    solve(A, n, m);
}

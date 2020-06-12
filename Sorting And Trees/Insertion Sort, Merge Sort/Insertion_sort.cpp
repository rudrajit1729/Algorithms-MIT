#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>
using namespace std;

void generate(vector<int> &A, int n = 10, int max = 50)
{
    for (int i = 0; i < n; i++)
    {
        A.push_back(rand()%(max+1));
    }
    
}

void print_vector(vector<int> &A)
{
    for (int x: A)
        cout<<x<<"\t";
    cout<<endl;
}

void insertion_sort(vector<int> &A)
{
    int d;
    for(int i = 1; i < A.size(); i++)
    {
        d = i;
        while(d>0)
        {
            if (A[d]<A[d-1])
            {
                A[d] = A[d]^A[d-1];
                A[d-1] = A[d]^A[d-1];
                A[d] = A[d]^A[d-1];
            }
            d--;
        }
    }
}

int main()
{
    srand(time(NULL));
    vector<int> A;
    int n, max;
    //cin>>n>>max;
    generate(A);
    cout<<"Original Array:\n\n";
    print_vector(A);
    insertion_sort(A);
    cout<<"Sorted Array:\n\n";
    print_vector(A);
       
}
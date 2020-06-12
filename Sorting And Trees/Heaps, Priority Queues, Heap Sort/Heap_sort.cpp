#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;


void generate(vector<int> &A, int n = 10, int max = 50)
{
    for (int i = 0; i < n; i++)
        A.push_back(rand()%(max+1));
}

void print_vector(vector<int> &A)
{
    for(int x : A)
        cout<< x << "\t";
    cout<<endl;
}

void max_heapify(vector<int> &A, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && A[largest] < A[l])
        largest = l;
    if (r < n && A[largest] < A[r])
        largest = r;
    
    if (largest != i)
    {
        A[largest] = A[largest] ^ A[i];
        A[i] = A[largest] ^ A[i];
        A[largest] = A[largest] ^ A[i];
        max_heapify(A, n, largest);
    }
}

void heapsort(vector<int> & A)
{
    int n = A.size();
    for (int i = n/2 - 1; i >= 0; i--)
        max_heapify(A, n, i);
    
    for(int i = n-1; i > 0; i--)
    {
        A[i] = A[i] ^ A[0];
        A[0] = A[i] ^ A[0];
        A[i] = A[i] ^ A[0];

        max_heapify(A, i, 0);
    }
}

int main()
{
    srand(time(NULL));
    vector<int> A;
    generate(A);
    cout<<"Original Array:\n";
    print_vector(A);
    heapsort(A);
    cout<<"Sorted Array:\n";
    print_vector(A);
}

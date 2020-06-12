#include<iostream>
#include<bits/stdc++.h>
#include<ctime>
#include<cstdlib>
using namespace std;

int generate(vector<int> &A)
{
    int size = rand()%251;

    for(int i = 0; i < size; i++)
        A.push_back(rand()%1000);
    return size;
}

void print_vector(vector<int> &A)
{
    for(int x:A)
        cout<<x<<",";
    cout<<endl;
}

int peak(vector<int> &A, int lb, int ub)
{
    while(lb<=ub)
    {
      int mid = (lb+ub)/2;
      if(A[mid]<A[mid-1])
        ub = mid-1; 
      else if (A[mid]<A[mid+1])
        lb = mid+1;
      else
        return mid; 
    }
    
}

int main()
{
    srand(time(NULL));
    vector<int> A;
    int size = generate(A);
    cout<<size<<endl;
    print_vector(A);
    cout<<"-----------------------Result---------------------------\n";
    int pos = peak(A, 0, size-1);
    if (pos>0 && pos<size-1)
    cout<<"\n"<<"Position : "<<pos<<"\tValue : "<<A[pos]<<"\tVisualize area : ["<<A[pos-1]<<" "<<A[pos]<<" "<<A[pos+1]<<"]\n";
    else if (pos==0)
    cout<<"\n"<<"Position : "<<pos<<"\tValue : "<<A[pos]<<"\tVisualize area : ["<<A[pos]<<" "<<A[pos+1]<<"]\n";
    else if (pos == size-1)
    cout<<"\n"<<"Position : "<<pos<<"\tValue : "<<A[pos]<<"\tVisualize area : ["<<A[pos-1]<<" "<<A[pos]<<"]\n";
    cout<<"---------------------------------------------------------\n";

}
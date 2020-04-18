//To print the kth largest element in the stream
#include<bits/stdc++.h>
using namespace std;
void kLargest(int a[],int n,int k)
{
    //Construct a min heap
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<n;i++)
    {
        q.push(a[i]);
        if(q.size()>k)
        q.pop();
    }
    cout<<q.top();
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int k;
    cin>>k;
    kLargest(a,n,k);
}

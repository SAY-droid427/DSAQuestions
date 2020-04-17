//Program to print the largest k numbers
#include<bits/stdc++.h>
using namespace std;
void largestK(int a[],int n,int k)
{
    //We construct a min heap
    priority_queue<int,vector<int>,greater<int>> q;
    for(int i=0;i<n;i++)
    {
        q.push(a[i]);
        if(q.size()>k)
        q.pop();
    }
    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
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
    largestK(a,n,k);
    return 0;
}

//Program to find the K closest elements to a number m
#include<bits/stdc++.h>
using namespace std;
void ClosestToK(int a[],int n,int k,int m)
{
    priority_queue<pair<int,int>> q;
    for(int i=0;i<k;i++)
    {
        q.push({abs(m-a[i]),a[i]});
        if(q.size()>k)
        q.pop();
    }
    while(!q.empty())
    {
        cout<<q.top().second<<"\n";
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
    int k;//Number of closest elements required
    cin>>k;
    int m;//Number pivot
    cin>>m;
    ClosestToK(a,n,k,m);
    return 0;
}

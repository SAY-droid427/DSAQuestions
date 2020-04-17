//Program to print the top k  frquent element
#include<bits/stdc++.h>
using namespace std;
void TopKFreq(int a[],int n,int k)
{
    //We map each element with its frequency
    unordered_map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        mp[a[i]]++;

    }
    //We construct min heap of pairs
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    unordered_map<int,int>::iterator itr;
    for(auto itr=mp.begin();itr!=mp.end();itr++)
    {
        q.push({itr->second,itr->first});
        if(q.size()>k)
        q.pop();
    }
    while(!q.empty())
    {
        cout<<q.top().second<<"-->"<<q.top().first<<"\n";
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
    TopKFreq(a,n,k);
    return 0;
}

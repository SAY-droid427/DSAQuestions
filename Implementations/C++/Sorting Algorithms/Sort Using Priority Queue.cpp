//Sorting using a priority queue
#include<bits/stdc++.h>
using namespace std;
void sortUsingQueuesDescending(int a[],int n)
{
    priority_queue<int> q;
    for(int i=0;i<n;i++)
    q.push(a[i]);
    //Printing in descending order
    while(!q.empty())
    {
        cout<<q.top()<<" ";
        q.pop();
    }
    cout<<"\n";
}
void sortUsingQueuesAscending(int a[],int n)
{
    priority_queue<int,vector<int>,greater<int>> p;
     for(int i=0;i<n;i++)
    p.push(a[i]);
    //Printing in ascending order
    while(!p.empty())
    {
        cout<<p.top()<<" ";
        p.pop();
    }
    cout<<"\n";
    
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    cout<<"Sorting in the descending order\n";
    sortUsingQueuesDescending(a,n);
    cout<<"Sorting in the ascending order\n";
    sortUsingQueuesAscending(a,n);
    return 0;
}

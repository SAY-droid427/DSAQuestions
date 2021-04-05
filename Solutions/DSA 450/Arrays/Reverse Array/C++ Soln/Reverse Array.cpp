#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int>& v, int start, int end)
{
    if(start >= end)
        return;
    
    int temp = v[start];
    v[start] = v[end];
    v[end] = temp;

    reverse(v, start+1, end - 1);
}

//Driver Code
int main()
{
    int n;
    vector<int>v;
    
    int x;
    cin>>n;
    for(int i = 0; i<n ; i++)
    {
        cin>>x;
        v.push_back(x);
    }

    reverse(v, 0, n-1);

    for(auto& x : v)
        cout<<x<<" ";
        
return 0;    

}

/* 
Contribution By
Author Name : Dwaipayan Munshi
Contribution Date : 05.04.2021
*/
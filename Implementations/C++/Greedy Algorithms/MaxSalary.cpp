//Maximum salary that can be made with two digit numbers
#include<bits/stdc++.h>
using namespace std;
void MaxSalary(int a[],int n)
{
    vector<pair<int,int>> v;
    for(int i=0;i<n;i++)
    {
        v.push_back({a[i]%100,a[i]});
    }
    sort(v.begin(),v.end());
    for(int i=n-1;i>=0;i--)
    cout<<v[i].second;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    MaxSalary(a,n);
    return 0;

    

}

//Maximum revenue
#include<bits/stdc++.h>
using namespace std;
void MaxRev(int a[],int b[],int n)
{
    sort(a,a+n);
    sort(b,b+n);
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=a[i]*b[i];
    }
    cout<<sum<<"\n";
}
int main()
{
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    for(int i=0;i<n;i++)
    cin>>b[i];
    MaxRev(a,b,n);
    return 0;
}

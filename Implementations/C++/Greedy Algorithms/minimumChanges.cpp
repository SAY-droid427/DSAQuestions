//Minimum number of coins required for the change
#include<bits/stdc++.h>
using namespace std;
void Change(int a[],int n,int money)
{
    int count=0;
    sort(a,a+n);
    int i=n-1;
    while(money!=0)
    {

        if(money>=a[i])
        {
            money=money-a[i];
            count++;//Increasing the count of the number of coins needed
        }
        else 
        i--;
    }
    cout<<count<<"\n";
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int money;
    cin>>money;
    Change(a,n,money);
    return 0;
}

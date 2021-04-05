//Prints the number of subarrays having the given sum
#include<bits/stdc++.h>
using namespace std;
int subsetSum(int a[],int sum,int n)
{
    int t[n+1][sum+1];

    /*
      If the no. of numbers given is zero, then the no. of subarrays with non-zero sum will be zero
      If the sum is zero, then the no. of subarrays will be 1
    */
   for(int i=0;i<n+1;i++)
   t[i][0]=1;
   for(int j=0;j<sum+1;j++)
   t[0][j]=0;
   for(int i=1;i<n+1;i++)
   {
       for(int j=1;j<sum+1;j++)
       {
           if(a[i-1]<=j)
           t[i][j]=t[i-1][j-a[i-1]]||t[i-1][j];
           if(a[i-1]>j)
           t[i][j]=t[i-1][j];
       }
   }
   return t[n][sum];
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    int sum;
    cin>>sum;
    cout<<subsetSum(a,sum,n)<<"\n";
}

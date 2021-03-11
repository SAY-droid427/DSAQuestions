//Longest common subsequence in three strings
#include<bits/stdc++.h>
using namespace std;
int lcs(string x,string y,string z)
{
    int m=x.length();
    int n=y.length();
    int l=z.length();
    int t[m+1][n+1][l+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<m+1;j++)
        {
            for(int k=0;k<l+1;k++)
            {
                if(i==0 ||j==0 ||k==0)
                t[i][j][k]=0;
            }
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<m+1;j++)
        {
            for(int k=1;k<l+1;k++)
            {
                if(x[i-1]==y[j-1] && y[j-1]==z[k-1])
                t[i][j][k]=1+t[i-1][j-1][k-1];
                else
                t[i][j][k]=max(t[i-1][j][k],max(t[i][j-1][k],t[i][j][k-1]));
            }
        }
    }
    return t[n][m][l];
}
int main()
{
    string x,y,z;
    cin>>x>>y>>z;
    cout<<lcs(x,y,z)<<"\n";   
}
/*
INPUT:
abcdef
abcdg
adch
OUTPUT:
2
*/

//SelectionSort
#include<bits/stdc++.h>
using namespace std;
void selectionSort(int a[],int n)
{
    int i,j,pos,min;
    for(int i=0;i<n;i++)
    {
        min=a[i];pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(min>a[j])
            {
                min=a[j];
                pos=j;
            }

        }
        int temp=a[i];
        a[i]=a[pos];
        a[pos]=temp;
    }
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
}

int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    selectionSort(a,n);
    return 0;

}

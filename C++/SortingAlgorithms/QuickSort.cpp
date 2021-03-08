//QuickSort Algorithms
#include<bits/stdc++.h>
using namespace std;
void swap(int *x ,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
int partition(int a[],int low,int high)
{
    int pivot=a[high];
    int i=low-1;
    for(int j=low;j<=high;j++)
    {
        if(a[j]<pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
    }
    swap(&a[i+1],&a[high]);
    return i+1;
}
void QuickSort(int a[],int low,int high)
{
    if(low<high)
    {
        int p=partition(a,low,high);
        QuickSort(a,low,p-1);
        QuickSort(a,p+1,high);
    }
}
void printArray(int a[],int n)
{
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    QuickSort(a,0,n-1);
    printArray(a,n);
    return 0;
}

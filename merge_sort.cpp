//Merge Sort
#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int r)
{
    int m=l+(r-l)/2;//Helps prevent stack overflow in case of big numbers
    int n1=m-l+1;//To store the length of the left array
    int n2=r-m;//To store the length of the array of the right side
    //Initializing the arrays
    int L[n1],R[n2];
    //Initializing the two arrays
    for(int i=0;i<n1;i++)
    L[i]=a[i+l];
    for(int j=0;j<n2;j++)
    R[j]=a[m+j+1];
    //Reinitialization
    int i=0,j=0,k=l;
    while(i<n1 && j<n2)
    {
        if(L[i]<=R[j])
        {
             a[k]=L[i];
             i++;
        }
        else
        {
            a[k]=R[j];
            j++;
        }
        k++;      
       
    }
    //Copying the rest of the elements
    while(i<n1)
    {
        a[k]=L[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[i]=R[j];
        k++;
        j++;
    }

}
void mergeSort(int a[],int l,int r)
{
    if(l<r)
    {
        int m=l+(r-l)/2;
        //Repeatedly dividing the array 
        mergeSort(a,l,m);
        mergeSort(a,m+1,r);
        //Merging the arrays
        merge(a,l,r);
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
    mergeSort(a,0,n-1);
    printArray(a,n);
    return 0;
}

// this is a merge sorting algorithm
// time complexity: O(n*Log n)
#include<stdio.h>
#include<stdlib.h>
void  merge(int A[],int l,int m,int r)
{
int i,j,k;
int n1=(m-l)+1;
int n2=r-m;
int L[n1],R[n2];
for(i=0;i<n1;i++)
    L[i]=A[l+i];
for(j=0;j<n2;j++)
    R[j]=A[m+1+j];
i=0;
j=0;
k=l;
while(i<n1&&j<n2)
{
  if(L[i]<=R[j])
    {
        A[k]=L[i];
        i++;
    }
      else
    {
     A[k]=R[j];
        j++;
    }
    k++;
}

while(i<n1)
{
    A[k]=L[i];
    i++;
    k++;
}
while(j<n2)
{
    A[k]=R[j];
    j++;
    k++;
}
}
void merge_sort(int A[],int left,int right)
{ int middle;
if(left<right){
middle=left+(right-left)/2;
merge_sort(A,left,middle);
merge_sort(A,middle+1,right);
merge(A,left,middle,right);
}
}
int main()
{
    int *A,size,i;
    printf("enter size");
    scanf("%d",&size);
    A=(int*)malloc(sizeof(int)*size);
    for(i=0;i<size;i++)
    scanf("%d",&A[i]);
    merge_sort(A,0,size-1);
     for(i=0;i<size;i++)
        printf("%d\t",A[i]);
    return 0;
}
// Input: Size: 7
// 10 7 2 54 32 1 4
// Output: 1 2 4 7 10 32 54

#include<iostream>

using namespace std;

int main()
{
	int n,i,a[30],temp,j;
	cout <<"Enter the number of element:";
	cin>>n;
	cout<<"\nEnter the elements\n";

	for (i=0;i<n;i++)
	{
	cin>>a[i];
	}

	for (i=0;i<=n;i++)
	{
	temp = a[i];
	j=i-1;

	while(temp<a[j]&&(j>=0))
	{
	a[j+1] = a[j];
	j=j-1;
	}
	a[j+1] = temp;
	}


	cout<<"\n Sorted list \n";
	for(i=0;i<n;i++)
	{
	cout<<a[i]<<"";
	}
	return 0;
}

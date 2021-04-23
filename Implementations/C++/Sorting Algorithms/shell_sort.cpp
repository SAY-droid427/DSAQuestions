// Shell sort is often termed as an improvement over insertion sort.In shell sort, the list is sorted by breaking it down into a number of smaller sublists,
// shell sort technique uses increment i, which is also called “gap” and uses it to create a list of elements that are “i” elements apart.

// Complexity for shell sort.
/*
1) Timecomplexity
    best case time complexity is O(n* logn)
    worst case is O(n* log2n).
    Time complexity of Shell sort is generally assumed to be near to O(n) and less than O(n^2).
    
2)Spacecomplexity
   Θ(1)
*/
#include<bits/stdc++.h>
using namespace std;

void display(int *array,int size){
    // This function is use for displaying values.
    for(int i=0;i<size;i++){
        cout<<array[i]<<" ";
    }
    cout<<"\n";
}

void swapping(int &a, int &b){
    // This function is use for swapping the values.
    int temp;
    temp=a;
    a=b;
    b=temp;
}

void shellSort(int *arr,int n){
    // This function is use for sorting. Therefore it creates a list of element.
    int gap,j,k;
    for(gap=n/2;gap>0;gap=gap/2){
        for(j=gap;j<n;j++){
            for(k=j-gap;k>=0;k-=gap){
                if(arr[k+gap]>=arr[k])
                   break;
                else 
                  swapping(arr[k+gap],arr[k]);
            }
        }

    }
    
}

int main(){
    // Driver code which is use to take value from user and pass it to main function.
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements: "<<"\n";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"Array before Sorting: ";
    display(arr,n);
    shellSort(arr,n);
    cout<<"Array after Sorting: ";
    display(arr,n);

}
// Shell sort is the highly efficient algorithm that comes to an improvement over the insertion sort.

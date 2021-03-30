//this is a mark and toys algorithm
// time complexity: O(n²)
// including necessary header file
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    // declaring variable
   int size,*arr,k,i;
   // taking array size by user
   printf("Enter size");
   scanf("%d",&size);
   //creating array dynamically
   arr=(int*)malloc(sizeof(int)*size);
   // Taking Arrays value
   printf("enter value");
   for(i=0;i<size;i++)
   {
       scanf("%d",&arr[i]);
   }
   // maximum money he/she wanted to spend
   printf("Enter the money he/she has");
  scanf("%d",&k);
  // putting the result of maximumToys function at %d
  printf("Maximum no. of toys he can buy is %d",maximumToys(size,arr,k));
  return 0;
}
int maximumToys(int prices_count, int* prices, int k) {

    int round,i,shift=0,sum=0,max=0;
    // main logic is to get the smallest price toys always

     for(round=1;round<=prices_count-1;round++)
     {  shift=prices[round];
         for(i=round;i>=1;i--)
         {
             if(prices[i-1]<shift)
             break;
             else
             {
                prices[i]=prices[i-1];
             }
         }
         prices[i]=shift;
     }
     for(i=0;i<prices_count;i++)
     {
         if(k>=sum+prices[i]){
         sum+=prices[i];
         max++;}
         else
         break;
     }
     return max;
}
// Input: size: 7 have money: 50
//arr block value : 1 12 5 111 200 1000 10
// Output: Maximum no. of toys he can buy is 4

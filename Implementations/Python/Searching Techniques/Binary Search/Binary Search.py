# Binary Search in python

def binary(arr,low,high,key):
    # It will run the loop while startIndex is less than or equal to endIndex
    while(low<=high):
        mid=(low+high)//2
        
        if(arr[mid]==key):
            print(arr[mid],"<- Found!!", "at index",mid)
            # If value of element is equal to the array at middleIndex then return that index
            break  
            
        elif(key not in arr):
            print("Not found")
            break

        # If the value of key is less than value of the array at middleIndex then decrease high by mid-1   
        elif(arr[mid]>key): 
            high=mid-1
            
        else:
            # Else store the value of low as mid+1
            low=mid+1
            
        
# Driver for the above code           
arr=[2,3,4,10,40]
x=10
# Calling binary search funtion
binary(arr,0,len(arr)-1,x) 

# Output
# 10 <- Found!! at index 3


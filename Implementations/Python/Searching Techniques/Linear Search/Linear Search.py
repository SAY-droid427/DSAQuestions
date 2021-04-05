# Python program for linear search

def linearsearch(arr, x):
   # loop will run till n
   for i in range(len(arr)):
      # if the element is fount return than index
      if arr[i] == x:
         return i
   #if the loop has been ended then return value as -1
   return -1 
arr = ['t','u','t','o','r','i','a','l']
# to find a int arr
x = 'a' 
# Calling linearsearch funtion
print("element found at index "+str(linearsearch(arr,x))) 


# Output
# element found at index 6

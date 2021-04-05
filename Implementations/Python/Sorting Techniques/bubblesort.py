a = []					

#Enter the number of inputs.
number = int(input("Enter the total number of elements: "))	
print("Enter the inputs:")
for i in range(number):

    #Input the elements 
    value = int(input())

    #appending elements to the array				
    a.append(value)					

#traverses throughout the array
for i in range(number):	

    #this loop swaps if the element is greater than the next element	
    for j in range(number - 1):	 
        if(a[j] > a[j + 1]):
             temp = a[j]
             a[j] = a[j + 1]
             a[j + 1] = temp

#Prints the sorted list
print("The Sorted List in Ascending Order : ", a) 

# Sample input and output for the above code
# Enter the total number of elements: 7
# Enter the inputs:
# 64
# 34
# 25
# 12
# 22
# 11
# 90
# The Sorted List in Ascending Order :  [11, 12, 22, 25, 34, 64, 90] 
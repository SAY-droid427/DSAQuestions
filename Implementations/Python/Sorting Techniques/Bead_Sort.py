def beadsort(input_list):
    return_list = []

    # Column of input beads and laying it out flat
    transposed_list = [0] * max(input_list)                          

    for num in input_list:

        # Drop the beads. To de-transpose
        transposed_list[:num] = [n + 1 for n in transposed_list[:num]] 

    for _ in input_list:
        # Counting values > 0; True == 1 and False == 0.
        return_list.append(sum(n > 0 for n in transposed_list))  
        
        # Remove the 'bottommost row' by subtracting 1 from each element.      
        transposed_list = [n - 1 for n in transposed_list]   
                  #TODO: 
    # The resulting list is sorted in descending order
    return return_list                                               

# Get length of array
n = int(input("Enter length of the array: "))                         
arr = []

# Get the elements of array
print("Enter each element of array and press Enter - \n")             
for i in range(n):
    num = int(input())
    arr.append(num)

# Calling beadsort function
farr = beadsort(arr)   
                                              
print('Sorted array is:', farr)   

# Output
# Enter length of the array: 4
# Enter each element of array and press Enter -

# 5
# 6
# 7
# 8
# Sorted array is: [8, 7, 6, 5]
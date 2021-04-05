import random
import time

# Function for insertion sort


def insertion(arr):
    for i in range(len(arr)):
        mark = arr[i]
        for j in range(i, -1, -1):
            if(mark <= arr[j]):
                arr[arr.index(mark)], arr[j] = arr[j], arr[arr.index(mark)]


# Main driver
size = int(input('Enter the size of the array'))
mylist = random.sample(range(0, 1000000), size)
list_copy = mylist.copy()
insertion(mylist)
if(size <= 20):
    print("Before insertion", list_copy)
    print("After insertion", mylist)
else:
    print("Array too large do you want to print?")
    check = input("Press 1 to print or any to skip:")
    if(check == "1"):
        print("Before insertion", list_copy)
        print("After insertion", mylist)


# Uncomment these lines to do benchmarking of the sorting technique
# #Average Case
# start=time.time()
# insertion(mylist)
# end=time.time()
# print("Average time:",(end-start))

# #Best Case
# start=time.time()
# insertion(mylist)
# end=time.time()
# print("Best time:",(end-start))

# #Worst time
# mylist.reverse()
# start=time.time()
# insertion(mylist)
# end=time.time()
# print("Worst time:",(end-start))

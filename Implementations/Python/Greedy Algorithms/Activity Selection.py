import operator


def activity_selection(n, s, f):  # Function to decide the activities to be performed
    act_detail = []

    for i in range(n):
        # Creating a list of list to store activity number,start time and end time as elements
        act_detail.append([i+1, s[i], f[i]])

    # Sorting list in ascending order with end time as key
    act_detail = sorted(act_detail, key=operator.itemgetter(2))
    act_n = 1  # Storing the number of activities to be performed
    act_performed = []  # Storing the details of the activities to be performed
    k = act_detail[0][2]
    act_performed.append(act_detail[0])
    i = 1
    while(i < n):
        # Comparing the end time of current activity with start time of next activity
        if k <= act_detail[i][1]:
            act_n += 1
            act_performed.append(act_detail[i])
            k = act_detail[i][2]
        i += 1  # Switching to next activity
    return act_n, act_performed


# Storing number of activities
n = int(input("Enter the number of activities:"))
# Storing start times
s = list(map(int, input("Enter the start times of activities:").split()))
# Storing end times
f = list(map(int, input("Enter the finishing times of activities:").split()))
# Fetching the returned values from function
act_n, act_performed = activity_selection(n, s, f)
print("Number of Activities performed:", act_n)  # Displaying activity count
# Displaying activities performed
print("Activities performed(in order)", end=":")
for i in range(len(act_performed)):
    print(act_performed[i][0], end=" ")

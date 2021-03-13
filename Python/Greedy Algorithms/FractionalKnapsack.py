'''
Algorithm:

Step 1:Start
Step 2:Enter the number of items(n),max weight(max_w)of the knapsack,profit values(p)of the items 
and the weight values(w) of the items
Step 3:Create a function(here knapsack)and take n,max_w,p and w as the parameter to the function
Step 4:Create a list of(here ob_detail) lists and insert profit value, weight value and profit/weight ratio
as a single element of the list of lists of different objects
Step 5:Sort the created list(here ob_detail) with profit/weight ratio as the key in decreasing order of 
their profit/weight ratio
Step 6:Calculate the max profit by adding the profit values of the individual items from the sorted list(here ob_details)
Step 7:Check if the knapsack is full or has insufficient weight by decreasing the weight of the items whose
profit is considered in the knapsack while calculating the max profit. Stop adding profit value if the knapsack is full 
or has insufficient weight and store the index of the item that is overflowing the knapsack max weight
Step 8:If the knapsack has space then calculate the fractional profit and add it to the max profit
Step 9:Return the max profit calculated
Step 10:Store the returned value and display it 
Step 11:Stop

'''


import operator as op


def knapsack(n, v, w, max_w):  # function for calculating the max_profit

    ob_detail = []  # a list of list for storing profit,weight and profit/weight as a single element
    for i in range(n):
        ob_detail.append([v[i], w[i], v[i]/w[i]])

    # reverse sorting the list keeping profit/weight as the key
    ob_detail = sorted(ob_detail, reverse=True, key=op.itemgetter(2))

    max_profit = 0  # for storing the maximum profit
    x = 0  # for storing fractional weight in the end
    w1 = max_w
    for i in range(n):
        if(w1 > 0 and ob_detail[i][1] < w1):
            max_profit = max_profit+(ob_detail[i][0])  # calculating max profit
            # decreasing the weight capacity after adding the object into knapsack
            w1 = w1-(ob_detail[i][1])
        else:
            x = i
            break

    if(w1 > 0):  # for calculating fractional part of object if the knapsack is not full
        max_profit = max_profit+((w1/ob_detail[i][1])*ob_detail[i][0])

    return(max_profit)


# for storing number of items available
n = int(input("Enter the number of items:"))
max_w = int(input("Enter the max weight of the bag:"))
# for storing value of each item
v = list(map(int, input("Enter the profit values:").split()))
# for storing weight of each item
w = list(map(int, input("Enter the weight values:").split()))
profit = knapsack(n, v, w, max_w)
print(profit)

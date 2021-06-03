class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        vector<int>dp(n+1, 0);
        
        for(int i = n - 1; i >= 0; i--)
        {
            int maxSum = arr[i];
            int maxNum = arr[i];
            
            for(int j = i; j < i+k && j < n ; j++)
            {
                maxNum = max(maxNum, arr[j]);
                
                maxSum = max(maxSum, dp[j+1] + maxNum*(j-i+1));
            }
            
            dp[i] = maxSum;
        }
        
        
        
        return dp[0];
    }
};


/*
dp
V
[0  0 0 0 0 0  0]
[1 15 7 9 2 5 10]
               ^
               i,j
MaxSum = 10
MaxNum = 10

dp = [0 0 0 0 0 0 10]

[1 15 7 9 2 5 10]
            ^
            i
            j
j = 5
i = 5
MaxNum = 10
MaxSum = max(10,10*(5-5+1) + 10 ) = 20

[1 15 7 0 2 5 10]
            i
               j

j = 6
i = 5
MaxNum = 10
MaxSum = max(20,10*(6-5+1) + 10) = 30
*/
class Solution {
public:
    int minOperations(vector<int>& arr) {
        
        int min_oprs = 0;
        int n = arr.size();
        
        for(int i = 1 ; i < n; i++)
        {
            if(arr[i] <= arr[i-1])
            {
                min_oprs += abs(arr[i] - arr[i-1]) + 1;
                arr[i] = arr[i-1] + 1;                
            }
        }
        
        return min_oprs;
    }
};
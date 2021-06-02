class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        int prev_diff = abs(arr[0] - arr[1]);
        for(int i = 2 ; i < n ; i++)
        {
            int diff = abs(arr[i] - arr[i-1]);
            if(prev_diff == diff)
                continue;
            else
                return false;            
        }
        
        
        return true;
    }
};
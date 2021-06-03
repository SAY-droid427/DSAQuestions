class Solution {
public:
    int findNumbers(vector<int>& nums) {
        
        int n = nums.size();
        int res = 0;
        for(int i = 0 ; i < n ; i++)
            if(to_string(nums[i]).length()%2 == 0)
                res++;
        
        return res;
    }
};
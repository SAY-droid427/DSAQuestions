class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int n  = nums.size();
        int i = n-2;
        
        while(i>=0 && nums[i+1] <= nums[i])
            i--;
        
        if(i == -1)
        {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        else
        {
            int k = n-1;
            while(k>=0 && nums[i]>=nums[k])
                k--;
            
            swap(nums[i], nums[k]);
            reverse(nums.begin()+i+1, nums.end());
        }
    }
};
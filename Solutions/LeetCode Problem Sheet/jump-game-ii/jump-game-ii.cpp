class Solution {
public:
    int jump(vector<int>& nums) {
        
        if(nums.size()<2)
            return 0;
        
        int n = nums.size();
        int jump = 1;
        
        int curr_jump = nums[0];
        int max_jump = nums[0];
        
        int i = 0;
        while(i<n-1)
        {
            max_jump = max(max_jump,i+nums[i]);
            if(curr_jump==i)
            {
                jump++;
                curr_jump = max_jump;
            }
            
            i++;
        }
        
        return jump;
        
        
    }
};
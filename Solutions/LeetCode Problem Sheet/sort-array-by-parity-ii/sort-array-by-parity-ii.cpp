class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>ans(n,0);
        
        int odd = 1;
        int even = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i]%2==0)
            {
                ans[even] = nums[i];
                even+=2;
            }
            
            else
            {
                ans[odd] = nums[i];
                odd+=2;
            }
        }
        
        
        return ans;
    }
};
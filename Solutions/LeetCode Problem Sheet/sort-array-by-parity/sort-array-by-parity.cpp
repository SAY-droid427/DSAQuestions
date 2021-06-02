class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>res(n,0);
        
        int even = 0;
        int odd = n-1;
        for(int i = 0; i < n; i++)
        {
            if(nums[i]%2 == 0)
            {
                res[even] = nums[i];
                even++;
            }
            
            else
            {
                res[odd] = nums[i];
                odd--;
            }  
            
                
        }
        
        
        return res;
    }
};

// 1 2 3 4
// 3 1 2 4
// 1 4 2 3
// 2 

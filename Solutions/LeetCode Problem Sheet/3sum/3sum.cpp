class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>>res;
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++)
        {
            int left = i+1;
            int right = nums.size()-1;
            
            int target = - nums[i];
            while(left < right)
            {
                int sum = nums[left] + nums[right];
                
                //Binary Search for Target
                if(sum < target )
                    left ++;
                else if (sum > target)
                    right --;
                else 
                {
                    //If Found Push to res
                    vector<int>triplet(3,0);
                    
                    triplet[0] = nums[i];
                    triplet[1] = nums[left];
                    triplet[2] = nums[right];
                    
                    res.push_back(triplet);
                    
                    //Skip elements with same left value
                    while(left<right&&nums[left]==triplet[1])
                        left++;
                    
                    //Skip elements with same right value
                    while(left<right&&nums[right]==triplet[2])
                        right--;
                }
                
                
            }
            
            //Skip Elements with Same Value & Choose the Latest one
             while(i+1<nums.size()&&nums[i+1]==nums[i])
                i++;
        }
        
        
        return res;
    }
};
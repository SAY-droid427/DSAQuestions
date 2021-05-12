class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        
        vector<int> res;
        
        for(int i = 0 ;i< nums.size(); i++)
        {
            int indx = index[i];
            int value = nums[i];
            
            auto idx = res.begin() + indx;
            res.insert(idx, value);
        }
        
        
        return res;
        
        
    }
};
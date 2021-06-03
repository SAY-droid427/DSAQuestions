class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        
        int n = nums.size();
        int freq_idx = 0;
        int val_idx = 1;
        
        vector<int>res;
        while(val_idx < nums.size())
        {
            res.insert(res.end(),nums[freq_idx],nums[val_idx]);
            freq_idx +=2;
            val_idx +=2;
        }
        
        
        
        return res;
    }
};
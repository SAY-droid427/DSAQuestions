class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> copy = nums;
        
        map<int, int> mp;
        int x = nums.size();
        
        sort(copy.begin(), copy.end());
        
        for(int i = x-1 ; i >= 0; i--)
            mp[copy[i]] = i;
        
        for(int i = 0 ; i < x ; i++)
            nums[i] = mp[nums[i]];
        
        return nums;
        
    }
};
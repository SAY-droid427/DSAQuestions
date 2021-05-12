class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size()-1;
        while(lo<=hi)
        {
            int mid = lo + (hi-lo)/2;
            if(target == nums[mid])
                return mid;
            else if(target> nums[mid])
                lo = mid + 1;
            else
                hi = mid-1;
        }
        
        return lo;
    }
};

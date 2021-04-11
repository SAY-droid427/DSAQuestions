class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        //Declare a Map containing
        //Key -> Value
        //Value -> Index
        map<int,int>mp;
        
        for(int i = 0 ; i < nums.size(); i++)
        {
            //If Current Value [target - nums[i]
            //is found in Map, return the indexes
            //of corresponding elements
            if(mp.find(target - nums[i]) != mp.end())
                return {i, mp[target - nums[i]]};
            
            //Insert the Number
            //& It's Index
            //into the Map
            mp[nums[i]] = i;
        }
        
        
        //Return {0,0}
        //If Nothing Found
        return {0,0};
    }
};
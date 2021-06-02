class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        
        int key_idx = 0;
        if(ruleKey == "type")
            key_idx = 0;
        if(ruleKey == "color")
            key_idx = 1;
        if(ruleKey == "name")
            key_idx = 2;
        
        int n = items.size();
        int res = 0;
        for(int i = 0 ; i < n; i++)
        {
            if(items[i][key_idx] == ruleValue)
                res++;
        }
        
        
        
        return res;
        
    }
};
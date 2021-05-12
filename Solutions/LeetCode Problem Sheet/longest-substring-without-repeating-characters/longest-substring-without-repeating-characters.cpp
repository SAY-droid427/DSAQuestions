class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        
        unordered_map<char,int>mp;
        
        int p1 = 0;
        int p2 = 0;
        
        int maxi = 0;
        
        while(p2<n)
        {
            if(mp.find(s[p2])==mp.end())
            {
                mp[s[p2]]++;
                p2++;
                if(maxi<mp.size())
                    maxi = mp.size();
            }
            else
            {
                mp.erase(s[p1]);
                p1++;
            }
        }
        
        
        return maxi;
    }
};
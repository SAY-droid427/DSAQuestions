class Solution {
public:
    string sortString(string s) {
        
        vector<int>lower(26,0);
        int n = s.length();
        
        for(int i = 0 ; i < n ; i++)
            lower[s[i] - 'a']++;
        
        int k = 0;
        string ans = "";
        while(k < n)
        {
            for(int i = 0; i < 26; i++)
            {
                if(lower[i] > 0)
                {
                    lower[i]--;
                    ans += i + 'a';
                    k++;
                }
            }
            
            
            for(int i = 25 ; i >= 0; i--)
            {
                if(lower[i] > 0)
                {
                    lower[i]--;
                    ans += i + 'a';
                    k++;
                }
            }
        }
        
        
        return ans;
        
    }
};
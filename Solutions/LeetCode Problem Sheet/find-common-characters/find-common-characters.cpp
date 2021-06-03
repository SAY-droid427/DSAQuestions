class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int>mp_1(26,0);
        vector<int>mp_2(26,0);
        
        for(auto ch: words[0])
            mp_1[ch - 'a']++;
        
        int n = words.size();
        for(int i = 1; i < n; i++)
        {
            for(auto ch: words[i])
                mp_2[ch- 'a']++;
            
            for(int i = 0; i < 26; i++)
            {
                mp_1[i] = min(mp_1[i], mp_2[i]);
                mp_2[i] = 0;
            }
        }
        
        
        vector<string>res;
        
        for(int i = 0 ; i < 26 ; i++)
        {
            if(mp_1[i] > 0)
            {
                int count = mp_1[i];
                while(count--)
                {
                    char x = i + 'a';
                    string s;
                    s = x;
                    res.push_back(s);
                }
            }
        }
        
        
        return res;
               
        
    }
};
class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        
        vector<int>charx(26,0);
        
        //Map Freq of String chars
        for(auto x : chars)
            charx[x - 'a']++;
        
    
             
        int sum = 0;
        bool ok = true;
        for(int i = 0 ; i < words.size(); i++)
        {
            ok = true;
            vector<int>chary(26,0);
            
            for(int j = 0 ; j < words[i].length(); j++)
                chary[words[i][j] - 'a']++;
            
            for(int j = 0; j < 26; j++)
                if(chary[j] > charx[j])
                    ok = false;
            
            if(ok)
                sum += words[i].length();
        }
        
        return sum;
    }
};
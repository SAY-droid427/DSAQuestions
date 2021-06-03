class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        
        set<char>s;
        for(auto x : allowed)
            s.insert(x);
        
        int count = 0;
        int n = words.size();
        for(auto wrd : words)
        {
            string y = wrd;
            set<char>a;
            bool ok = true;
            for(auto x : y)
            {
                if(s.find(x) != s.end())
                    continue;
                else
                    ok = false;
            }
            
            if(ok)
                count++;
        
        }
        
        
        return count;
    }
};
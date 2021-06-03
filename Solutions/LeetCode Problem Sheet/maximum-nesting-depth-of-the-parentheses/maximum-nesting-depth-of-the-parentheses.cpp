class Solution {
public:
    int maxDepth(string s) {
        
        int n = s.length();
        int open = 0;
        int max_depth = 0;
        
        for(auto ch : s)
        {
            if(ch == '(')
            {
                open++;
                max_depth = max(max_depth, open);
            }
                
            if(ch == ')')
                open--;
        }
        
        
        
        return max_depth;
    }
};
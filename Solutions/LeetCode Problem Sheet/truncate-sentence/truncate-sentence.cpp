class Solution {
public:
    string truncateSentence(string s, int k) {
        
        string a = "";
        for(auto x : s)
        {
            if(k == 0)
                break;
            if(x == ' ')
                k--;
            a += x;
        }
        int n = a.length();
        
        return a[n-1] == ' ' ? a.substr(0,n-1) : a;
            
            
    }
};
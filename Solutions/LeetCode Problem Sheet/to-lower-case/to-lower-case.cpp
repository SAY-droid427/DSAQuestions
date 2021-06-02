class Solution {
public:
    string toLowerCase(string s) {
        string res = "";
        for(auto x : s) res += (char)tolower(x);
        return res;
    
    }
};
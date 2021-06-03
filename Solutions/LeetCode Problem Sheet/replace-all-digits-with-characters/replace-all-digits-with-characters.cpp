class Solution {
public:
    string replaceDigits(string s) {
        
        int n = s.length();
        for(int i = 1 ; i < n ; i+=2)
        {   
            // cout << ++s[i-1];   
            int x = s[i] - '0';
            cout << x << " ";
            s[i] = s[i-1] + x;
        }
        return s;
    }
};
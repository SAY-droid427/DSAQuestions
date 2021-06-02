class Solution {
public:
    string sortSentence(string s) {
        vector<string>str;
        
        stringstream ss(s);
        char delim = ' ';
        while (std::getline(ss, s, delim)) 
            str.push_back(s);
        
        string ans = "";
        map<int, string>mp;
        
        for(int i = 0; i < str.size(); i++)
        {
            int n = str[i].length();
            int idx = str[i][n-1] - '0';
            cout << idx << endl;
            
            mp[idx] = str[i].substr(0,n-1);
            cout << mp[idx] << endl;
        }
        
        map<int, string>::iterator it;
        
        for(it = mp.begin(); it!=mp.end(); it++)
            ans += it->second + " ";
            
        int m = ans.length();
        return ans.substr(0,m-1);
        
    }
};
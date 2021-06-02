class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string wrd1 = "";
        for(auto s : word1)wrd1+=s;
        string wrd2 = "";
        for(auto s : word2)wrd2+=s;
        return (wrd1 == wrd2)?true:false;
    }
};
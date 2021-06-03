class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        
        vector<string>morse = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string>s;
        for(auto x : words)
        { 
            string a = "";
            for(auto y : x)
                a += morse[y-'a'];
            s.insert(a);
        }
        return s.size();
    }
};
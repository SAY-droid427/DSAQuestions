class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string>keypad = {"0","0","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n = digits.length();
        vector<string>res;
        if(n==0)
            return res;
        backtrack(digits,res,0,"",keypad);
        return res;
    }
    
    void backtrack(string digits, vector<string>&res, int index, string current, vector<string>keypad)
    {
        if(index == digits.length())
        {
            res.push_back(current);
            return;
        }
        
        string letters = keypad[digits[index] - '0'];
        for(int i = 0;i<letters.size();i++)
            backtrack(digits,res,index+1,current+letters[i],keypad);
    }
};
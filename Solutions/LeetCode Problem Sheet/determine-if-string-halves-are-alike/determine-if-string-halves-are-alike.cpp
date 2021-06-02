class Solution {
public:
    bool halvesAreAlike(string s) {
        set<char>vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        int n = s.length();
        int one = 0;
        int two = 0;
        
        
        for(int i = 0, j = n/2 ; i < n/2 ; i++, j++ )
        {

            if(vowels.find(s[i])!=vowels.end())
                one++;
            if(vowels.find(s[j])!=vowels.end())
                two++;            
        }
        
        
        cout << one << " " << two;
        return one == two ? true : false;
    }
};


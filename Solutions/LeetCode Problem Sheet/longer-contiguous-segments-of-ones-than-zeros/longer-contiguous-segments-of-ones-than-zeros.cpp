class Solution {
public:
    bool checkZeroOnes(string s) {
        
        int count_1 = 0;
        int count_0 = 0;
        
        int max_count1 = 0;
        int max_count0 = 0;
        int n = s.length();
        for(int i = 0 ; i < n ; i++)
        {
            if(s[i] == '1')
            {
                count_0 = 0;
                count_1++;
                max_count1 = max(count_1, max_count1);
            }
            
            else
            {
                count_1 = 0;
                count_0++;
                max_count0 = max(count_0, max_count0);
            }
            
        }
        
        return max_count1>max_count0 ? true : false;
    }
};
class Solution {
public:
    int myAtoi(string str) {
        
        long long int result = 0;
        int sign = 1;
        
        int n = str.size();
        
        //Return 0 for Empty String
        if(n==0)
            return 0;
        
        //Find first Character which is not
        //WHitespace
        int i = str.find_first_not_of(' ');
        if(i == -1)
            return 0;
        //Check for the Sign
        if(str[i] == '-' || str[i] == '+')
            sign = (str[i++] == '+') ? 1 : -1;
        
        //Traverse String which has digits
        //from 0 to 9 and Add it to Result
        while(i < str.size() && isdigit(str[i]))
        {
            result = result*10 + (str[i++] - '0');
            
            //Check for Overflow
            if(result*sign >= INT_MAX)
                return INT_MAX;
            if(result*sign <= INT_MIN)
                return INT_MIN;                
        }
        
        return result*sign;
        
    }
};
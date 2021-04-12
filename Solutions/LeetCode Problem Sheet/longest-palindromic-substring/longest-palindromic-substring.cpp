class Solution {
public:
    string substring(string s, int low, int high)
    {
        string x = "";
        for(int i = low;i<=high;i++)
             x += s[i];
        
        return x;
    }
    string longestPalindrome(string s) {
        int n = s.size();
        bool table[n][n];
        memset(table,0,sizeof(table));
        int max_Length = 1;
        int start = 0;
        
        for(int i=0;i<n;i++)
            table[i][i] = true;
        for(int i = 0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                table[i][i+1]=true;   
                start = i;
                max_Length = 2;
            }
        }
        
        for(int k=3;k<=n;k++)
        {
            for(int i = 0;i<n-k+1;i++)
            {
                int j = i+k-1;
                if(table[i+1][j-1]&&s[i]==s[j])
                {    table[i][j] = true;
                 
                    if(k>max_Length)
                     {
                        max_Length = k;
                        start = i;
                     }
                }
            }                
            
        }
        
        string x = substring(s,start,start+max_Length-1);
        return x;
        
    }
        
       
    
};
class Solution {
public:
    int countVowelStrings(int n) {
        
        //Each Element of DP Table dp[i][j] Indicates
        //the Number of Possible Sorted Vowel Strings
        //With i length and ending with vowel j
        //a->0 e->1 i->2 o->3 u->4
        vector<vector<int>>dp(n+1,vector<int>(5,0));
  
        
        //Initialization of DP Table
        //With Length 1, Number of Sorted Vowel
        //Strings are always 1
        for(int i = 0;i<5;i++)
            dp[1][i] = 1;
        
        //Run A Loop for Each Possible Length
        for(int i=2;i<=n;i++)
        {
            //For Each Possible Length, Run A Loop
            //for Each Possible Ending Sorted Vowel
            //String
            for(int j=0;j<5;j++)
            {
                //To count Each Vowel String Ending with the
                //Current character, the curr character
                //can be added to all lexicographically smaller vowel
                // strings i.e. k<=j of the previous length i.e. i-1
                for(int k=0;k<=j;k++)
                {
                    
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
        
        int ans = 0;
        
        //Find Summation of All Possible Sorted Strings
        for(int i=0;i<5;i++)
        {
            ans += dp[n][i];
        }
        
        return ans;
        
        
        
    }
};

//Vowels = a,e,i,o,u

//Example Dry for n = 5
// DP Table
// dp a e i o u -> Each Column Represents Strings Ending                   
//  0 0 0 0 0 0    with Column Index Vowel
//  1 1 1 1 1 1 -> a e i o u
//  2 1 2 3 4 5
//  3 1 3 6 10 15
//  4 . . . . ,
//  5 . . . . .  -> And So On

//For Example
//dp[2][1] = 2 -> How ?
//dp[1][1] = 1 which Means String 'e'
//dp[2][1] -> Strings of Length 2 ending With 'e'
//dp[2][1] -> Appending An e to Sorted Strings of Length '1' but lesser than
//            and equal to 'e' would make count under this.
//dp[2][1] -> Accounts for ('a + e' + 'e + e') -> Total Count = 2
//Therefore -> dp[2][1] = 2
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        
        int r = matrix.size();
        int c = matrix[0].size();
        
        vector<int>res;
        
        unordered_set<int>st;
        
        for(int i = 0 ; i < r; i++)
        {
            int mini_r = INT_MAX;
            for(int j = 0; j < c; j++)
            {
                mini_r = min(mini_r, matrix[i][j]);
            }
            
            st.insert(mini_r);
        }
        
        for(int i = 0; i < c; i++)
        {
            int max_c = INT_MIN;
            for(int j = 0; j < r; j++)
            {
                max_c = max(max_c, matrix[j][i]);
            }
            
            if(st.find(max_c)!=st.end())
                res.push_back(max_c);
        }
        
        
        return res;
    }
};
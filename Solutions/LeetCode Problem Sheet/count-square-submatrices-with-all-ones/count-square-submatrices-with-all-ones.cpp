class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        for(int i = 1; i < m ; i++)
        {
            for(int j = 1; j < n ; j++)
                if(matrix[i][j])
                    matrix[i][j] += min({matrix[i-1][j-1], 
                                    matrix[i][j-1], matrix[i-1][j]});
        }
        
        
        int result = 0;
        for(int i = 0 ; i < m ; i++)
            for(int j = 0 ; j < n ; j++)
                result += matrix[i][j];
        
        
        return result;
    }
};
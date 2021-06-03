class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        
        int n = image.size();
        vector<vector<int>>res(n, vector<int>(n,0));
        
        for(int i = 0 ; i < n; i++)
        {
            for(int j = n-1 ; j >= 0; j--)
            {
                if(image[i][j] == 1)
                    res[i][n-j-1] = 0;
                else
                    res[i][n-j-1] = 1;                    
            }
        }
        
        
        return res;
    }
};



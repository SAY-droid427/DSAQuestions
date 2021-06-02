class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        
        int m = box.size();
        int n = box[0].size();
        
        for(int i = 0; i < m ; i++ )
        {
            int down_empty = n-1;
            
            for(int j = n-1; j >= 0; j--)
            {
                if(box[i][j] == '#')
                {
                    box[i][j] = '.';
                    box[i][down_empty] = '#';
                    down_empty--;
                }
                
                else if(box[i][j] == '*')
                    down_empty = j - 1;
            }
        }
        
        vector<vector<char>>res(n, vector<char>(m,0));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0 ; j < m ; j++)
            {
                res[i][j] = box[m-1-j][i];
            }
        }
        
        return res;
    }
};
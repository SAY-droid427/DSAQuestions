class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int r = grid.size();
        int c = grid[0].size();
        
        //Separate Matrix to Keep Check of Visited Points
        vector<vector<bool>>visited(r, vector<bool>(c,false));
        
        //Direction Vectors
        vector<int>rtrav = {1,-1,0,0};
        vector<int>ctrav = {0,0,1,-1};
        
        int ans = 0;
        
        for(int i = 0 ; i < r; i++)
        {
            for(int j = 0; j < c; j++)
            {
                //If an Island is Found, Start DFS
                if(grid[i][j] == 1 && !visited[i][j])
                {
                    int shape = 0;
                    stack<pair<int,int>>st;
                    
                    //Push it to A Stack
                    st.push(make_pair(i,j));
                    
                    visited[i][j] = true;
                    
                    //Continue DFS Unless Stack is Empty
                    while(!st.empty())
                    {
                        pair<int,int> top = st.top();
                        st.pop();
                        int rx = top.first;
                        int cx = top.second;
                        
                        //Increase Shape for Every '1'
                        //in Stack
                        shape++;
                        
                        for(int k = 0; k < 4 ; k++)
                        {
                            //Four Direction Traversal
                            int nr = rx + rtrav[k];
                            int nc = cx + ctrav[k];
                            
                            //Within Boundaries & Unvisited
                            if(nr >= 0 && nr < r 
                               && nc >= 0 && nc < c
                                && grid[nr][nc] == 1 && !visited[nr][nc])
                            {
                                //Push to Stack & Mark Visited
                                st.push(make_pair(nr,nc));
                                visited[nr][nc] = true;
                            }
                        }
                    }
                    
                    //Update Max Size
                    ans = max(shape, ans);
                }
            }
        }
        
        
        return ans;
    }
};
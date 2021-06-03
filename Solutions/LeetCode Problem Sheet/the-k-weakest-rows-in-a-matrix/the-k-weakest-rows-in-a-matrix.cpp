class Solution {    
    static bool sortbysec(const pair<int,int> &a,const pair<int,int> &b)
    {
        return (a.second < b.second);
    }
    public:    
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        
        int m = mat.size();
        int n = mat[0].size();
        
        vector<pair<int,int>>arranged;
        
        for(int i = 0 ; i < m ; i++)
        {
            int count = 0;
            for(int j = 0 ; j < n ; j++)
            {
                if(mat[i][j] == 1)
                    count++;
            }
            
            arranged.push_back(make_pair(count, i));
        }
                
        sort(arranged.begin(),arranged.end());
        for(auto x : arranged)
            cout << x.first << " " << x.second << endl;
        
        
        
        vector<int>x(k,0);        
        for(int i = 0; i < k; i++)
        {
            x[i] = arranged[i].second;
            
        }
        
        
        return x;
    }
};
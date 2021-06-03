class Solution {
public:
    vector<int> sumZero(int n) {
        
        vector<int>res;
        if(n%2 == 0)
        {
            int t = n;
            while(t)
            {
                res.push_back(n);
                res.push_back(-n);
                n--;
                
                t = t-2;
            }
        }
        
        else if(n%2 !=0)
        {
            res.push_back(0);
            n--;
            
            int t = n;
            while(t)
            {
                res.push_back(n);
                res.push_back(-n);
                
                n--;
                t = t-2;
            }
        }
        
        
        return res;
    }
};
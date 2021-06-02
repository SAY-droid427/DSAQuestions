class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        map<int, int> mp_1;
        map<int, int> mp_2;
        
        set<int>st;
        
        for(int i = 0; i < arr2.size(); i++)
            st.insert(arr2[i]);
        
        vector<int>rem;
        for(int i = 0; i < arr1.size(); i++)
        {
            if(st.find(arr1[i])==st.end())
                rem.push_back(arr1[i]);
            
            if(mp_1.find(arr1[i])==mp_1.end())
                mp_1[arr1[i]]=1;
            else
                mp_1[arr1[i]]++;
        }
        
        for(int i = 0; i < arr2.size(); i++)
        {
            mp_2[i] = arr2[i];
        }
        
        
        vector<int>res;
        for(auto x : mp_2)
        {
            int k = x.second;
            if(mp_1.find(k) != mp_1.end())
            {
                int count = mp_1[k];
                while(count--)
                    res.push_back(k);
            }
        }
        
        sort(rem.begin(), rem.end());
        for(auto x : rem)
            res.push_back(x);
        
        
        return res;
        
    }
};
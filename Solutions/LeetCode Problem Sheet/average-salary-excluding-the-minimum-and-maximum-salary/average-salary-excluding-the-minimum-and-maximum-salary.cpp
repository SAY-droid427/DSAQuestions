class Solution {
public:
    double average(vector<int>& salary) {
        double avg = 0;
        
        int max_s = INT_MIN;
        int min_s = INT_MAX;
        
        for(auto x: salary)
        {
            avg += x;
            max_s = max(x,max_s);
            min_s = min(x,min_s);
        }
        
        
        avg -= (max_s + min_s);
        int n = salary.size()-2;
        avg = avg/double(n);
        
        return avg;
        
    }
};
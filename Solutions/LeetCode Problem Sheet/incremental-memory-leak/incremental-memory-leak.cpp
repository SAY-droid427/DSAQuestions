class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        
        int i = 1;
        int crashtime = 1;
        while(memory1 >= i || memory2 >= i )
        {
            int max = memory1 >= memory2 ? memory1 : memory2;
            if(max == memory1)
                memory1 -= i;
            else
                memory2 -= i;
            
            i++;
        }
        
        crashtime = i;
        vector<int>res = {crashtime, memory1, memory2};
        return res;
    }
};
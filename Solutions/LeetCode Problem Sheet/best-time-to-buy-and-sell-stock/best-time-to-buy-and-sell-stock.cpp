class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        //Declare the Max_Profit & Min Possible
        int max_profit = 0;
        int min = INT_MAX;
        int l = 0;
        
        
        while(l<prices.size())
        {   
            //Find Min Price till Current
            if(prices[l]<min)
                min = prices[l];
            //If Profit > Initialized Max
            //Update
            else if(prices[l]-min>max_profit)
                max_profit = prices[l]-min;
            
            //Move Pointer Ahead
            l++;
        }
        
        return max_profit;
    }
};
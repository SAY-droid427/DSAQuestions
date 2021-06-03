class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        
        vector<int>box(46,0);
        
        int maxi = -1;
        for(int i = lowLimit; i <= highLimit; i++)
        {
            int temp = i;
            int sum = 0;
            while(temp)
            {
                sum += temp%10;
                temp = temp/10;

            }
            
            box[sum]++;
            maxi = max(maxi,box[sum]);  
        }
        
        
        return maxi;
    }
};
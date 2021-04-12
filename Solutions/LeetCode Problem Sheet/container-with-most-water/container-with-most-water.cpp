class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1,res = 0;
        while(l<r)
        {
            res = max(res,min(height[l],height[r])*(r-l));
            height[l]<height[r]?l++:r--;
        }        
        return res;     
        
    }
};
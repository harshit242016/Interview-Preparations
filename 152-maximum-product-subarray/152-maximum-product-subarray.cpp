class Solution {
public:
    
    
    
    int maxProduct(vector<int>& nums) 
    {
        int n = nums.size();
        int maxVal[n];
        int minVal[n];
        maxVal[0] = nums[0];
        minVal[0] = nums[0];
        for(int i = 1;i<n;i++)
        {
            maxVal[i] = max(maxVal[i-1] * nums[i],max(minVal[i-1] * nums[i],nums[i]));
            minVal[i] = min(maxVal[i-1] * nums[i],min(minVal[i-1] * nums[i],nums[i]));
        }
        int maxx = INT_MIN;
        for(int i = 0;i<n;i++)
        {
            if(maxx<maxVal[i])
            {
                maxx = maxVal[i];
            }
        }
        return maxx;
    }
    
};
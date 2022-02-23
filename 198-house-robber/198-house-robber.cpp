class Solution {
public:
    int houseRobber(vector<int> &nums,vector<int> &dp,int i)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        
        dp[i] = max(houseRobber(nums,dp,i+1),houseRobber(nums,dp,i+2)+nums[i]);
        return dp[i];
    }
    int rob(vector<int>& nums) 
    {
        vector<int> dp(301,-1);
        return houseRobber(nums,dp,0);
    }
};
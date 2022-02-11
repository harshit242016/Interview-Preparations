class Solution {
    int dp[1001];
public:
    int helper(vector<int> &nums,int i,int n)
    {
        if(i>n)
        {
            return 0;
        }
        if(dp[i]>-1)
        {
            return dp[i];
        }
        int leaveCurrentValue = helper(nums,i+1,n);
        int addCurrentValue = helper(nums,i+2,n) + nums[i];
        dp[i] = max(leaveCurrentValue,addCurrentValue);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        if(nums.size()==1)
        {
            return nums[0];
        }
        memset(dp,-1,sizeof(dp));
        
        int case1 = helper(nums,0,nums.size()-2);
        
        memset(dp,-1,sizeof(dp));
        int case2 = helper(nums,1,nums.size()-1);
        
        return max(case1,case2);
    }
};
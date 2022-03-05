class Solution {
public:
    int houseRobbers(vector<int> &arr,vector<int> &dp,int i)
    {
        if(i>=arr.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        
        dp[i] = max((arr[i] + houseRobbers(arr,dp,i+2)),houseRobbers(arr,dp,i+1));
        
        return dp[i];
    }
    
    int deleteAndEarn(vector<int>& nums) 
    {
        vector<int> dp(10001,-1);
        vector<int> arr(10001,0);
        for(int i = 0;i<nums.size();i++)
        {
            arr[nums[i]]+=nums[i];
        }
        int x = houseRobbers(arr,dp,0);
        return x;
    }
};
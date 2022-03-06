class Solution {
public:
    int countOrders(int n) 
    {
        long long dp[501];
        memset(dp,0,sizeof(dp));
        long rem = 1e9+7;
        dp[1] = 1;
        dp[2] = 6;
        for(int i = 3;i<=n;i++)
        {
            int places = i*2 - 1;
            int res = (places * (places+1))/2;
            dp[i] = (dp[i-1] * res)%rem;
        }
        return dp[n];
    }
};
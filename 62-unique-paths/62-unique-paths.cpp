class Solution {
public:
    int uniquepathssolution(int m,int n,int dp[101][101])
    {
        if(m==1 or n==1)
        {
            return 1;
        }
        if(dp[m][n]!=0)
        {
            return dp[m][n];
        }
        dp[m][n] = uniquepathssolution(m,n-1,dp)+uniquepathssolution(m-1,n,dp);
        return dp[m][n];
    }
    
    int uniquePaths(int m, int n) 
    {
        int dp[101][101];
        memset(dp,0,sizeof(dp));
        return uniquepathssolution(m,n,dp);
    }
};
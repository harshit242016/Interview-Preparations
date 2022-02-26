class Solution {
public:
     int uniquepaths(vector<vector<int>> &obstacleGrid,int dp[101][101],int row,int col)
    {
        if(row<0 or col<0)
        {
            return 0;
        }
        if(row==0 and col==0)
        {
            return 1;
        }
        if(dp[row][col]>0)
        {
            return dp[row][col];
        }
        if(obstacleGrid[row][col]==1)
        {
            return 0;
        }
        dp[row][col] = uniquepaths(obstacleGrid,dp,row-1,col)+uniquepaths(obstacleGrid,dp,row,col-1);
        return dp[row][col];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int row = obstacleGrid.size();
        int col = obstacleGrid.front().size();
        if(obstacleGrid[0][0]==1)
        {
            return 0;
        }
        int dp[101][101];
        memset(dp,0,sizeof(dp));
        return uniquepaths(obstacleGrid,dp,row-1,col-1);
    }
};
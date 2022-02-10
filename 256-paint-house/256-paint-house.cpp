class Solution {
public:
    
    int minCostHelper(vector<vector<int>> &costs, vector<vector<int>> &dp,int index,int curr)
    {
        if(index == -1)
        {
            return 0;
        }
        if(dp[index][curr] != -1)
        {
            return dp[index][curr];
        }
        
        int min_price = INT_MAX;
        
        for(int i = 0;i<costs[0].size();i++)
        {
            if(i!=curr)
            {
                int chose = costs[index][i] + minCostHelper(costs,dp,index-1,i);
                min_price = min(chose,min_price);
            }
        }
        
        dp[index][curr] = min_price;
        return dp[index][curr];
        
    }
    
    int minCost(vector<vector<int>>& costs) 
    {
        int n = costs.size();
        int m = costs[0].size();
        vector<vector<int>> dp(n,vector<int>(m+1,-1));
        return minCostHelper(costs,dp,n-1,m);
    }
//     int minCostHelper(vector<vector<int>>& costs, vector<vector<int>>& dp,int inx, int c)
//     {
//         if(inx == -1) return 0;
        
//         if(dp[inx][c] != -1) return dp[inx][c];
        
//         int min_price = INT_MAX;
//         for(int i=0; i<costs[0].size(); i++){
//             if(i != c){
//                 int chose = costs[inx][i] + minCostHelper(costs, dp,inx-1, i);
//                 min_price = min(min_price, chose);
//             }
//         }
//         return dp[inx][c] = min_price;
//     }
};
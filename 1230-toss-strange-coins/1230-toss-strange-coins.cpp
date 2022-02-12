class Solution {
public:
    
    double Helper(int index,vector<double> &prob,int target,vector<vector<double>> &dp)
    {
        if(target<0)
        {
            return 0;
        }
        
        if(index == prob.size())
        {
            if(target == 0)
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        
        if(dp[index][target]!=-1)
        {
            return dp[index][target];
        }
        
        double probability = Helper(index + 1,prob,target-1,dp) * prob[index];
        probability += (Helper(index+1,prob,target,dp) * (1-prob[index]));
        dp[index][target] = probability;
        return dp[index][target];
            
    }
    
    double probabilityOfHeads(vector<double>& prob, int target) 
    {
        int n = prob.size();
        vector<vector<double>> dp(n+1,vector<double>(target+1,-1));
        return Helper(0,prob,target,dp);
    }
    
};
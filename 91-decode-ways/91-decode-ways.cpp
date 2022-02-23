class Solution {
public:
    int decodeWays(int i,vector<int> &dp,string &s)
    {
        int n = s.size();
        if(i == n)
        {
            return dp[i] = 1;
        }
        if(s[i] == '0')
        {
            return dp[i] = 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        dp[i] = decodeWays(i+1,dp,s);
        if(i<(n-1) and (s[i] == '1' or s[i] == '2' and s[i+1]<'7'))
        {
            dp[i] += decodeWays(i+2,dp,s);
        }
        return dp[i];
    }
    int numDecodings(string s) 
    {
        if(s.size()==0)
        {
            return 0;
        }
        vector<int> dp(s.size()+1,-1);
        return decodeWays(0,dp,s);
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        if(prices.size()<1)
        {
            return 0;
        }
        int maxx = INT_MIN,minn = INT_MAX;
        for(int i = 0;i<prices.size();i++)
        {
            minn = min(prices[i],minn);
            maxx = max(prices[i]-minn,maxx);
        }
        return maxx;
    }
};
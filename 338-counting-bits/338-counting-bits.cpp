class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1,0);
        int temp = 1;
        
        for(int i = 1;i<=n;i++)
        {
            if(temp * 2 == i)
            {
                temp *= 2;
            }
            result[i] = result[i-temp] + 1;
        }
        return result;
    }
};
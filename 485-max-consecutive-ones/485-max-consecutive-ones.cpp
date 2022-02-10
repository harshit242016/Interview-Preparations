class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int beg = 0,end = 0;
        int maxLen = 0;
        
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]==0)
            {
                beg = i+1;
                end = i+1;
            }
            else
            {
                end++;
                maxLen = max(maxLen,end - beg);
                cout<<maxLen<<endl;
            }
        }
        return maxLen;
    }
};
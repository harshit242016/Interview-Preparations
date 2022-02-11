class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        int flag = 0;
        int count = 0;
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1] and flag!=1)
            {
                flag = 1;
                count++;
            }
            else if(nums[i]<nums[i-1] and flag!=-1)
            {
                flag = -1;
                count++;
            }
        }
        return count+1;
    }
};
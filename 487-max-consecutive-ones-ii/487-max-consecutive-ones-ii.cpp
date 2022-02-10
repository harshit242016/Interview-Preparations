class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxx = 0,zeroIncluded = 0,count = 0;
        for(int i = 0;i<nums.size();i++)
        {
            count++;
            
            if(nums[i]==0)
            {
                zeroIncluded = count;
                count = 0;
            }
            
            maxx = max(maxx,zeroIncluded+count);
        }
        return maxx;
    }
};
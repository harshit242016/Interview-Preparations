class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mp;
        int sum = 0,count = 0;
        for(int i = 0;i<nums.size();i++)
        {
            sum += nums[i]%2;
            if(sum == k)
            {
                count++;
            }
            count += mp[sum-k];
            mp[sum]++;
        }
        return count;
    }
};
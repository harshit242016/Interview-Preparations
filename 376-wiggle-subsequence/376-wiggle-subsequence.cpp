class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) 
    {
        stack<int> st;
        st.push(0);
        for(int i = 1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1] and st.top()!=1)
            {
                st.push(1);
            }
            else if(nums[i]<nums[i-1] and st.top()!=-1)
            {
                st.push(-1);
            }
        }
        return st.size();
    }
};
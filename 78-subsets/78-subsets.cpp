class Solution {
public:
    void findSubsets(vector<vector<int>> &mat,vector<int> &v,int curr, vector<int> &nums)
    {
        mat.push_back(v);
        for(int i = curr;i<nums.size();i++)
        {
            v.push_back(nums[i]);
            findSubsets(mat,v,i+1,nums);
            v.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> mat;
        vector<int> v;
        findSubsets(mat,v,0,nums);
        return mat;
    }
};
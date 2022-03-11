class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> result; //2d matrix
        
        if(nums.size()<=2)
        {
            return result;          //return empty matrix
        }
        
        sort(nums.begin(),nums.end());      //sort the array
        
        for(int i = 0;i<nums.size();i++)
        {
            int a = nums[i];        
            
            if(a>0)
                break;  
            
            if(i>0 and a==nums[i-1])
            {
                continue;
            }
            int left = i+1,right = nums.size()-1;
            while(left<right)
            {
                int b = nums[left];
                int c = nums[right];
                int sum = a+b+c;
                if(sum == 0)
                {
                    vector<int> v{a,b,c};
                    result.push_back(v);
                    while(left<right and b == nums[left])
                    {
                        left++;
                    }
                    while(left<right and c == nums[right])
                    {
                        right--;
                    }
                }
                else if(sum>0)
                {
                    right--;
                }
                else
                {
                    left++;
                }
            }
        }
        return result;
    }
};
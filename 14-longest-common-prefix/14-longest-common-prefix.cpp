class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        if(n == 0)
        {
            return "";
        }
        sort(strs.begin(),strs.end());
        string beg = strs[0];
        string dead = strs[n-1];
        string ans = "";
        for(int i = 0;i<beg.size();i++)
        {
            if(beg[i] == dead[i])
            {
                ans+=beg[i];
            }
            else
            {
                break;
            }
        }
        return ans;
    } 
};
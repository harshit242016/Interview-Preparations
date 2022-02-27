class Solution {
public:
    bool Helper(string &s, int start, unordered_set<string> st,vector<int> &memo)
    {
        if(start == s.size())
        {
            return true;
        }
        if(memo[start]!=-1)
        {
            return memo[start];
        }
        for(int i = start + 1;i<=s.size();i++)
        {
            string sub = s.substr(start,i-start);
            if(st.find(sub)!=st.end())
            {
                if(Helper(s,i,st,memo))
                {
                    memo[start] = 1;
                    return true;
                }
            }
        }
        memo[start] = 0;
        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string> st(wordDict.begin(),wordDict.end());
        vector<int> memo(s.size(),-1);
        return Helper(s,0,st,memo);
    }
};
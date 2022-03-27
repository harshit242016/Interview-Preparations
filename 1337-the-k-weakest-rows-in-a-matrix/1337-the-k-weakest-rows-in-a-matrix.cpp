class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) 
    {
        set<pair<int,int>> s;
        
        for(int i = 0;i<mat.size();i++)
        {
            auto summ = accumulate(mat[i].begin(),mat[i].end(),0);
            s.insert({summ,i});
        }
        vector<int> res;
        for(auto itr = s.begin();itr!=s.end();itr++)
        {
            k--;
            res.push_back(itr->second);
            if(k==0)
            {
                break;
            }
        }
        return res;
    }
};
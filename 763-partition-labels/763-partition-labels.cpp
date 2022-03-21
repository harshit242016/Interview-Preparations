class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        vector<int> maxpos(26,-1);
        for(int i = 0;i<s.size();i++)
        {
            maxpos[s[i] - 'a'] = i;
        }
        int maxIndex = -1,lastIndex = 0;
        vector<int> res;
        for(int i = 0;i<s.size();i++)
        {
            maxIndex = max(maxpos[s[i]-'a'],maxIndex);
            if(maxIndex == i)
            {
                res.push_back(maxIndex - lastIndex + 1);
                lastIndex = i+1;
            }
        }
        return res;
    }
};
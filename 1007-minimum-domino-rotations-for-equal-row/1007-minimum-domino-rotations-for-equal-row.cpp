class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        vector<int> countA(7,0);
        vector<int> countB(7,0);
        vector<int> same(7,0);
        
        for(int i = 0;i<tops.size();i++)
        {
            countA[tops[i]]++;
            countB[bottoms[i]]++;
            if(tops[i] == bottoms[i])
            {
                same[tops[i]]++;
            }
        }
        
        for(int i = 1;i<7;i++)
        {
            if(countA[i] + countB[i] - same[i] == tops.size())
            {
                return tops.size() - max(countA[i],countB[i]);
            }
        }
        return -1;
    }
};
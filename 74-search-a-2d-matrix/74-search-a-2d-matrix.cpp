class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size(), m = matrix.front().size();
        int ri = 0;
        int ci = m-1;
        while(ri<n and ci>=0)
        {
            if(matrix[ri][ci] == target)
            {
                return true;
            }
            else if(matrix[ri][ci] > target)
            {
                ci--;
            }
            else
            {
                ri++;
            }
        }
        return false;
    }
};
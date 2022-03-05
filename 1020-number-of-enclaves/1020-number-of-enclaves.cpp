class Solution {
public:
    int direction[6] = {0,1,0,-1,0};
    void dfsfill(vector<vector<int>> &grid,int x,int y,int &count)
    {
        if(x<0 or x==grid.size() or y <0 or y==grid[0].size() or grid[x][y] == 0)
        {
            return;
        }
        grid[x][y] = 0;
        count++;
        for(int i = 0;i<4;i++)
        {
            dfsfill(grid,x+direction[i],y+direction[i+1],count);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) 
    {
        int n = grid.size() ,m = grid[0].size();
        int r = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 1)
                    if(i == 0 or i == n-1 or j == 0 or j == m-1)
                    {
                        dfsfill(grid,i,j,r);
                    }
            }
        }
        int count = 0,res = 0;
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    count = 0;
                    dfsfill(grid,i,j,count);
                    res += count;
                }
            }
        }
        return res;
    }
};
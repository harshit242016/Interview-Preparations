class Solution {
public:
    int zeroes = 0,ans = 0;
    int dir[5] = {0,1,0,-1,0};
    void dfs(vector<vector<int>> &grid, int x,int y, int count)
    {
        if (x < 0 or x >= grid.size() or y < 0 or y >= grid[0].size() or grid[x][y] == -1)           {
            return;
        }
        
        if (grid[x][y] == 2) 
        {
            if(zeroes == count-1) 
                ans++; 
            
            return;
        }
        
        grid[x][y] = -1;
        
        for(int i = 0;i<4;i++)
        {
            dfs(grid,x + dir[i],y + dir[i+1],count+1);
        }
        
        grid[x][y] = 0;
        
    }
    int uniquePathsIII(vector<vector<int>>& grid) 
    {
        int sx, sy;
        
        for(int i = 0;i<grid.size();i++)
        {
            for(int j = 0;j<grid[0].size();j++)
            {
                if(grid[i][j] == 1)
                {
                    sx = i;
                    sy = j;
                }
                else if(grid[i][j] == 0)
                {
                    zeroes++;
                }
            }
        }
        //cout<<sx<<" "<<sy<<" "<<zeroes<<endl;
        dfs(grid,sx,sy,0);
        
        return ans;
    }
};
class Solution {
public:
    int dir[5] = {0,-1,0,1,0};
    
    int closedIsland(vector<vector<int>>& grid) 
    {
        int n = grid.size(),m = grid[0].size();
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(i == 0 or j == 0 or i == n-1 or j == m-1)
                {
                    if(grid[i][j] == 0)
                        dfs(grid,i,j);
                }
            }
        }
        
        int count = 0;
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(grid[i][j] == 0)
                {
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        
        return count;
    }
    
    void dfs(vector<vector<int>> &grid,int i,int j)
    {
        int n = grid.size() , m = grid[0].size();
        
          if(i<0 or i==n or j < 0 or j == m or grid[i][j]==1)  
          {
              return;
          }
        
          grid[i][j] = 1;
        
          for(int x = 0;x<4;x++)
          {
                dfs(grid,i+dir[x],j+dir[x+1]);
          }
    }
};
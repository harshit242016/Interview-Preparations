class Solution {
public:
    int n,m;
    int maxKilledEnemies(vector<vector<char>>& grid) 
    {
        n = grid.size();
        m = grid[0].size();
        
        int row[n][m],col[n][m];
        memset(row,0,sizeof(row));
        memset(col,0,sizeof(col));
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0,flag=0;j<m;j++)
            {
                if(grid[i][j] == 'E')
                {
                    flag++;
                }
                else if(grid[i][j] == 'W')
                {
                    flag = 0;
                }
                else
                {
                    row[i][j] += flag;
                }
            }
            for(int j = m-1,flag = 0;j>=0;j--)
            {
                if(grid[i][j] == 'E')
                {
                    flag++;
                }
                else if(grid[i][j] == 'W')
                {
                    flag = 0;
                }
                else
                {
                    row[i][j] += flag;
                }
            }
        }
        
        for(int j = 0;j<m;j++)
        {
            for(int i = 0,flag = 0;i<n;i++)
            {
                if(grid[i][j] == 'E')
                {
                    flag++;
                }
                else if(grid[i][j] == 'W')
                {
                    flag = 0;
                }
                else
                {
                    col[i][j] += flag;
                }
            }
            for(int i = n-1,flag = 0;i>=0;i--)
            {
                if(grid[i][j] == 'E')
                {
                    flag++;
                }
                else if(grid[i][j] == 'W')
                {
                    flag = 0;
                }
                else
                {
                    col[i][j] += flag;
                }
            }
        }
        
        
        int maxx = 0;
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                maxx = max(maxx,col[i][j] + row[i][j]);
            }
        }
        return maxx;
    }
    
};
class Solution {
public:
    int directions[5] = {0,1,0,-1,0};
    
    void helper(vector<vector<int>> &grid1,vector<vector<int>> &grid2,int x,int y,int &flag)
    {   
        int n = grid1.size();
        int m = grid1[0].size();
        
        if(x<0 or x == n or y<0 or y == m or grid2[x][y] == 0)
        {
            return;
        }
        
        if(grid2[x][y] != grid1[x][y])
        {
            flag = 1;
            return;
        }
        
        grid2[x][y] = 0;
        
        for(int i = 0;i<4;i++)
        {
            helper(grid1,grid2,x+directions[i],y+directions[i+1],flag);
        }

    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) 
    {
        int count = 0,flag = 0;
       
        for(int i = 0;i<grid1.size();i++)
        {
            for(int j = 0;j<grid1[0].size();j++)
            {
                if(grid2[i][j] == 1)
                {
                    flag = 0;
                    helper(grid1,grid2,i,j,flag);
                    if(flag == 0)
                    {
                        count++;
                    }
                }
            }
        }
        
        return count;
    }
};
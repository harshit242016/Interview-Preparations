class Solution {
public:
    vector<vector<bool>> pacific,atlantic;
    int n,m;
    
    vector<vector<int>> ans;
    int dir[5] = {0,1,0,-1,0};
    
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) 
    {
        n = heights.size();
        m = heights[0].size();
        
        pacific = atlantic = vector<vector<bool>> (n,vector<bool>(m,false));
         
        for(int i = 0;i<n;i++)
        {
            dfs(pacific,heights,i,0);
            dfs(atlantic,heights,i,m-1);
        }
        
        for(int i = 0;i<m;i++)
        {
            dfs(pacific,heights,0,i);
            dfs(atlantic,heights,n-1,i);
        }
        
        return ans;
    }
    
    void dfs(vector<vector<bool>> &visited,vector<vector<int>> &heights, int x, int y)
    {
        if(visited[x][y])
        {
            return;
        }
        visited[x][y] = true;
       //\U0001f9d0 
        if(pacific[x][y] && atlantic[x][y])
        {
            ans.push_back(vector<int>{x,y});
        }
        for(int i = 0;i<4;i++)
        {
            int nx = x+dir[i] , ny = y+ dir[i+1];
            if(nx<0 or nx>=n or ny<0 or ny>=m or heights[x][y]>heights[nx][ny])
            {
                continue;
            }
            dfs(visited,heights,nx,ny);
        }
    }
    
};
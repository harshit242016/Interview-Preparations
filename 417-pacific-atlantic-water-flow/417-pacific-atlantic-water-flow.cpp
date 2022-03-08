class Solution {
public:
    int m, n;

    vector<vector<bool> > atlantic, pacific;
	vector<vector<int> > ans;    
    
    int dx[5] = {0,1,0,-1,0};
    
    vector<vector<int> > pacificAtlantic(vector<vector<int>>& heights) 
    {
        m = heights.size(), n = heights[0].size();
        atlantic = pacific = vector<vector<bool> >(m, vector<bool>(n, false));
		// perform dfs from all edge cells (ocean-connected cells)
        for(int i = 0; i < m; i++) 
        {
            dfs(heights, pacific, i, 0); 
            dfs(heights, atlantic, i, n - 1);
        }
        
        for(int i = 0; i < n; i++) 
        {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, m - 1, i);
        }
        
        return ans;
    }
    
    void dfs(vector<vector<int>> &heights,vector<vector<bool>> &visited,int x,int y)
    {
        if(visited[x][y] == true)
        {
            return;
        }
        visited[x][y] = true;
        if(atlantic[x][y] && pacific[x][y])
        {
            ans.push_back(vector<int>{x,y});
        }
        
        int m = heights.size(), n = heights[0].size();
        
        for(int i=0; i<4; i++)
        {
            int nx = x+dx[i], ny = y+dx[i+1];
            if(nx<0 or nx>=m or ny<0 or ny>=n or heights[nx][ny] < heights[x][y]) 
            {
                continue;
            }
            dfs(heights,visited,nx, ny);
        }
    }
    
};
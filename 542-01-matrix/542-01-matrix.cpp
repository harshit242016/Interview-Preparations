class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) 
    {
        int n = mat.size() ;
        int m = mat[0].size();
        
        queue<pair<int,int>> q;
        vector<vector<int>> v(n,vector<int>(m,-1));
        
        int dir[5] = {0,-1,0,1,0};
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                if(mat[i][j] == 0)
                {
                    v[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int nx = x + dir[i];
                int ny = y + dir[i+1];
                if((nx<n and nx>=0 and ny<m and ny>=0) and v[nx][ny] == -1)
                {
                    v[nx][ny] = v[x][y] + 1;
                    q.push({nx,ny});
                }
            }
        }
        
        return v;
    }
};
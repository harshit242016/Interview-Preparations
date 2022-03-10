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
            pair<int,int> curr = q.front();
            q.pop();
            for(int i = 0;i<4;i++)
            {
                int a = curr.first + dir[i];
                int b = curr.second + dir[i+1];
                if((a<n and b<m and a>=0 and b>=0) and v[a][b] == -1)
                {
                    q.push({a,b});
                    v[a][b]=v[curr.first][curr.second]+1;
                }
            }
        }
        
        return v;
    }
};
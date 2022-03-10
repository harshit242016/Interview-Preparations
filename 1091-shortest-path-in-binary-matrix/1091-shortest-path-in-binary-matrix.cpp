class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) 
    {
        int n = grid.size();
        if(grid[0][0] != 0 or grid[n-1][n-1]!=0)
        {
            return -1;
        }
        grid[0][0] = 1;
        queue<pair<int,int>> q;
        q.push({0,0});
        int row[8] = {0,1,1,-1,-1,-1,0,1};
        int col[8] = {-1,0,-1,-1,0,1,1,1};
        int temp = 0;
        while(!q.empty())
        {
            temp++;
            int size = q.size();
            for(int i = 0;i<size;i++)
            {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                if(x == n-1 and y == n-1)
                {
                    return temp;
                }   
                
                for(int i = 0;i<8;i++)
                {
                    int r = x + row[i];
                    int c = y + col[i];
                    
                    if(r>=0 and r<n and c>=0 and c<n and grid[r][c] == 0)
                    {
                        grid[r][c] = 1;
                        q.push({r,c});
                    }
                }
            }
        }
        return -1;
    }
};
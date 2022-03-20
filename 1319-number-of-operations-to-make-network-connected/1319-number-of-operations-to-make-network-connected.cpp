class Solution {
public:
    void dfs(vector<vector<int>> &matrix, vector<bool> &visited,int src)
    {
        visited[src] = true;
        
        for(auto x : matrix[src])
        {
            if(!visited[x])
            {
                dfs(matrix,visited,x);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) 
    {
        if(connections.size() < n-1)
        {
            return -1;
        }
        vector<vector<int>> matrix(n);
        for(auto v : connections)
        {
            matrix[v[0]].push_back(v[1]);
            matrix[v[1]].push_back(v[0]);
        }
        vector<bool> visited(n,false);
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            if(!visited[i])
            {
                count++;
                dfs(matrix,visited,i);
            }
        }
        
        return count - 1;
        
    }
};
class Solution {
public:
    
    vector<int> adj[100009];
    int visited[100009];
    
    int dfs(int headID,vector<int> &info)
    {
        int time=0;
        visited[headID]=1;
        for(auto x:adj[headID])
        {
            if(visited[x])
            {
                continue;
            }
            time = max(time,dfs(x,info));
        }
        
        return time+info[headID];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) 
    {
        for(int i=0;i<manager.size();i++)
        {
            if(manager[i] == -1)
            {
                continue;
            }
            adj[i].push_back(manager[i]);
            adj[manager[i]].push_back(i);
        }
        
        return dfs(headID,informTime);
    }
    
};
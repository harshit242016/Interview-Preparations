class Solution {
public:
    void dfs(vector<vector<int>> &rooms,bool *visited,int x)
    {
        visited[x] = true;
        for(int i = 0;i<rooms[x].size();i++)
        {
            if(!visited[rooms[x][i]])
                dfs(rooms,visited,rooms[x][i]);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) 
    {
        bool visited[rooms.size()];
        memset(visited,false,sizeof(visited));

        dfs(rooms,visited,0);
        
        for(int i = 0;i<rooms.size();i++)
        {
            if(visited[i]==0)    
            {
                return false;
            }
        }
        return true;
    }
};
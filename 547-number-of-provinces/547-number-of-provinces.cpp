class Solution {
public:
    void dfs(vector<vector<int>> &isConnected,bool *visited,int temp)
    {
        visited[temp] = true;
        for(int j = 0;j<isConnected.size();j++)
        {
            if(isConnected[temp][j] == 1 and visited[j] == 0)
            {
                dfs(isConnected,visited,j);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) 
    {
        int count_province = 0;
        bool visited[isConnected.size()+1];
        memset(visited,false,sizeof(visited));
        for(int i = 0;i<isConnected.size();i++)
        {
            if(visited[i] == 0)
            {
                dfs(isConnected,visited,i);
                count_province++;
            }
        }
        return count_province;
    }
};
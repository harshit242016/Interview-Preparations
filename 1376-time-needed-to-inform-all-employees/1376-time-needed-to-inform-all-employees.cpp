class Solution {
public:
    vector<int>g[100009],info;
    int vis[100009];
    
    int dfs(int node){
        int t=0;
        vis[node]=1;
        for(auto x:g[node]){
            if(vis[x])continue;
            t=max(t,dfs(x));
        }
        return t+info[node];
    }
    
    int numOfMinutes(int n, int headID, vector<int>& v, vector<int>& informTime) {
        this->info=informTime;
        for(int i=0;i<v.size();i++){
            if(v[i]==-1)continue;
            g[i].push_back(v[i]);
            g[v[i]].push_back(i);
        }
        return dfs(headID);
    }
};
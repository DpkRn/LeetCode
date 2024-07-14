class Solution {
public:
    vector<vector<int>> ans;
    vector<int> time;
    vector<int> low;
    vector<int> vis;
    //vector<par
   int timer=1;
    void dfs(int u,int par,vector<int> adj[]){
        vis[u]=1;
        low[u]=timer;
        time[u]=timer;
         timer++;
        for(auto v:adj[u]){
            if(par==v) continue;
                if(!vis[v]){
                    dfs(v,u,adj);
                    low[u]=min(low[v],low[u]);
                    if(time[u]<low[v]){
                    ans.push_back({u,v});
                }
            }else{
                //low[u]=min(low[u],time[u]); this can also work
                low[u]=min(low[u],time[v]);
            }
        }  
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int> adj[n];
        time.resize(n,-1);
        low.resize(n,-1);
        vis.resize(n,0);
        for(auto it:connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int timer=0;
        dfs(0,-1,adj);
        return ans;
    }
};
class Solution {
public:
    void dfs(int u,auto &ans,vector<int> adj[],int p,vector<int> &vis){
        for(auto v:adj[u]){
            if(!vis[v]){
                ans[p].push_back(v);
                vis[v]=1;
                dfs(v,ans,adj,p,vis);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto edge:edges){
            adj[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>> ans(n);
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            dfs(i,ans,adj,i,vis);
            sort(ans[i].begin(),ans[i].end());
        }
        return ans;
        
    }
};
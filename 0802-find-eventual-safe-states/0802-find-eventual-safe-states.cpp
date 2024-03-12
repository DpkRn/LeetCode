class Solution {
public:
    bool dfs(int node,vector<vector<int>> &adj,vector<int> &vis,vector<int> &path){
        vis[node]=1;
        path[node]=1;
        for(auto adjNode:adj[node]){
            //node has not been visited then
            if(!vis[adjNode]){
                if(dfs(adjNode,adj,vis,path)) return true;
            }else 
            //node has already in path then
            if(path[adjNode]==1) return true;
        }
        path[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> states;
        int n=graph.size();
        for(int i=0;i<n;i++){
            vector<int> vis(n,0);
            vector<int> path(n,0);
            if(dfs(i,graph,vis,path)) 
            continue;
            states.push_back(i);
        }
        return states;
    }
};
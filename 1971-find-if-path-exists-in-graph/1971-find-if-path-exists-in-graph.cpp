class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int destination) {
        vector<int> adj[n];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        queue<int> q;
        vector<int> vis(n,0);
        q.push(src);
        vis[src]=1;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            if(node==destination) return true;
            for(auto it:adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return false;
    }
};
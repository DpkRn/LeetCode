class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
         unordered_map<int,vector<int>>adj;
        vector<int> indeg(n);
        vector<int>ans;
        queue<int>q;
        if(n==1){
            return {0};   
        }
        for (auto &edge:edges){
            int u=edge[0];
            int v=edge[1];
            indeg[u]++;
            indeg[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<n;i++){
            if(indeg[i]==1){
                q.push(i);
            }
        }
        while(n>2){
            int size=q.size();
            n=n-size;
            while(size--){
                int u=q.front();
                q.pop();
                for(auto x: adj[u]){
                    indeg[x]--;
                    if(indeg[x]==1){
                        q.push(x);
                    }
                }
            }
        }
        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }
    return ans;
    }
};
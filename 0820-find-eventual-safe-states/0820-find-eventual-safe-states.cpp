class Solution {
public:
    //using bfs(kahn's algorithm or topoSort)
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> adj[n];
        int indegree[n];
        memset(indegree,0,sizeof(indegree));
        for(auto i=0;i<n;i++){
            for(auto it:graph[i]){
                indegree[i]++;
                adj[it].push_back(i);
            }
        }
        queue<int> q;
       for(int i=0;i<n;i++){
           if(indegree[i]==0) q.push(i);
       }
        vector<int> ans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(auto it:adj[node]){
                indegree[it]--;
                if(indegree[it]==0) q.push(it);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
//USING DFS
/*
bool dfs(int src,vector<vector<int>>&graph,int vis[],int path[],int isState[]){
        vis[src]=1;
        path[src]=1;
        isState[src]=0;
        for(auto it:graph[src]){
            if(!vis[it]){
                if(dfs(it,graph,vis,path,isState)) 
                {
                    isState[src]=0;
                   // path[src]=0;
                    return true; 
                }
            }else{
                if(path[it]){
                    isState[src]=0;
                   // path[src]=0;
                    return true; ;
                }
            }
        }
        path[src]=0;
        isState[src]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();

        int vis[n];
        int path[n];
        int isState[n];
        for(int i=0;i<n;i++){
                vis[i]=0;
            path[i]=0;
            isState[i]=0;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,graph,vis,path,isState);
            }
        }
     vector<int> vec;
        for(int i=0;i<n;i++){
            if(isState[i]){
                vec.push_back(i);
            }
        }
        return vec;
    }
*/
class Solution {
public:
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
};
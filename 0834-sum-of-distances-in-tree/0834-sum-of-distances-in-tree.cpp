
//child[node]=total child connected including node only downwards
//ans[node]=child[it]+ans[it];

class Solution {
public:
     vector<int> child;
     vector<int> ans;
     vector<int> vis;
    int N;
    int dfsGet(int node,vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
               child[node]+=dfsGet(it,adj); 
               ans[node]+=child[it]+ans[it];
            }
        }
        return child[node];
    }
    
    void dfsFromTop(int node,vector<int> adj[]){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                                //remaining ans except down      + no of child except down  +  only down ans including it    
                //    ans[it]=     ans[node]-(ans[it]+child[it]) +    (N - child[it] )      +     ans[it];      after simplifying becomes below
                ans[it]=ans[node]-2*child[it]+N; 
                dfsFromTop(it,adj);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        N=n;
        child=vector<int> (n,1);
        ans=vector<int> (n,0);
        vector<int> adj[n];
        for(auto el:edges){
            adj[el[0]].push_back(el[1]);
            adj[el[1]].push_back(el[0]);
        }
        vis=vector<int>(n,0);
       
        dfsGet(0,adj);
        for(auto it:child) cout<<it<<" ";
        cout<<endl;
        for(auto it:ans) cout<<it<<" ";
         for(int i=0;i<n;i++) vis[i]=0;
        dfsFromTop(0,adj);
        return ans;
    }
};
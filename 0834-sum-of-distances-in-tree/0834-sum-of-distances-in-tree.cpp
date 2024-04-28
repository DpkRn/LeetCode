class Solution {
public:
    vector<int> cnt;
    vector<int> ans;
    int N;
    void dfs(int node,vector<int> adj[],int par){
        for(auto child:adj[node]){
            if(child!=par){
                dfs(child,adj,node);
                cnt[node]+=cnt[child];
                ans[node]+=ans[child]+cnt[child];
            }
        }
    }
    void dfs1(int node,vector<int> adj[],int par){
        for(auto child:adj[node]){
           if(par!=child){
                ans[child]=ans[node]-cnt[child]+(N-cnt[child]);
                dfs1(child,adj,node);
           }          
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        N=n;
        for(auto it:edges){     
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);            
        }
        cnt=vector<int>(n,1);
        ans=vector<int>(n,0);
    
        dfs(0,adj,-1);
        dfs1(0,adj,-1);
        // for(auto it:ans)
        //     cout<<it<<" ";
       
    return ans;
    }
    
};
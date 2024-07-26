class Solution {
public:
    void findDist(int src,vector<vector<int>> adj[],vector<vector<int>> &dist){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,src});
        while(!pq.empty()){
            int u=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            for(auto it:adj[u]){
                if(d+it[1]<dist[src][it[0]]){
                    dist[src][it[0]]=d+it[1];
                    pq.push({dist[src][it[0]],it[0]});
                }
            }
        }
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adj[n];
        for(auto vec:edges){
            adj[vec[0]].push_back({vec[1],vec[2]});
            adj[vec[1]].push_back({vec[0],vec[2]});
        }
        
        vector<vector<int>>dist(n,vector<int> (n,1e8));
        for(int i=0;i<n;i++){
                dist[i][i]=0;
        }
        for(int i=0;i<n;i++){
            findDist(i,adj,dist);
        }
        vector<bool> cnt(n,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dist[i][j]<<" ";
            }
            cout<<endl;
        }
        int ans=-1;
       int mini=n;
        for(int i=0;i<n;i++){
             int city=0;
            for(int j=0;j<n;j++){
                if(i!=j&&dist[i][j]<=distanceThreshold) city++;
            }
           if(city<=mini){
               ans=i;
               mini=city;
           }
        }
        return ans;
        
        
    }
};
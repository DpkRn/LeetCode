 class disjoint{
    vector<int> rank;
   
    vector<int> parent;
    public:
    disjoint(int n){
        rank.resize(n+1,0);
       
        parent.resize(n+1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParent(int u){
        if(parent[u]==u) return u;
        return parent[u]=findParent(parent[u]);
    }
    void unionByRank(int u,int v){
        int ulp=findParent(u);
        int vlp=findParent(v);
        if(ulp==vlp) return;
        if(rank[ulp]<rank[vlp]){
            parent[ulp]=vlp;
        }else if(rank[ulp]>rank[vlp]){
            parent[vlp]=ulp;    
        }else{
            parent[vlp]=ulp;
            rank[ulp]++;
        }
    }

    bool isComponent(int u,int v){
        if(findParent(u)==findParent(v)) return true;
        return false;
    }
    vector<int> getParent(){
        return parent;
    }
    
};
class Solution {
public:
   
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        disjoint dsu(n);
        vector<pair<int,int>> edges;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i!=j&&isConnected[i][j]==1){
                    edges.push_back({i+1,j+1});
                }
            }
            
        }
        for(int i=0;i<edges.size();i++){
            cout<<edges[i].first<<" "<<edges[i].second<<endl;
        }
        for(auto it:edges){
            dsu.unionByRank(it.first,it.second);
        }
        int cnt=0;
        for(int i=0;i<=n;i++){
            dsu.findParent(i);
        }
        vector<int> parent=dsu.getParent();
        for(auto it:parent){
            cout<<it<<" ";
        }
        int mp[n+1];
        memset(mp,0,sizeof(mp));
       
        for(int i=1;i<=n;i++){
            mp[parent[i]]=1;
            
        }
        
        for(int i=0;i<=n;i++){
            if(mp[i]) cnt++;
        }
        return cnt;
    }
};
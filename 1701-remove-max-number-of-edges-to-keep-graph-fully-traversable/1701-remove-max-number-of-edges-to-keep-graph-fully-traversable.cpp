class DSet{
    public:
    vector<int> size;
    vector<int> par;
    DSet(int n){
        size.resize(n+1,0);
        par.resize(n+1);
        for(int i=0;i<=n;i++) par[i]=i;
    }
    int findParent(int node){
        if(node==par[node]) return node;
        return par[node]=findParent(par[node]);
    }
    bool join(int u,int v){
        u=findParent(u);
        v=findParent(v);
        if(u==v) return false;
        if(size[u]<size[v]) swap(u,v);
            par[v]=par[u];
            size[u]+=size[v];
        return true;
        
    }
};
class Solution {
public:
    
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSet alice(n+1),bob(n+1);
        int edge=0;
        int cmpA=n,cmpB=n;
        sort(edges.begin(),edges.end(),[&](vector<int> a,vector<int> b){return a[0]>b[0];});
        for(auto it:edges){
          if(it[0]==3){ 
              //for alice and bob only one edge of type 3 need
            bool added=alice.join(it[1],it[2]);
            bob.join(it[1],it[2]);
              if(added==1){
                   cmpA--; cmpB--;
                  edge++;
              }
              //componenet also be decreased by one by one
          }
          if(it[0]==1){
              bool added=alice.join(it[1],it[2]);
              if(added){ edge++,cmpA--;}
          }
         if(it[0]==2){
              bool added=bob.join(it[1],it[2]);
              if(added){ edge++,cmpB--;}
          }
        }
       
        if(cmpA!=1||cmpB!=1) return -1;
        return edges.size()-edge;
        
    }
};
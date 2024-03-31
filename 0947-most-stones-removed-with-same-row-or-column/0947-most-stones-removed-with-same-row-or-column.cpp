class disjointSet{
    public:
    vector<int> size;
    vector<int> parent;
    
    disjointSet(int n){
        size.resize(n,1);
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i]=i;
    }
    
    int findUPar(int node){
        if(parent[node]==node) return node;
        return parent[node]=findUPar(parent[node]);
    }
    void unionBySize(int u,int v){
        int epu=findUPar(u);
        int epv=findUPar(v);
        if(epu==epv) return;
        if(size[epu]<size[epv]){
            parent[epu]=epv;
            size[epv]+=size[epu];
        }else{
             parent[epv]=epu;
            size[epu]+=size[epv];
        }
    }
   
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        
        int maxRow=0;
        int maxCol=0;
       
        unordered_map<int,int> mp;
        for(auto it:stones){
            maxRow=max(maxRow,it[0]);
            maxCol=max(maxCol,it[1]);
          
        }
        
  
        int n=maxRow+maxCol+2;
        disjointSet dsu(n);
        for(auto it:stones){
           
            dsu.unionBySize(it[0],it[1]+maxRow+1);
            mp[it[0]]=1;
            mp[it[1]+maxRow+1]=1;
        }
        int nofC=0;
    
        for(auto it:mp){
        
            if(dsu.findUPar(it.first)==it.first){
                nofC++;
            }
        }
        return stones.size()-nofC;
    }
};
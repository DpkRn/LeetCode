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
    int makeConnected(int n, vector<vector<int>>& connections) {
        disjointSet dsu(n);
        int cnt=0;
        for(auto it:connections){
            if(dsu.findUPar(it[0])==dsu.findUPar(it[1])) cnt++;
            else dsu.unionBySize(it[0],it[1]);
        }
        
        int noOfComponents=0;
        for(int i=0;i<n;i++) if(dsu.parent[i]==i) noOfComponents++;
         int reqEdge=noOfComponents-1;
        if(reqEdge<=cnt) return reqEdge;
        else return -1;
    }
};
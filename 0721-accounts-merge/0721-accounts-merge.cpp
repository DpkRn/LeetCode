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
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        disjointSet dsu(n);
        map<string,int> mp;
        for(int i=0;i<n;i++){
            for(auto j=1;j<accounts[i].size();j++){
                if(mp.find(accounts[i][j])==mp.end()){
                   mp[accounts[i][j]]=i; 
                }else{
                    dsu.unionBySize(mp[accounts[i][j]],i);
                }
            }
        }
       
      
        
        vector<string> ans[n]; 
        for(auto it:mp){
            string email=it.first;
            int ind=it.second;
            int parent=dsu.findUPar(ind);
            ans[parent].push_back(email);
            
        }
        
       vector<vector<string>> result;      
       for(int i=0;i<n;i++){
            if(ans[i].size()>0){
                   vector<string> temp;
                   temp.push_back(accounts[i][0]);
                
                   for(int j=0;j<ans[i].size();j++){
                      temp.push_back(ans[i][j]);
                   }
                 result.push_back(temp);
               }
          
          
       }
        return result;
    }
};
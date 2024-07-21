class Solution {
public:
    vector<int> topo(vector<vector<int>> &adj,int k){
        vector<int> enq(k+1,0);
        vector<int> ans;

        for(int i=0;i<=k;i++){
            for(auto it:adj[i]){
                enq[it]++;
            }
        }

        queue<int> q;
        for(int i=1;i<=k;i++){
            if(enq[i]==0) q.push(i);
        }

        
        while(!q.empty()){
            int u=q.front();
            q.pop();
            ans.push_back(u);
            for(auto it:adj[u]){
                enq[it]--;
                if(enq[it]==0)
                q.push(it);
            }
        }

        for(int i=1;i<=k;i++) if(enq[i]!=0) return {};
        return ans;

    }

    vector<vector<int>> buildGraph(int k,vector<vector<int>>& conditions){
        vector<vector<int>> adj(k+1);
        for(auto it:conditions){
            adj[it[0]].push_back(it[1]);
        }

        return adj;
    }

    void fillArray(int k,vector<int> &vec){
        unordered_map<int,bool> mp;
        for(auto it:vec){
            mp[it]=true;
        }
        
        for(int i=1;i<=k;i++){
            if(mp[i]==0) vec.push_back(i);
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> ans(k,vector<int>(k,0));

        vector<vector<int>> adjRow=buildGraph(k,rowConditions);
        vector<vector<int>> adjCol=buildGraph(k,colConditions);

        vector<int> rowTopo=topo(adjRow,k);
        vector<int> colTopo=topo(adjCol,k);

        if(rowTopo.size()==0||colTopo.size()==0) return {};
        fillArray(k,rowTopo);
        fillArray(k,colTopo);

        unordered_map<int,int> colInd;
        for(int col=0;col<k;col++){
                colInd[colTopo[col]]=col;
        }
        

        for(int i=0;i<k;i++){
            ans[i][colInd[rowTopo[i]]]=rowTopo[i];
        }

        return ans;
    }
};
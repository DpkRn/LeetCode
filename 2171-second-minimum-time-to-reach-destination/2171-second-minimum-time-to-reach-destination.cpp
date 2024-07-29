#define P pair<int,int>
class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
         vector<vector<int>> adj(n+1);
        for (auto& e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        vector<int> d1(n+1, INT_MAX),d2(n+1,INT_MAX);
        d1[1]=0;
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,1});
        while(!pq.empty()){
            auto [cTime,node]=pq.top();
            cout<<cTime<<" "<<node<<endl;
            pq.pop();
            int div=cTime/change;
            if(div%2==1)
            cTime=(div+1)*change;
            if(node==n&&d2[node]!=INT_MAX) return d2[node];
            for(auto &v:adj[node]){
                int newtime=cTime+time;
                if(newtime<d1[v]){
                    d2[v]=d1[v];
                    d1[v]=cTime+time;
                    pq.push({d1[v],v});
                }else if(newtime>d1[v]&&newtime<d2[v]){
                    d2[v]=cTime+time;
                    pq.push({d2[v],v});
                }
            }
        }
       
        
        return -1;

        
    }
};
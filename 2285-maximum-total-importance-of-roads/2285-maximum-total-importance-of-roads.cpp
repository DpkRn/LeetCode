#define ll long long
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<ll> enq(n,0);
        for(auto it:roads){
            enq[it[0]]++;
            enq[it[1]]++;
        }
        sort(enq.begin(),enq.end());
        ll sum=0;
        for(int i=0;i<n;i++){
            sum=sum+enq[i]*(i+1);
        }
        return sum;
    }
};
class Solution {
public:
    int fun(int k,int r,string key,string ring,auto &dp){
       if(k>=key.size()) return 0;
        if(dp[k][r]!=-1) return dp[k][r];
        int clock=0;
        for(int i=r;;i++){
            if(i==ring.size()) i=0;
            if(key[k]==ring[i]){
               clock+=(1+fun(k+1,i,key,ring,dp));
               break;
            }
            clock++;
        }
        int anti=0;
        for(int i=r;;i--){
            if(i==-1) i=ring.size()-1;
            if(ring[i]==key[k]){
                anti+=(1+fun(k+1,i,key,ring,dp));
                break;
            }
            anti++;
        }
        return dp[k][r]=min(anti,clock);
        
    }
    int findRotateSteps(string ring, string key) {
        int n=ring.size();
        int k=key.size();
        
        vector<vector<int>> dp(k,vector<int>(n,-1));
        return fun(0,0,key,ring,dp);
    }
};
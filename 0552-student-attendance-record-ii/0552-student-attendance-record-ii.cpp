class Solution {
public:
    const int mod=(int)1e9+7;
    int dfs(int n,int cnta,int cntl, vector<vector<vector<int>>> &dp){
        if(n==0) return 1;
        if(dp[n][cnta][cntl]!=-1) return dp[n][cnta][cntl];
        long long ans=0;
        // for P
        ans=dfs(n-1,cnta,0,dp);
        
        //for A
        if(cnta<1){
            ans+=dfs(n-1,cnta+1,0,dp);
        }
        
        //for L
        if(cntl<2)
            ans+=dfs(n-1,cnta,cntl+1,dp);
        
        return dp[n][cnta][cntl]=ans%mod;
    }
    int checkRecord(int n) {
     vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,-1)));
      return dfs(n,0,0,dp);  

        
    }
};
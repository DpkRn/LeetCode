class Solution {
public: 
    const int mod=1e9+7;
    // int f(int i,int j,string &s,string &t,auto &dp){
    //     if(j<0) return 1;
    //     if(i<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==t[j]) return dp[i][j]=(f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp))%mod;
    //     else
    //     return dp[i][j]=f(i-1,j,s,t,dp)%mod;
    // }
    int numDistinct(string s, string t) {
        int n=s.size();
        int m=t.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return f(n-1,m-1,s,t,dp);               
        vector<vector<int>> dp(n+1,vector<int>(m+1,0)); //no of subsequences in s[0..n] of t[0...m]
        for(auto i=0;i<=n;i++){
            dp[i][0]=1; //if any time we if we are not taking t then 1 matching subsequence that is ""; nothing
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%mod;
                else dp[i][j]=dp[i-1][j]%mod;
            }
        }
        return dp[n][m];
    }
};
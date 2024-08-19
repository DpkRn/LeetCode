class Solution {
 public:
//     int dfs(int i,int n,int l,auto &dp){
//         if(i==n){
//             return 0;
//         }
//         if(dp[i][l]!=-1) return dp[i][l];
//         if(i>n) return 1e9;
//         int left=2+dfs(2*i,n,i,dp);
//         int right=1+dfs(i+l,n,l,dp);
//         return dp[i][l]=min(left,right);
//     }
    int minSteps(int n) {
        if(n==1) return 0; 
        // vector<vector<int>> dp(2*n+1,vector<int>(n+1,-1));
        // return dfs(1,n,1,dp)+1;

        vector<vector<int>> dp(n+1,vector<int>(n+1,1e9));
        for(int i=0;i<n;i++)
        dp[n][i]=0;
            for(int i=n-1;i>=1;i--){
                for(int l=n;l>=1;l--){
                    dp[i][l]=(2*i>n)?1e9:2+dp[2*i][i];
                    dp[i][l]=(i+l>n)?1e9:min(dp[i][l],1+dp[i+l][l]);
                }
            }
            return 1+dp[1][1];
        
    }
};
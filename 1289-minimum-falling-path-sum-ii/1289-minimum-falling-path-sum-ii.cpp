class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        
        int n=grid.size();
        if(n==1) return grid[0][0];
        vector<vector<int>> dp(n+1,vector<int>(n,1e9));
        
        fill(dp[0].begin(),dp[0].end(),0);
        
        for(int i=1;i<=n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(k!=j){
                        dp[i][j]=min(dp[i][j],grid[i-1][j]+dp[i-1][k]);
                    }
                }
            }
        }
        return *min_element(dp[n].begin(),dp[n].end());
    }
};
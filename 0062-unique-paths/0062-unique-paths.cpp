int fun(int i, int j, int m, int n, vector<vector<int>>& dp){
    
    if(i>=m or j>=n) return 0;
    if(i==m-1 and j==n-1) return 1;
    if(dp[i][j]!=-1) return dp[i][j];
    int bot=fun(i+1,j,m,n,dp);
    int right=fun(i,j+1,m,n,dp);
    return dp[i][j]=bot+right;
    
}
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return fun(0,0,m,n,dp);
    }
};
int fun(int i, int j, int m, int n, vector<vector<int>>& mat, vector<vector<int>>& dp){
    
    if(i>=m or j>=n or mat[i][j]==1) return 0;
    if(i==m-1 and j==n-1) return 1;
    // if(mat[i][j]==1) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    int bot=fun(i+1,j,m,n,mat,dp);
    int right=fun(i,j+1,m,n,mat,dp);
    return dp[i][j]=bot+right;
    
}

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return fun(0,0,m,n,obstacleGrid,dp);
    }
};
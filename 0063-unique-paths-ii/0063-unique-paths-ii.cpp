class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
         int m=obstacleGrid.size();
         int n=obstacleGrid[0].size();
        const int mod=2*1e9;
         vector<vector<long long>> dp(m, vector<long long>(n,0));
        for(int r=m-1;r>=0;r--){
            for(int c=n-1;c>=0;c--){
                if(r==m-1&&c==n-1 && !(obstacleGrid[r][c]==1) ){ dp[r][c]=1; continue;}
                if(obstacleGrid[r][c]==1) { dp[r][c]=0; continue;}
                long long right=0;
                long long bot=0;
                if(c+1<=n-1) right=dp[r][c+1];
                if(r+1<=m-1) bot=dp[r+1][c];
                dp[r][c]=(bot%mod+right%mod)%mod;
                
            }
        }
        return dp[0][0];      
    }
};

/*int fun(int r, int c, int m, int n, vector<vector<int>>& mat, vector<vector<int>>& dp){
    
    if(r>=m or c>=n or mat[r][c]==1) return 0;
    if(r==m-1 and c==n-1) return 1;
    if(dp[r][c]!=-1) return dp[r][c];
    int bot=fun(r+1,c,m,n,mat,dp);
    int right=fun(r,c+1,m,n,mat,dp);
    return dp[r][c]=bot+right;
    
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
*/

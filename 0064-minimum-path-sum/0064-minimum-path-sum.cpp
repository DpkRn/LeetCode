class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
         int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        for(int r=m-1;r>=0;r--){
            for(int c=n-1;c>=0;c--){
                if(r==m-1&&c==n-1) {dp[r][c]=grid[r][c]; continue;}
                int right=INT_MAX;
                int down=INT_MAX;
                if(c+1<=n-1) right=grid[r][c]+dp[r][c+1];
                if(r+1<=m-1) down=grid[r][c]+dp[r+1][c];
                dp[r][c]=min(right,down);
            }
        }
        return dp[0][0];
    }
};
/*
class Solution {
public:
    int f(int r,int c,vector<vector<int>>& grid,int m,int n,vector<vector<int>> &dp){
        if(r==m-1&&c==n-1) return grid[r][c];
        if(dp[r][c]!=-1) return dp[r][c];
        int right=INT_MAX;
        int down=INT_MAX;
        if(c+1<=n-1)
         right=grid[r][c]+f(r,c+1,grid,m,n,dp);
        if(r+1<=m-1)
         down=grid[r][c]+f(r+1,c,grid,m,n,dp);
        return dp[r][c]=min(right,down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return f(0,0,grid,m,n,dp);
    }
};

*/
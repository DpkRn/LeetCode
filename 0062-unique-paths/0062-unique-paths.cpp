class Solution {
    int f(int r,int c,int m,int n,vector<vector<int>>&dp){
        if(r>=m||c>=n) return 0;
        if(dp[r][c]!=-1) return dp[r][c];
        if(r==m-1&&c==n-1) return 1;
        int bot=f(r+1,c,m,n,dp);
        int right=f(r,c+1,m,n,dp);
        
        return dp[r][c]=bot+right;
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return f(0,0,m,n,dp);
    }
};
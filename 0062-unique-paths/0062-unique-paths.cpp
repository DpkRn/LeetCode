class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n,0);
        int rt=0;
        for(int r=m-1;r>=0;r--){    
            for(int c=n-1;c>=0;c--){
                if(r==m-1&&c==n-1) {dp[n-1]=1;rt=1; continue;}
                int bot=0;
                int right=0;
                if(c+1<=n-1)
                right=rt;
                if(r+1<=m-1)
                bot=dp[c];
                dp[c]=bot+right;
                rt=dp[c];                
            }           
        }
        return dp[0];
    }
};

/*class Solution {
public:
    int uniquePaths(int m, int n) {
         vector<vector<int>>dp(m,vector<int>(n,0));
        dp[m-1][n-1]=1;
        for(int r=m-1;r>=0;r--){    
            for(int c=n-1;c>=0;c--){
                if(r==m-1&&c==n-1) {dp[r][c]=1; continue;}
                int bot=0;
                int right=0;
                if(r+1<=m-1)
                bot=dp[r+1][c];
                if(c+1<=n-1)
                right=dp[r][c+1];
                 dp[r][c]=bot+right;
            }
           
        }
        return dp[0][0];
    }
};
*/

/*
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
*/
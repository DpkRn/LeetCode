class Solution {
    // int f(int i,int j,string &s,string &t,auto &dp){
    //     if(i<0&&j<0) return 1;
    //     if(i<0){
    //         while(j>=0){
    //             if(t[j]!='*') return false;
    //             j--;
    //         }
    //          return true;
    //     } else if(j<0) return false;
    //    if(dp[i][j]!=-1) return dp[i][j];
    //     if(s[i]==t[j]||t[j]=='?') return dp[i][j]=f(i-1,j-1,s,t,dp);
    //     else if(t[j]=='*') return dp[i][j]=f(i,j-1,s,t,dp)||f(i-1,j,s,t,dp);
    //     else return dp[i][j]=false;
    // }
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int m=p.size();
        // vector<vector<int>> dp(n,vector<int> (m,-1));
        // return f(n-1,m-1,s,p,dp);
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        dp[0][0]=1;
        for(int i=1;i<=m;i++){
            if(p[i-1]=='*') dp[0][i]=1;
            else break;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==p[j-1]||p[j-1]=='?') dp[i][j]=dp[i-1][j-1];
                else if(p[j-1]=='*') dp[i][j]=dp[i-1][j]||dp[i][j-1];
                else dp[i][j]=0;                
            }
        }
        return dp[n][m];  
    }
};
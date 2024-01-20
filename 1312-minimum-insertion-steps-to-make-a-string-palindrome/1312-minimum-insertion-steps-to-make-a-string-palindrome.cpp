class Solution {
public:
    //to make a "mdbdm" in palindrome we need to search longest palindrome so that minm    replacement i ll have to do
    int lcs_palindrome(string s){
        string t=s;
        reverse(s.begin(),s.end());
        int n=s.size(); 
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
            }
        }
        return dp[n][n];
    }
    int minInsertions(string s) {
        return s.size()-lcs_palindrome(s);
    }
};
class Solution {
public:
    //we can only delete so to make same we can only remove in both string so to minimize
    //operation we need to remove as minimum as possible
    //alternate way if i find the longest common subsequence then that will be maximum 
    //character equal in both character so only few characters have to be remove in both
    // i.e (s1.size-lcs)+(s2.size-lcs)
    int lcs(string &s,string &t){
        int n=s.size();
        int m=t.size();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s[i-1]==t[j-1]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
    int minDistance(string word1, string word2) {
        return word1.size()+word2.size()-2*lcs(word1,word2);
    }
};
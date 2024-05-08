class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
      //optimised
        vector<int> prev(n2+1,0);
        vector<int> curr(n2+1,0);
        prev[0]=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1])
                    curr[j]=1+prev[j-1];
                else curr[j]=max(prev[j],curr[j-1]);
            }
            prev=curr;
        }
        return prev[n2];
    }
};

/*
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
        dp[0][0]=0;
        for(int i=1;i<=n1;i++){
            for(int j=1;j<=n2;j++){
                if(text1[i-1]==text2[j-1])
                    dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        // for(auto it:dp){
        //     for(auto el:it) cout<<el<<" "; cout<<endl;
        // }
        return dp[n1][n2];
    }
};
*/

/*
class Solution {
public:
    vector<vector<int>> dp;
    int f(int n1,int n2,string text1,string text2){
        if(n1<0||n2<0) return 0;
        if(dp[n1][n2]!=-1) return dp[n1][n2];
        
        if(text1[n1]==text2[n2]) return 1+f(n1-1,n2-1,text1,text2);
        else
        return dp[n1][n2]=max(f(n1,n2-1,text1,text2),f(n1-1,n2,text1,text2));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.size();
        int n2=text2.size();
        dp=vector<vector<int>> (n1,vector<int>(n2,-1));
        
        return f(n1-1,n2-1,text1,text2);
    }
};
*/
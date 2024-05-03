class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int m=t.size();
        int n=t[m-1].size();
        vector<vector<int>> dp(m,vector<int>(n,1e9));
        dp[0][0]=t[0][0];
        for(int i=0;i<m-1;i++){
            for(int j=0;j<t[i].size();j++){
                dp[i+1][j]=min(t[i+1][j]+dp[i][j],dp[i+1][j]);
                dp[i+1][j+1]=min(t[i+1][j+1]+dp[i][j],dp[i+1][j+1]);
            }
        }
        int ans=1e9;
       for(auto it:dp[m-1])
         ans=min(ans,it);
        return ans;
    }
};
/*
class Solution {
public:
    int minimumTotal(vector<vector<int>>& t) {
        int m=t.size();
        int n=t[m-1].size();
        vector<vector<int>> dp(m,vector<int>(n,1e9));
        dp[0][0]=t[0][0];
        for(int i=1;i<m;i++){
            for(int j=0;j<=i;j++){
                int left=1e9;
                if(j-1>=0) left=t[i][j]+dp[i-1][j-1];
                dp[i][j]=min(left,dp[i-1][j]+t[i][j]);
            }
        }
        int ans=1e9;
       for(auto it:dp[m-1])
         ans=min(ans,it);
        return ans;
    }
};
*/
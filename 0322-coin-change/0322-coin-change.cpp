class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
         int n=coins.size();
       vector<int> dp(amount+1,1e9);
       dp[0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=amount;j++){
                
                 if(j-coins[i-1]>=0) dp[j]=min(dp[j],1+dp[j-coins[i-1]]);
            }
        }        
       if(dp[amount]==1e9) return -1;
       return dp[amount];
    }
};
/*
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
       vector<vector<int>> dp(n+1,vector<int>(amount+1,1e9));
       dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=amount;j++){
                 dp[i][j]=dp[i-1][j];
                 if(j-coins[i-1]>=0) dp[i][j]=min(dp[i][j],1+dp[i][j-coins[i-1]]);
            }
        }        
       if(dp[n][amount]==1e9) return -1;
       return dp[n][amount];
    }
};
*/
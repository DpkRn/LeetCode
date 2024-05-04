class Solution {
public:
    int f(int ind,int a,auto &coins,auto &dp){
        if(ind<0){
            if(a==0) return 0; else return 1e9;
        }
        if(dp[ind][a]!=-1) return dp[ind][a];
        int notpick=f(ind-1,a,coins,dp);
        int pick=1e9;
        if(a>=coins[ind])
            pick=1+f(ind,a-coins[ind],coins,dp);
        return dp[ind][a]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        int ans= f(n-1,amount,coins,dp);
        if(ans==1e9) return -1;
        else return ans;
        
    }
};
/*
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

*/

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


class Solution {
      int f(int i,int sell,vector<int>&prices,auto &dp){
        if(i==0){
            if(sell) return 0;
            return -prices[0];
        }       
          if(dp[i][sell]!=-1) return dp[i][sell];
        int profit=0;
        if(!sell){            
             profit=max(-prices[i]+f(i-1,1,prices,dp),f(i-1,0,prices,dp));
        }else{
             profit=max(prices[i]+f(i-1,0,prices,dp),f(i-1,1,prices,dp));
        }
        return dp[i][sell]=profit;
      }
    
public:
  
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(n-1,1,prices,dp);
    }
};
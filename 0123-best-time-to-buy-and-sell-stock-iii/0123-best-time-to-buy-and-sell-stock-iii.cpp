class Solution {
    int f(int i,bool buy,int trjction,auto &prices,auto &dp){
        if(trjction==0) return 0;
        if(i==prices.size()) return 0;
        if(dp[i][buy][trjction]!=-1) return dp[i][buy][trjction];
        int profit=0;
        if(buy){
            profit=max(-prices[i]+f(i+1,!buy,trjction,prices,dp),f(i+1,buy,trjction,prices,dp));
        }else{
            profit=max(prices[i]+f(i+1,!buy,trjction-1,prices,dp),f(i+1,buy,trjction,prices,dp));
        }
        return dp[i][buy][trjction]=profit;
    }
    
public:
    int maxProfit(vector<int>& prices) {
        bool buy=true;
        int n=prices.size();
        int trjction=2;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return f(0,buy,trjction,prices,dp);
    }
};
class Solution {
public:
    int f(int ind,int buy,auto &prices,auto &dp){
        if(ind>=prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy)
            return dp[ind][buy]= max(-prices[ind]+f(ind+1,!buy,prices,dp),f(ind+1,buy,prices,dp));
        return dp[ind][buy]= max(prices[ind]+f(ind+2,!buy,prices,dp),f(ind+1,buy,prices,dp));
        
    }
    int maxProfit(vector<int>& prices) {
        int buy=true;
        int n=prices.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,buy,prices,dp);
    }
};
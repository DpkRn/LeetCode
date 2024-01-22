class Solution {
    int f(int ind,int fee,int buy,auto &prices,auto &dp){
        if(ind>=prices.size()) return 0;
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy) 
            return dp[ind][buy]=max(-prices[ind]+f(ind+1,fee,!buy,prices,dp),f(ind+1,fee,buy,prices,dp));
        return dp[ind][buy]=max(prices[ind]-fee+f(ind+1,fee,!buy,prices,dp),f(ind+1,fee,buy,prices,dp));       
    }
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        //int buy=true;
        // vector<vector<int>> dp(n,vector<int>(2,-1));
       // return f(0,fee,buy,prices,dp);
        vector<vector<int>> dp(n+1,vector<int>(2,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                if(buy)
                    dp[ind][buy]=max(-prices[ind]+dp[ind+1][!buy],dp[ind+1][buy]);
                else
                    dp[ind][buy]=max(prices[ind]-fee+dp[ind+1][!buy],dp[ind+1][buy]);
            }
        }
        return dp[0][1];
    }
};
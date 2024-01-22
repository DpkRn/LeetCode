class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int> (2,0));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<2;buy++){
                if(buy)
                    dp[ind][buy]=max(-prices[ind]+dp[ind+1][!buy],dp[ind+1][buy]);
                else
                    dp[ind][buy]=max(prices[ind]+dp[ind+2][!buy],dp[ind+1][buy]);                    
            }
        }
        return dp[0][1];
    }
};
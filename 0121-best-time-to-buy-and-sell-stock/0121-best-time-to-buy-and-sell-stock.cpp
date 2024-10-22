class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int maxProfit=0;
        int mini=prices[0];
        for(auto it:prices){
            maxProfit=max(maxProfit,it-mini);
            mini=min(mini,it);
        }
        return maxProfit;
    }
};
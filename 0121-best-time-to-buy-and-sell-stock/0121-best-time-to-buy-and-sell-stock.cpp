class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int purchased=INT_MAX;
        int maxi=0;
        for(auto sell:prices){
            if(sell<purchased){
                purchased=sell;
            }else
            {
              maxi=max(sell-purchased,maxi);
            }
        }       
        return maxi;       
    }
};
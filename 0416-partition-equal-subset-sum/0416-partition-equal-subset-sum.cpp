class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalSum=0;
        for(auto &it:nums) totalSum+=it;
        if(totalSum%2==1) return false;
        int k=totalSum/2;
        int n=nums.size();     
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=k;j++){
                dp[i][j]=dp[i-1][j];
                if(j-nums[i-1]>=0) dp[i][j]=dp[i][j]||dp[i-1][j-nums[i-1]];
            }
        }
        return dp[n][k];       
    }
};
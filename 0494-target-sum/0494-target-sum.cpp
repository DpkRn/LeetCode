class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
       int sum=0;
        sum=accumulate(nums.begin(),nums.end(),0);
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int> (sum+1,0));
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                dp[i][j]=dp[i-1][j];
                if(j-nums[i-1]>=0) dp[i][j]=dp[i][j]+dp[i-1][j-nums[i-1]];
            }
        }
        // for(auto &it:dp){
        //     for(auto &it1:it) cout<<it1<<" ";
        //     cout<<endl;
        // }
        int cnt=0;
        for(int i=0;i<=sum;i++){
            if(dp[n][i]){
                if(i-(sum-i)==target) cnt+=dp[n][i];
            }
        }
        return cnt;
    }
};
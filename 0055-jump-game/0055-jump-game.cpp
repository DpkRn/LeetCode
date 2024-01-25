class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        
        vector<int> dp(n,false);
        dp[0]=true;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n&&j<=i+nums[i];j++){
                dp[j]=dp[i]&&true;
            }
        }
        return dp[n-1];
    }
};
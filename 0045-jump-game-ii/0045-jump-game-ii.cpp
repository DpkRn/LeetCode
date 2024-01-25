class Solution {
public:
    int f(int i,auto &nums,auto &dp){
        if(i>=nums.size()-1) return 0;
        if(dp[i]!=-1) return dp[i];
        int mini=1e9;
        
        for(int j=i+1;j<=i+nums[i];j++){
            if(j<nums.size()){
            int steps=1+f(j,nums,dp);
            mini=min(steps,mini);
            }
        }
        return dp[i]=mini;
    }
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,-1);
        return f(0,nums,dp);
    }
};
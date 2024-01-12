class Solution {
public:
    int f(int n,int initial,vector<int>&nums,vector<vector<int>>&dp){
        if(n==initial) return nums[initial];
        if(dp[n][initial]!=-1) return dp[n][initial];
        int nottake=0+f(n-1,initial,nums,dp);
        int take=nums[n];
        if(n-2>=initial) take=nums[n]+f(n-2,initial,nums,dp);
        return dp[n][initial]=max(take,nottake);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];   
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return max(f(n-1,1,nums,dp),f(n-2,0,nums,dp));
        
        
    }
};
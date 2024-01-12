class Solution {
public:
    int f(vector<int>&nums,int n,vector<int>&dp){
        if(n==0) return nums[n];
        if(dp[n]!=-1) return dp[n];
        int left=0+f(nums,n-1,dp);        
        int right=nums[n];
        if(n-2>=0)
            right=nums[n]+f(nums,n-2,dp);
        return dp[n]=max(left,right);
    }
    int rob(vector<int>& nums) {
        
        vector<int> dp(nums.size(),-1);
        return f(nums,nums.size()-1,dp);
        
        
    }
};
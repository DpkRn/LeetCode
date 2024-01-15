class Solution {
public:
    bool f(int n,int k,auto &nums,auto &dp){
        if(k==0) return true;
        if(n==0) return nums[n]==k;
        //pick condition
        if(dp[n][k]!=-1) return dp[n][k];
        bool pick=nums[n]<=k?f(n-1,k-nums[n],nums,dp):false;
        bool notpick=f(n-1,k,nums,dp);
        return dp[n][k]=pick or notpick;
    }
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if((sum&1)==1) return false;
        int n=nums.size();
        int k=sum/2;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));
        return f(n-1,k,nums,dp);        
    }
};
class Solution {
public:
    int f(int ind,int prev,auto &nums,auto &dp){
        if(ind==nums.size()) return 0;
        if(dp[ind][prev+1]!=-1) return dp[ind][prev+1];
        int pick=INT_MIN;
        if(prev==-1||nums[prev]<nums[ind])
            pick=1+f(ind+1,ind,nums,dp);
            pick=max(pick,f(ind+1,prev,nums,dp));        
        return dp[ind][prev+1]=pick;     
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int> (n+1,-1));
        return f(0,-1,nums,dp);
    }
};
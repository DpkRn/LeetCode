class Solution {
public:
    int rob(vector<int>& nums) {
      int n=nums.size();
      vector<int> dp(n,0);
        if(n==1) return nums[0];
        if(n==2) return max(nums[1],nums[0]);
        dp[0]=nums[0];
        
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++){
           int notpick=dp[i-1];
           //int pick=nums[i];
              int  pick=nums[i]+dp[i-2];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
};

/*
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
*/
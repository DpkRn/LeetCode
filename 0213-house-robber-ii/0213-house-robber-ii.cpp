
class Solution {
public:
 
    int solve(vector<int>& nums,int n,vector<int> &dp){
         if(n==0)
            return nums[n];
        if(n<0)
            return 0;
        if(dp[n]!=-1) return dp[n];   
        int pick=nums[n]+solve(nums,n-2,dp);
        int notPick=0+solve(nums,n-1,dp);
        return dp[n]=max(pick,notPick);
    }
    
    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return nums[0];
        vector<int> temp1,temp2;
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
          vector<int> dp(n-1,-1);
        int left=solve(temp1,n-2,dp);
        for(int i=0;i<n-1;i++) dp[i]=-1;
        int right=solve(temp2,n-2,dp);
        return max(left,right);
        
    }
};

/*
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
*/

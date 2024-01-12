class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int p1=nums[0];
        int p2=0;
        for(int i=1;i<n;i++){
            int notpick=p1;
            int pick=nums[i]+p2;
            int curr=max(pick,notpick);
            
            p2=p1;
            p1=curr;
            
        }
        return p1;
    }
};

/*
class Solution {
public:
    int rob(vector<int>& nums) {
      int n=nums.size();
      vector<int> dp(n,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
           int notpick=dp[i-1];
           int pick=nums[i];
            if(i-2>=0)
                pick=nums[i]+dp[i-2];
            dp[i]=max(pick,notpick);
        }
        return dp[n-1];
    }
};
*/

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